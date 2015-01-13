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


module videoGen #(parameter BACKGROUNDCOLOR = 24'h77_21_6F)
               (input  logic       vgaclk,
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
  logic inSubHealthBar1, inSubHealthBar2;
  logic inMainSprite1, inMainSprite2;
  logic [5:0] inSubSprite;
  
  logic inFightBox, inSwitchBox, inRunBox, p1Turn, p2Turn;
  
  logic inFightState = 1'b0, inSwitchState = 1'b0, inRunState = 1'b0;
  
  //assign inFightState = 1'b1;
  //assign inSwitchState = 1'b0;
  //assign inRunState = 1'b0;

  logic [3:0] inMove;

  logic [3:0] spriteToDraw = 4'd0;

  logic [5:0] streamToDraw = 6'd0;
  logic [6:0] cival = 7'd0;
  assign cival = x[9:3];
  logic [6:0] charIndex = 7'd0;
  logic [9:0] yoff = 3'd0, xoff = 3'd0;
  logic pixel = 1'b0;
  logic animationCmd = 1'b0;
  
  logic [31:0] vgaCounter = 32'd0;
  
  logic animationWasReset = 1'b0;
  
   typedef enum logic[2:0] { NOANIMATION    = 3'b000,
                            ANIMATION = 3'b001
									 } animationStateType;
  animationStateType animationState = NOANIMATION;
  
  always_ff @(posedge vgaclk) begin
    if (animationCmd == 1'b0) begin
	   animationWasReset <= 1'b1;
	 end
	 
    if (animationState == NOANIMATION) begin
	   if (animationCmd == 1'b1 && animationWasReset) begin
	     animationState <= ANIMATION;
		  animationWasReset <= 1'b0;
		  vgaCounter <= 32'd0;
		end
	 end
	 
	 else begin
	   if (vgaCounter > 32'd15000000) begin
		  animationState <= NOANIMATION;
		end
		else begin
		  vgaCounter <= vgaCounter + 32'd1;
		end
	 end
  end
  
  logic inFullScreenMessage1 = 1'b0, inFullScreenMessage2 = 1'b0, inFullScreenMessage3 = 1'b0; //inFullScreenMessage4 = 1'b0;

  logic [6:0] percentHealthRemaining1 = 7'd0, percentHealthRemaining2 = 7'd0;
  logic [9:0] modPercentHealthRemaining1 = 10'd0;
  logic [9:0] modPercentHealthRemaining2 = 10'd0;

  assign modPercentHealthRemaining1 = 10'd40 + {3'd0,percentHealthRemaining1};
  assign modPercentHealthRemaining2 = 10'd496 + {3'd0,percentHealthRemaining2};
  
  logic inMainSprite1AnimationBox, inMainSprite2AnimationBox;
  
  logic inTrainerText1, inTrainerText2;

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
         percentHealthRemaining1,
         percentHealthRemaining2,
			inFightState,
			inSwitchState,
			inRunState,
			p1Turn,
			p2Turn,
			animationCmd,
			leds
			);

  rectGen healthBar1(x, y, 10'd40, 10'd140, 10'd38, 10'd51, inHealthBar1);
  rectGen healthBar2(x, y, 10'd496, 10'd596, 10'd38, 10'd51, inHealthBar2);
  rectGen subHealthBar1(x, y, modPercentHealthRemaining1, 10'd140, 10'd38, 10'd51, inSubHealthBar1);
  rectGen subHealthBar2(x, y, modPercentHealthRemaining2, 10'd596, 10'd38, 10'd51, inSubHealthBar2);

  rectGen mainSprite1(x, y, 10'd128, 10'd192, 10'd136, 10'd200, inMainSprite1);
  rectGen mainSprite2(x, y, 10'd448, 10'd512, 10'd136, 10'd200, inMainSprite2);
  
  rectGen mainSprite1AnimationBox(x, y, 10'd144, 10'd208, 10'd136, 10'd200, inMainSprite1AnimationBox);
  rectGen mainSprite2AnimationBox(x, y, 10'd432, 10'd496, 10'd136, 10'd200, inMainSprite2AnimationBox);

  rectGen subSprite0(x, y, 10'd000, 10'd064, 10'd400, 10'd464, inSubSprite[0]);
  rectGen subSprite1(x, y, 10'd104, 10'd168, 10'd400, 10'd464, inSubSprite[1]);
  rectGen subSprite2(x, y, 10'd208, 10'd272, 10'd400, 10'd464, inSubSprite[2]);
  rectGen subSprite3(x, y, 10'd312, 10'd376, 10'd400, 10'd464, inSubSprite[3]);
  rectGen subSprite4(x, y, 10'd416, 10'd480, 10'd400, 10'd464, inSubSprite[4]);
  rectGen subSprite5(x, y, 10'd520, 10'd584, 10'd400, 10'd464, inSubSprite[5]);

  rectGen move0(x, y, 10'd0, 10'd96, 10'd400, 10'd408, inMove[0]);
  rectGen move1(x, y, 10'd104, 10'd200, 10'd400, 10'd408, inMove[1]);
  rectGen move2(x, y, 10'd208, 10'd304, 10'd400, 10'd408, inMove[2]);
  rectGen move3(x, y, 10'd312, 10'd408, 10'd400, 10'd408, inMove[3]);
  
  rectGen fightBox(x, y, 10'd152, 10'd248, 10'd280, 10'd288, inFightBox);
  rectGen switchBox(x, y, 10'd272, 10'd368, 10'd280, 10'd288, inSwitchBox);
  rectGen runBox(x, y, 10'd392, 10'd488, 10'd280, 10'd288, inRunBox);
  
  logic inHealthText1, inHealthText2;
  
  rectGen healthText1(x, y, 10'd40, 10'd136, 10'd56, 10'd64, inHealthText1);
  rectGen healthText2(x, y, 10'd496, 10'd592, 10'd56, 10'd64, inHealthText2);
  
  
  rectGen trainerText1(x, y, 10'd40, 10'd136, 10'd320, 10'd328, inTrainerText1);
  rectGen trainerText2(x, y, 10'd496, 10'd592, 10'd320, 10'd328, inTrainerText2);
  
  logic inPokeName1, inPokeName2;
  
  rectGen pokeName1(x, y, 10'd40, 10'd136, 10'd24, 10'd32, inPokeName1);
  rectGen pokeName2(x, y, 10'd496, 10'd592, 10'd24, 10'd32, inPokeName2);
  
  //logic [7:0] inStatus = 8'd0;
  
  //rectGen status0(x, y, 10'd40, 10'd136, 10'd150, 10'd158, inStatus[0]);
  //rectGen status1(x, y, 10'd496, 10'd592, 10'd150, 10'd158, inStatus[1]);
  
  rectGen fullScreenMessage1(x, y, 10'd0, 10'd640, 10'd360, 10'd368, inFullScreenMessage1);
  rectGen fullScreenMessage2(x, y, 10'd0, 10'd640, 10'd368, 10'd376, inFullScreenMessage2);
  rectGen fullScreenMessage3(x, y, 10'd0, 10'd640, 10'd376, 10'd384, inFullScreenMessage3);
  //rectGen fullScreenMessage4(x, y, 10'd0, 10'd640, 10'd384, 10'd392, inFullScreenMessage4);
  
  logic inZone1 = 1'b0, inZone2 = 1'b0;
  
  assign inZone1 = inMainSprite1 | inMainSprite2 | inMainSprite1AnimationBox | inMainSprite2AnimationBox;
  assign inZone2 = (|inMove) | (|inSubSprite);

  always_comb begin
  if (inZone1) begin
    if (inMainSprite1 && animationState == NOANIMATION) begin
	     spriteToDraw = 4'd1;
		  spriteX = x - 10'd128;
		  spriteY = y - 10'd136;
		  streamToDraw = 4'd0;
		  xoff = 3'd0;
		  yoff = 3'd0;
		  charIndex = 4'd0;
	     {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inMainSprite2 && animationState == NOANIMATION) begin
	     spriteToDraw = 4'd2;
		  spriteX = x - 10'd448;
		  spriteY = y - 10'd136;
		  streamToDraw = 4'd0;
		  xoff = 3'd0;
		  yoff = 3'd0;
		  charIndex = 4'd0;
	     {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inMainSprite1AnimationBox && animationState == ANIMATION) begin
	     spriteToDraw = 4'd1;
		  spriteX = x - 10'd144;
		  spriteY = y - 10'd136;
		  streamToDraw = 4'd0;
		  xoff = 3'd0;
		  yoff = 3'd0;
		  charIndex = 4'd0;
	     {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inMainSprite2AnimationBox && animationState == ANIMATION) begin
	     spriteToDraw = 4'd2;
		  spriteX = x - 10'd432;
		  spriteY = y - 10'd136;
		  streamToDraw = 4'd0;
		  xoff = 3'd0;
		  yoff = 3'd0;
		  charIndex = 4'd0;
	     {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
		{r_int, g_int, b_int} = BACKGROUNDCOLOR;
	 end
end



else if (inZone2) begin
  if (inSwitchState) begin
	 if (inSubSprite[0]) begin
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
		spriteX = x - 10'd104;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[2]) begin
	   spriteToDraw = 4'd5;
		spriteX = x - 10'd208;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[3]) begin
	   spriteToDraw = 4'd6;
		spriteX = x - 10'd312;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[4]) begin
	   spriteToDraw = 4'd7;
		spriteX = x - 10'd416;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else if (inSubSprite[5]) begin
	   spriteToDraw = 4'd8;
		spriteX = x - 10'd520;
		spriteY = y - 10'd400;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
	   {r_int, g_int, b_int} = {spriteR, spriteG, spriteB};
	 end
	 else begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
		{r_int, g_int, b_int} = BACKGROUNDCOLOR;
	 end
  end
  else if (inFightState) begin
    if (inMove[0]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
	   streamToDraw = 4'd0;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd400;
		charIndex = cival; //-0
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inMove[1]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
	   streamToDraw = 4'd1;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd400;
		charIndex = cival - 7'd13; //-17
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inMove[2]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd2;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd400;
		charIndex = cival - 7'd26; //-34
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inMove[3]) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd3;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd400;
		charIndex = cival - 7'd39; //-51
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
		{r_int, g_int, b_int} = BACKGROUNDCOLOR;
	 end
  end
  else begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 3'd0;
		yoff = 3'd0;
		charIndex = 4'd0;
		{r_int, g_int, b_int} = BACKGROUNDCOLOR;
  end
end

else begin
    if (inHealthBar1) begin
	    spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 10'd0;
		yoff = 10'd0;
		charIndex = 4'd0;
        if (!inSubHealthBar1) begin
          if (percentHealthRemaining1 < 7'd20)
	        {r_int, g_int, b_int} = {8'd255, 8'd0, 8'd0};
          else if (percentHealthRemaining1 < 7'd50)
            {r_int, g_int, b_int} = {8'd255, 8'd255, 8'd0};
          else
            {r_int, g_int, b_int} = {8'd0, 8'd255, 8'd0};
        end
        else
          {r_int, g_int, b_int} = {24'h30_30_30};
	 end
	 else if (inHealthBar2) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd0;
		xoff = 10'd0;
		yoff = 10'd0;
		charIndex = 4'd0;
        if (!inSubHealthBar2) begin
          if (percentHealthRemaining2 < 7'd20)
            {r_int, g_int, b_int} = {8'd255, 8'd0, 8'd0};
          else if (percentHealthRemaining2 < 7'd50)
            {r_int, g_int, b_int} = {8'd255, 8'd255, 8'd0};
          else
            {r_int, g_int, b_int} = {8'd0, 8'd255, 8'd0};
        end
        else
          {r_int, g_int, b_int} = {24'h30_30_30};
	 end
	 else if (inFightBox) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd4;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd280;
		charIndex = cival - 7'd19 ; //-51
		if (inFightState & ~pixel)
		  {r_int, g_int, b_int} = 24'hFF_00_00;
		else
		  {r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inSwitchBox) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd5;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd280;
		charIndex = cival - 7'd34; //-51
		if (inSwitchState & ~pixel)
		  {r_int, g_int, b_int} = 24'hFF_00_00;
		else
		  {r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inRunBox) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd6;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd280;
		charIndex = cival - 7'd49; //-51
		if (inRunState & ~pixel)
		  {r_int, g_int, b_int} = 24'hFF_00_00;
		else
		  {r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inFullScreenMessage1) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 6'd30;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd360;
		charIndex = cival; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inFullScreenMessage2) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 6'd31;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd368;
		charIndex = cival; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inFullScreenMessage3) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 6'd32;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd376;
		charIndex = cival; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
/*
	 else if (inFullScreenMessage4) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 6'd33;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd384;
		charIndex = cival; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
*/
	 else if (inHealthText1) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd7;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd56;
		charIndex = cival - 7'd5; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inHealthText2) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd8;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd56;
		charIndex = cival - 7'd62; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inTrainerText1) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd9;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd320;
		charIndex = cival - 7'd5; //-51
		if (p1Turn & ~pixel)
		  {r_int, g_int, b_int} = 24'hFF_00_00;
		else
		  {r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inTrainerText2) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd10;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd320;
		charIndex = cival - 7'd62; //-51
		if (p2Turn & ~pixel)
		  {r_int, g_int, b_int} = 24'hFF_00_00;
		else
		  {r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inPokeName1) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd11;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd24;
		charIndex = cival - 7'd5; //-51
		{r_int, g_int, b_int} = {24{pixel}};
	 end
	 else if (inPokeName2) begin
	   spriteToDraw = 4'd0;
		spriteX = 10'd0;
		spriteY = 10'd0;
		streamToDraw = 4'd12;
	   xoff = {7'd0,x[2:0]};
		yoff = y - 10'd24;
		charIndex = cival - 7'd62; //-51
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
		{r_int, g_int, b_int} = BACKGROUNDCOLOR;
	 end
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


