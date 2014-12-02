// slightly modified from the internet (I don't why some of the things are here)
// the write clock, clk1, is now negedge to match my spi slave code, because I'm
// lazy and didn't want to pass in inverted sck
module ram_dual(q, addr_in, addr_out, d, we, clk1, clk2);
   output[3:0] q;
   input [3:0] d;
   input [11:0] addr_in;
   input [11:0] addr_out;
   input we, clk1, clk2;
 
   reg [11:0] addr_out_reg;
   reg [3:0] q;
   reg [3:0] mem [4095:0];
 
   always @(negedge clk1) begin
      if (we)
         mem[addr_in] <= d;
   end
 
   always @(posedge clk2) begin
      q <= mem[addr_out_reg];
      addr_out_reg <= addr_out;
   end
        
endmodule
