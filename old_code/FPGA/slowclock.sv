 module slowclock(	input logic clk,
							output logic sclk
);
	integer counter = 0;
	
	always_ff@(posedge clk) begin
		counter <= counter + 1;
		if (counter < 800_000) // 1ms
			sclk <= 1'b1;
		else if (counter < 1_600_000) begin // 2ms
			sclk <= 1'b0;
			counter <= 0;
		end
	end
endmodule