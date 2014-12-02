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
           output logic [7:0] r, g, b); // to video DAC

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

  // generate monitor timing signals
  vgaController vgaCont(vgaclk, hsync, vsync, sync_b, blank_b, //jbai
                        r_int, g_int, b_int, r, g, b, x, y);

  // user-defined module to determine pixel color
  videoGen vidGen(clk, sck, mosi, x, y, r_int, g_int, b_int);
endmodule


module videoGen(input  logic       vgaclk,
                input  logic       sck,
                input  logic       mosi,
                input  logic [9:0] x, y,
                output logic [7:0] r_int, g_int, b_int);

  //assign {r_int, g_int, b_int} = {8'd255, 8'd0, 8'd0};

  logic [9:0] spriteX, spriteY;
  logic [7:0] spriteR, spriteG, spriteB;

  logic inSprite1;

  spi_slave_and_sprite_data_lookup ssasdl(vgaclk, sck, mosi, spriteX, spriteY, spriteR, spriteG, spriteB);

  rectGen inS1(x, y, 10'd50, 10'd150, 10'd50, 10'd150, inSprite1);

  always_comb begin
    if (inSprite1) begin
      spriteX = x - 10'd50;
      spriteY = y - 10'd50;
      {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
    end
	 else begin
	   spriteX = 10'd0;
		spriteY = 10'd0;
		{r_int, g_int, b_int} = 24'd0;
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
                       output logic [9:0] x, y);

  logic [9:0] hcnt, vcnt;
  logic       oldhsync;
  logic       valid;

  // counters for horizontal and vertical positions
  always @(posedge vgaclk) begin
    if (hcnt >= HMAX) hcnt = 0;
    else hcnt++;

    if (hsync & ~oldhsync) begin // start of hsync; advance to next row
      if (vcnt >= VMAX) vcnt = 0;
      else vcnt++;
    end
    oldhsync = hsync;
  end

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


