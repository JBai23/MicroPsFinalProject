// The total number of bits per pokeSprite must be divisible by 32.
// changing the parameters is not completely safe - there is a part
// that currently must be changed by hand whenever bitsperpixel
// changes.
module spi_slave_and_sprite_data_lookup #(parameter
                  NUMPIXELSPERSPRITE = 15'd4096,
						SPRITEWIDTH = 15'd64,
                  NUMCOLORSINHEADER = 5'd16)
       (input  logic       vgaclk,
        input  logic       sck,
        input  logic       mosi,
		  input  logic [3:0] spriteToDraw,
        input  logic [9:0] spriteX, spriteY,
        output logic [7:0] spriteR, spriteG, spriteB,
		  input  logic [3:0] streamToDraw,
		  input  logic [6:0] charIndex,
		  input  logic [9:0] yoff, xoff,
		  output logic       pixel,
		  output logic [7:0] leds
		  );

  /*******************************/
  /* storage containers */
  /*******************************/
  logic [23:0] pokeSpriteHeaders [7:0][NUMCOLORSINHEADER-1:0]; // 24 bits: {r[7:0], g[7:0], b[7:0]}

  // wires in/out of RAM
  logic [3:0] pixelQ = 4'd0; // readout
  logic [3:0] pixelData = 4'd0; // writein
  logic [14:0] pixelWriteAddr = 15'd0;
  logic [14:0] pixelReadAddr = 15'd0;
  logic writeEnable = 1'b0;

  // arguments: q, addr_in, addr_out, d, we, clk1 [write], clk2 [read]
  ram_dual pokeSpriteData(pixelQ,
                          pixelWriteAddr,
								  pixelReadAddr,
								  pixelData,
								  writeEnable,
								  sck,
								  vgaclk);
	

  logic [11:0][7:0] streams [6:0]; // 4 move names, each move name 12 characters, each character 1 byte
  
  //assign streams[0][11:0] = 96'h41424344_45464748_494A4B4C;
  //assign streams[1][11:0] = 96'h42424242_42424242_42424242;
  //assign streams[2][11:0] = 96'h43434343_43434343_43434343;
  //assign streams[3][11:0] = 96'h44444444_44444444_44444444;
  
  // streams:
  // 0-3: moves
  // 4-5: health text
  // 6+: messages
  
  logic [7:0] ch = 8'd0;
  assign ch = streams[streamToDraw][charIndex]; // character to draw
  
  
  // from lab 7's vga.sv
  logic [5:0] charrom [743:0];
  logic [7:0] line;
  
  initial $readmemb("charrom.txt", charrom);
  
  assign line = {charrom[yoff+{ch, 3'b000}]};
  assign pixel = line[10'd7-xoff];
  
  logic [6:0] percentHealthRemaining1 = 7'd0;
  logic [6:0] percentHealthRemaining2 = 7'd0;

  
  //logic [7:0] poke1HealthText [6:0]; // ex. 123/544, 12/430
  //logic [7:0] poke2HealthText [6:0];


  /*******************************/
  /* sprite data lookup code */
  /*******************************/
  
  assign pixelReadAddr = {5'd0,spriteY} * SPRITEWIDTH + {5'd0,spriteX} + ({11'd0,spriteToDraw} - 15'd1) * NUMPIXELSPERSPRITE;
  assign {spriteR, spriteG, spriteB} = pokeSpriteHeaders[spriteToDraw-4'd1][pixelQ][23:0];


  /*******************************/
  /* SPI slave code */
  /*******************************/
  logic [31:0] q = 32'd0; // stores data received via SPI

  // counters
  logic [4:0] spiCounter = 5'd0;
  logic [1:0] spiSubCounter = 2'd0;
  logic [4:0] headerCounter = 5'd0;
  logic [14:0] dataCounter = 15'd0;
  logic [1:0] textCounter = 2'd0;
  
  // information passed in via CMD
  logic [3:0] spriteSelect = 3'd0;
  logic [2:0] cmdType = 3'd0;
  assign cmdType = q[10:8];

  typedef enum logic[2:0] { GET_CMD    = 3'b111,
                            GET_HEADER = 3'b001,
                            GET_DATA   = 3'b010,
									 GET_TEXT   = 3'b011,
									 GET_HEALTH = 3'b100} stateType;

  stateType currentState = GET_CMD;


  always_ff @(posedge sck) begin
    q <= {q[30:0], mosi}; // shift register
  end


  always_ff @(negedge sck) begin
    leds <= {currentState,2'd0,cmdType};
    // still data left to receive for these 4 bytes
    if (spiCounter < 5'd31) begin
      spiCounter <= spiCounter + 5'd1;
		
		// deal with pixel data (since if writeEnable is on, we must write every 4 bits [1 pixel])
	   if (spiSubCounter < 2'd3) begin
		  spiSubCounter <= spiSubCounter + 2'd1;
      end
	   else begin
		  spiSubCounter <= 2'd0;
		  dataCounter <= dataCounter + 15'd1;
		  pixelWriteAddr <= pixelWriteAddr + 15'd1;
	     pixelData <= q[3:0];
	   end
    end

    // entire 4-byte packet has been transferred
    else begin // spiCounter == 5'b31   
		spiCounter <= 5'b0;
		spiSubCounter <= 2'd0;
		pixelData <= q[3:0];


		/***************/
		/*** GET_CMD ***/
		/***************/
      if (currentState == GET_CMD) begin
		  spriteSelect <= q[3:0];
		  
		  if (cmdType == 3'd2) begin // health bar command
		    percentHealthRemaining2 <= q[22:16];
		    percentHealthRemaining1 <= q[30:24];
			 currentState <= GET_CMD; // only here for emphasis
		  end
		  
		  else if (cmdType == 3'd1) begin
		    currentState <= GET_TEXT;
		  end
		  
		  else begin // cmdType == 3'd0
          currentState <= GET_HEADER;
		  end
      end
		
		
		/****************/
		/*** GET_TEXT ***/
		/****************/
		// all text is 12 characters, which takes 3 32-bit messages total (excluding CMD)
		// sprite select also functions as stream select
		// the characters are in fact loaded in in reverse, as they are read in reverse,
		// and as such these will cancel each other out
		
		else if (currentState == GET_TEXT) begin
		  streams[spriteSelect][{2'd0,textCounter} * 4'd4] <= q[31:24];
		  streams[spriteSelect][{2'd0,textCounter} * 4'd4 + 4'd1] <= q[23:16];
		  streams[spriteSelect][{2'd0,textCounter} * 4'd4 + 4'd2] <= q[15:8];
		  streams[spriteSelect][{2'd0,textCounter} * 4'd4 + 4'd3] <= q[7:0];
		
		  if (textCounter < 2'd2) begin
		    textCounter <= textCounter + 2'd1;
		  end
		  else begin // textCounter == 2'd2
		    textCounter <= 2'd0;
			 currentState <= GET_CMD;
		  end
		end


      /******************/		
		/*** GET_HEADER ***/
		/******************/
      else if (currentState == GET_HEADER) begin

        // set color
		  pokeSpriteHeaders[spriteSelect][headerCounter] <= q[23:0];

		  // check if there are more colors
        if (headerCounter < (NUMCOLORSINHEADER - 5'd1)) begin
          headerCounter <= headerCounter + 5'd1;
			 writeEnable <= 1'd0;
        end
        else begin // headerCounter == NUMCOLORSINHEADER - 1
          currentState <= GET_DATA;
          headerCounter <= 5'd0;
			 writeEnable <= 1'b1;
        end

		  // set pixelWriteAddr
		  pixelWriteAddr <= {11'd0,spriteSelect} * NUMPIXELSPERSPRITE;
		
		  // since this is always increasing, set to 0 in case we go to GET_DATA
		  dataCounter <= 15'd0;
		
		end


      /****************/
		/*** GET_DATA ***/
		/****************/
      else begin // currentState == GET_DATA
        if (dataCounter < NUMPIXELSPERSPRITE - 15'd1) begin
          currentState <= currentState;
			 dataCounter <= dataCounter + 15'd1;
			 pixelWriteAddr <= pixelWriteAddr + 15'd1;
			 writeEnable <= 1'b1;
        end
        else begin // dataCounter == NUMPIXELSPERSPRITE - 1
          currentState <= GET_CMD;
			 dataCounter <= 15'd0;
          pixelWriteAddr <= 15'd0;
			 writeEnable <= 1'b0;
        end
      end
    end
  end
endmodule
