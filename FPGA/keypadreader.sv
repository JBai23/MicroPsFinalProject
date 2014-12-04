 module keypadReader(input logic clk,
					      //jbai output logic [6:0] seg,
					      //jbai output logic use_left,
					      //jbai output logic use_right,
					      output logic [3:0] row,
					      input logic [3:0] col,
							output logic [3:0] val //jbai
					      //jbai output logic [7:0] led
);
	//logic [3:0] s_right = 0;//jbai , s_left = 0;
	logic sclk, en = 0;
	slowclock sclock(clk, sclk);
	keypad kp(row, col, sclk, en, keypadval); //jbai
	
	logic [3:0] keypadval;
	logic [3:0] updateval;
	
	updater up(row, col, en, clk, updateval); //jbai
	
	always_comb begin
	  if (keypadval == 4'b0000) val = 4'd0;
	  else val = updateval;
	end
	
	//jbai display_two dt(s_right, s_left, clk, seg, use_left, use_right);
	
endmodule
