module updater(	input logic [3:0] row,
						input logic [3:0] col,
						input logic en,
						input logic clk,
						output logic [3:0] s_right
						//output logic [3:0] s_left //jbai
);
	logic upd;
	logic [3:0] s_temp;
	
	always_ff @(posedge clk) begin
		if (en) begin
			if (upd) begin
				case({row, col})
					// row 0
					8'b_0001_0001: s_temp = 4'b0001; // r0 c0 - 1
					8'b_0001_0010: s_temp = 4'b0010; // r0 c1 - 2
					8'b_0001_0100: s_temp = 4'b0011; // r0 c2 - 3
					8'b_0001_1000: s_temp = 4'b1010; // r0 c3 - A				
					// row 1
					8'b_0010_0001: s_temp = 4'b0100; // r1 c0 - 4
					8'b_0010_0010: s_temp = 4'b0101; // r1 c1 - 5
					8'b_0010_0100: s_temp = 4'b0110; // r1 c2 - 6
					8'b_0010_1000: s_temp = 4'b1011; // r1 c3 - B
					// row 2
					8'b_0100_0001: s_temp = 4'b0111; // r2 c0 - 7
					8'b_0100_0010: s_temp = 4'b1000; // r2 c1 - 8
					8'b_0100_0100: s_temp = 4'b1001; // r2 c2 - 9
					8'b_0100_1000: s_temp = 4'b1100; // r2 c3 - C			
					// row 3
					8'b_1000_0001: s_temp = 4'b1110; // r3 c0 - E
					8'b_1000_0010: s_temp = 4'b0000; // r3 c1 - 0
					8'b_1000_0100: s_temp = 4'b1111; // r3 c2 - F
					8'b_1000_1000: s_temp = 4'b1101; // r3 c3 - D
					// invalid
					default: s_temp = 4'b0000;
				endcase
				//s_left = s_right; //jbai
				s_right = s_temp;
				upd = 0;
			end
		end else begin
			upd = 1;
		end
	end
endmodule