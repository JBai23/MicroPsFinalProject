module keypad(		output logic [3:0] row = 4'b1111,
						input logic [3:0] col,
						input logic clk,
						output logic en = 0
						//jbai output logic [7:0] led
);
	typedef enum logic [1:0] 	{
											search = 2'b00,
											bounce = 2'b01,
											update = 2'b10,
											btnrel = 2'b11
										} states;
	
	typedef enum logic [3:0] {
									x0 = 4'b0001,
									x1 = 4'b0010,
									x2 = 4'b0100,
									x3 = 4'b1000
								} one_bit;
	
	const logic [3:0] zero = 4'b0000;
	
	//logic [3:0] curr_col = 4'b0000;
	
	//jbai integer counter = 0;
	
	states state = search, next_state = search;
	one_bit next_row = x0;
	
	always_ff@(posedge clk) begin
		state <= next_state;
		//jbai led[3:0] <= row;
		//jbai led[7:4] <= col;
		case(state)
			search: row <= next_row; // too quick?
			//jbai bounce: counter <= counter + 1;
		endcase
	end
	
	always_comb begin
		// next_row, next_state, en
	
		// search state
		case(state)
			search: begin
				case(row)
					x0: next_row = x1;
					x1: next_row = x2;
					x2: next_row = x3;
					x3: next_row = x0;
					default: next_row = x0;
				endcase
				if (col == zero) begin
					next_state = search; //jbai bounce;
				end else begin
					next_state = bounce;
				end
				en = 0;
			end
			
			// bounce state
			bounce: begin
				next_row = x0;
				//jbai if (counter >= 20) // reset counter
					//jbai if (col == zero)
						//jbai next_state = search;
					//jbai else
						next_state = update;
				//jbai else
					//jbai next_state = bounce;
				en = 0;
			end
			
			// update state
			update: begin
				next_row = x0;
				next_state = btnrel; // is this correct?
				en = 1;
			end
			
			// btnrel state
			btnrel: begin
				en = 0;
				next_row = x0;
				if (col == zero)
					next_state = search;
				else
					next_state = btnrel;
			end
			
			// error state
			default: begin
				next_row <= x0;
				next_state <= search;
				en = 0;
			end
		endcase
	end
endmodule