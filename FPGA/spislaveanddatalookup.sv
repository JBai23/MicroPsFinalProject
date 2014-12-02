// The total number of bits per pokeSprite must be divisible by 32.
// changing the parameters is not completely safe - there is a part
// that currently must be changed by hand whenever bitsperpixel
// changes.
module spi_slave_and_sprite_data_lookup #(parameter
                  NUMPIXELS = 13'd1024,
                  SPRITEWIDTH = 10'd32,
                  BITSPERPIXEL = 10'd4,
                  NUMCOLORSINHEADER = 5'd4)
       (input  logic       vgaclk,
        input  logic       sck,
        input  logic       mosi,
        input  logic [9:0] x, y,
        output logic [7:0] r_int, g_int, b_int);

  /*******************************/
  /* storage containers */
  /*******************************/
  logic [23:0] pokeSprite1Header [NUMCOLORSINHEADER-1:0]; // 24 bits: {r[7:0], g[7:0], b[7:0]}
  logic [23:0] pokeSprite2Header [NUMCOLORSINHEADER-1:0]; // 24 bits: {r[7:0], g[7:0], b[7:0]}

  logic [11:0] pixelWriteIndex = 12'd0, pixelReadIndex = 12'd0;
  logic we1 = 0; // write-enable
  
  logic [BITSPERPIXEL-1:0] pixelQ1 = 4'd0; // readout
  logic [BITSPERPIXEL-1:0] pixelData = 4'd0; // writein

  // q, addr_in, addr_out, d, we, clk1 [write], clk2 [read]
  // 4096 words, 4-bit words
  ram_dual pokeSprite1Data(pixelQ1,
                           pixelWriteIndex,
									pixelReadIndex,
									pixelData,
									we1,
									sck,
									vgaclk);

/*
  ram_dual pokeSprite1Data(pixelQ2,
                           pixelWriteIndex,
									pixelReadIndex,
									pixelData,
									we2,
									sck,
									vgaclk);
 */
 
 
  /*******************************/
  /* sprite data lookup code */
  /*******************************/
  
  assign pixelReadIndex = y * SPRITEWIDTH + x; // ??? do the factors need to be 12-bit too?
  assign {r_int, g_int, b_int} = pokeSprite1Header[pixelQ1][23:0];


  /*******************************/
  /* SPI slave code */
  /*******************************/
  logic [31:0] q = 32'd0; // stores data received via SPI

  logic [4:0] spiCounter = 5'd0;
  logic [1:0] spiSubCounter = 2'd0;
  logic [4:0] headerCounter = 5'd0;

  typedef enum logic[1:0] { GET_CMD    = 2'b00,
                            GET_HEADER = 2'b01,
                            GET_DATA   = 2'b10} stateType;

  stateType currentState = GET_CMD;

  always_ff @(posedge sck) begin
    q <= {q[30:0], mosi}; // shift register
  end

  always_ff @(negedge sck) begin
    // still data left to receive for these 4 bytes
    if (spiCounter < 5'd31) begin
      currentState <= currentState;
      spiCounter <= spiCounter + 5'd1;
		
	   if (spiSubCounter < 2'd3) begin
		  spiSubCounter <= spiSubCounter + 2'd1;
		  pixelWriteIndex <= pixelWriteIndex;
		  pixelData <= pixelData;
      end

	   else begin
		  spiSubCounter <= 2'd0;
		  pixelWriteIndex <= pixelWriteIndex + 12'd1;
	     pixelData <= q[3:0];
	   end

      // leftover
      headerCounter <= 5'd0;
    end

    // entire 4-byte packet has been transferred
    else begin // spiCounter == 5'b31
      if (currentState == GET_CMD) begin
        currentState <= GET_HEADER;
        spiCounter <= 5'b0;
        // TODO: set where we're putting our data (just doing pokeSprite1 for now)
        // TODO: modify other parts of code to reflect this choice

        // leftover
        headerCounter <= 5'd0;
		  spiSubCounter <= 2'd0;
        pixelWriteIndex <= 12'd0;
	     pixelData <= q[3:0];
		  we1 <= 1'd0;
      end

      else if (currentState == GET_HEADER) begin
        pokeSprite1Header[headerCounter] <= q[23:0]; // r, g, b

        if (headerCounter < (NUMCOLORSINHEADER - 1)) begin
          currentState <= currentState;
          headerCounter <= headerCounter + 5'd1;
			 we1 <= 1'd0;
        end

        else begin // headerCounter == NUMCOLORSINHEADER - 1
          currentState <= GET_DATA;
          headerCounter <= 5'd0;
			 we1 <= 1'd1;
        end

        // leftover
        spiCounter <= 5'd0;
		  spiSubCounter <= 2'd0;
        pixelWriteIndex <= 12'd0;
		  pixelData <= q[3:0];
      end

      else begin // currentState == GET_DATA
		  spiSubCounter <= 2'd0;
        pixelData <= q[3:0];

        if (pixelWriteIndex < NUMPIXELS - 1) begin
          currentState <= currentState;
			 pixelWriteIndex <= pixelWriteIndex + 12'd1;
			 we1 <= 1'd1;
        end

        else begin // pixelWriteIndex == NUMPIXELS - 1
          currentState <= GET_CMD;
          pixelWriteIndex <= 12'd0;
			 we1 <= 1'd0;
        end

        // leftover
        spiCounter <= 5'b0;
        headerCounter <= 5'b0;
      end
    end
  end
endmodule
