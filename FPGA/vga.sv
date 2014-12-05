/* Things that'll probably be on the screen:
* - background
* - 2 pokemon sprites
* - 2 health bars
* - 2 health bar number indicators
* - menu (font sprites, perhaps a rectangular border)
* - cursor (for menu) - not strictly necessary if have enough buttons
* - switch pokemon screen:
* -- 6 sprites (preferably smaller) or 6 names
* -- sprites do not change unless knocked out or status, etc. - can draw
*      stupid rectangle as indicator
*/
module vga(input  logic       clk,
           input  logic       sck, //jbai
           input  logic       mosi, //jbai
           output logic       vgaclk, // 25 MHz VGA clock
           output logic       hsync, vsync, sync_b, blank_b, //jbai to monitor & DAC
           output logic [7:0] r, g, b, // to video dac
			  output logic [7:0] leds
			  );

  logic [9:0] x, y;
  logic [7:0] r_int, g_int, b_int;

  pll   pll_inst (
    .areset ( areset_sig ),
    .inclk0 ( inclk0_sig ),
    .c0 ( c0_sig ),
    .locked ( locked_sig )
  );

  //jbai and MegaWizard
  // Use a PLL to create the 25.175 MHz VGA pixel clock
  // 25.175 Mhz clk period = 39.772 ns
  // Screen is 800 clocks wide by 525 tall, but only 640 x 480 used for display
  // HSync = 1/(39.772 ns * 800) = 31.470 KHz
  // Vsync = 31.474 KHz / 525 = 59.94 Hz (~60 Hz refresh rate)
  pll   vgapll(.inclk0(clk),    .c0(vgaclk));

  //logic [6:0] cival = 7'd0;
  
  // generate monitor timing signals
  vgaController vgaCont(vgaclk, hsync, vsync, sync_b, blank_b, //jbai
                        r_int, g_int, b_int, r, g, b, x, y);

  // user-defined module to determine pixel color
  videoGen vidGen(vgaclk, sck, mosi, x, y, r_int, g_int, b_int, leds);
endmodule


