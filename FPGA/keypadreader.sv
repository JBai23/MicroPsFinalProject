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
	keypad kp(row, col, sclk, en); //jbai
	
	updater up(row, col, en, clk, val); //jbai
	
	//jbai display_two dt(s_right, s_left, clk, seg, use_left, use_right);
	
endmodule