module videoGen(input  logic       vgaclk,
                input  logic       sck,
                input  logic       mosi,
                input  logic [9:0] x, y,
                output logic [7:0] r_int, g_int, b_int,
					 //input  logic [6:0] cival
					 output logic [7:0] leds
					 );

  logic [9:0] spriteX, spriteY;
  logic [7:0] spriteR, spriteG, spriteB;

  logic inHealthBar1, inHealthBar2;
  logic inMainSprite1, inMainSprite2;
  logic [5:0] inSubSprite;
  
  logic [3:0] inMove;
  
  logic [3:0] spriteToDraw = 4'd0;

  logic [3:0] streamToDraw = 4'd0;
  logic [6:0] cival = 7'd0;
  assign cival = x[9:3];
  logic [6:0] charIndex = 7'd0;
  logic [9:0] yoff = 3'd0, xoff = 3'd0;
  logic pixel = 1'b0;

  spi_slave_and_sprite_data_lookup ssasdl
        (vgaclk,
         sck,
			mosi,
			spriteToDraw,
			spriteX,
			spriteY,
			spriteR,
			spriteG,
			spriteB,
			streamToDraw,
			charIndex,
			yoff,
			xoff,
			pixel,
			leds
			);

  rectGen healthBar1(x, y, 10'd0, 10'd100, 10'd0, 10'd20, inHealthBar1);
  rectGen healthBar2(x, y, 10'd540, 10'd640, 10'd0, 10'd20, inHealthBar2);
  rectGen mainSprite1(x, y, 10'd0, 10'd64, 10'd100, 10'd164, inMainSprite1);
  rectGen mainSprite2(x, y, 10'd576, 10'd640, 10'd100, 10'd164, inMainSprite2);
  
  rectGen subSprite0(x, y, 10'd000, 10'd064, 10'd400, 10'd464, inSubSprite[0]);
  rectGen subSprite1(x, y, 10'd100, 10'd164, 10'd400, 10'd464, inSubSprite[1]);
  rectGen subSprite2(x, y, 10'd200, 10'd264, 10'd400, 10'd464, inSubSprite[2]);
  rectGen subSprite3(x, y, 10'd300, 10'd364, 10'd400, 10'd464, inSubSprite[3]);
  rectGen subSprite4(x, y, 10'd400, 10'd464, 10'd400, 10'd464, inSubSprite[4]);
  rectGen subSprite5(x, y, 10'd500, 10'd564, 10'd400, 10'd464, inSubSprite[5]);
  
  rectGen move0(x, y, 10'd0, 10'd96, 10'd300, 10'd308, inMove[0]);
  rectGen move1(x, y, 10'd200, 10'd296, 10'd300, 10'd308, inMove[1]);
  rectGen move2(x, y, 10'd0, 10'd96, 10'd200, 10'd208, inMove[2]);
  rectGen move3(x, y, 10'd400, 10'd496, 10'd300, 10'd308, inMove[3]);
  
  always_comb begin
    if (inHealthBar1) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 10'd0;
		yoff = 10'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {8'd0, 8'd255, 8'd0};
	 end
	 else if (inHealthBar2) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 10'd0;
		yoff = 10'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {8'd0, 8'd255, 8'd0};
	 end
	 else if (inMainSprite1) begin
	   spriteToDraw = 4'd1;
		spriteX = x;
		spriteY = y - 10'd100;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inMainSprite2) begin
	   spriteToDraw = 4'd2;
		spriteX = x - 10'd576;
		spriteY = y - 10'd100;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[0]) begin
	   spriteToDraw = 4'd3;
		spriteX = x;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[1]) begin
	   spriteToDraw = 4'd4;
		spriteX = x - 10'd100;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[2]) begin
	   spriteToDraw = 4'd5;
		spriteX = x - 10'd200;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[3]) begin
	   spriteToDraw = 4'd6;
		spriteX = x - 10'd300;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[4]) begin
	   spriteToDraw = 4'd7;
		spriteX = x - 10'd400;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[5]) begin
	   spriteToDraw = 4'd8;
		spriteX = x - 10'd500;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
    else if (inMove[0]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
	   streamToDraw = 4'd0;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd300;
		charIndex = cival; //-0
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inMove[1]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
	   streamToDraw = 4'd1;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd300;
		charIndex = cival - 7'd25; //-17
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inMove[2]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd2;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd200;
		charIndex = cival; //-34
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inMove[3]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd3;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd300;
		charIndex = cival - 7'd50; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
		{r_int, g_int, b_int} = {8'h66, 8'h66, 8'h66};
	 end
  end
endmodule


// provided (I switched order of inputs)
module rectGen #(parameter
                MAX_DIMENSION_BITS = 10)
    (input logic [MAX_DIMENSION_BITS-1:0] x, y, left, right, top, bot,
     output logic inRect);

assign inRect = (x >= left & x < right & y >= top & y < bot);
endmodule


// (mostly) from the Lab 7 code
module vgaController #(parameter HMAX   = 10'd800,
                               VMAX   = 10'd525,
                               HSTART = 10'd152,
                               WIDTH  = 10'd640,
                               VSTART = 10'd37,
                               HEIGHT = 10'd480)
                      (input  logic       vgaclk,
                       output logic       hsync, vsync, sync_b, blank_b, //jbai
                       input  logic [7:0] r_int, g_int, b_int,
                       output logic [7:0] r, g, b,
                       output logic [9:0] x, y
							  //output logic [6:0] cival //jbai
							  );

  logic [9:0] hcnt, vcnt;
  logic       oldhsync;
  logic       valid;
  
  //jbai
  //logic [2:0] cicounter = 3'd0;
  //logic [6:0] ci = 7'd0;
/*
  always_ff @(posedge vgaclk) begin
    if (hcnt >= HMAX) ci <= 7'd0;
    else if (cicounter < 3'd5) begin
	   cicounter <= cicounter + 3'd1;
	 end
	 else begin
	   cicounter <= 3'd0;
		ci <= ci + 7'd1;
	 end
  end
*/
  
  // counters for horizontal and vertical positions
  always @(posedge vgaclk) begin
    //jbai

  
    if (hcnt >= HMAX) begin hcnt = 0; end//ci <= 7'd0; end //jbai
    else hcnt++;

    if (hsync & ~oldhsync) begin // start of hsync; advance to next row
      if (vcnt >= VMAX) vcnt = 0;
      else vcnt++;
    end
    oldhsync = hsync;
  end
  
  //jbai
  //assign cival = ci;

  // compute sync signals (active low)
  assign hsync = ~(hcnt >= 10'd8 & hcnt < 10'd104); // horizontal sync
  assign vsync = ~(vcnt >= 2 & vcnt < 4); // vertical sync
  assign sync_b = hsync | vsync;

  // determine x and y positions
  assign x = hcnt - HSTART;
  assign y = vcnt - VSTART;

  // force outputs to black when outside the legal display area
  assign valid = (hcnt >= HSTART & hcnt < HSTART+WIDTH &
                  vcnt >= VSTART & vcnt < VSTART+HEIGHT);
  assign blank_b = valid; //jbai
  assign {r,g,b} = valid ? {r_int,g_int,b_int} : 24'b0;
endmodule


