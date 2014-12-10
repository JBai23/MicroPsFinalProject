/*
 * 32768 pixels
 * 8 sprites, each 64x64: 4096 * 8 = 32768
 */

 /* RAM map
  *
  * 0-32767: 8 64x64 pokemon sprites
  *   0: main pokemon sprite 1
  *   1: main pokemon sprite 2
  *   2-7: the "switch pokemon" sprites at the bottom
  *
  *
  * 60000-?????: pokemon sprite headers
  *
  */

/* how headers work
 *
 * since a header is 32 bits, and we use 4-bit words, it will be split across
 * 8 words.
 *
 * old: logic [23:0] pokeSpriteHeaders [7:0][NUMCOLORSINHEADER-1:0]; // 24 bits: {r[7:0], g[7:0], b[7:0]}
 *
 *       pokeSpriteHeaders[spriteSelect][headerCounter] <= q[23:0];
 *
 * new:
 *
 *   - each color is 32 bits (first 8 bits ignored)
 *   - each header has 16 colors, for 512 bits total per header
 *   - there are 8 headers (1 for each sprite)
 *
 * headerBaseAddr = (spriteSelect * 512) + (headerCounter * 32)
 *
 *  then, do 8 simultaneous 4-bit-word loads
 *
 *
 * assign pixelReadAddr = {5'd0,spriteY} * SPRITEWIDTH + {5'd0,spriteX} + ({11'd0,spriteToDraw} - 15'd1) * NUMPIXELSPERSPRITE;
 * assign {spriteR, spriteG, spriteB} = pokeSpriteHeaders[spriteToDraw-4'd1][pixelQ][23:0];
 *
 */

// slightly modified from the internet (I don't why some of the things are here)
// the write clock, clk1, is now negedge to match my spi slave code, because I'm
// lazy and didn't want to pass in inverted sck
module ram_dual(q, addr_in, addr_out, d, we, clk1, clk2);
   output[3:0] q;
   input [3:0] d;
   input [14:0] addr_in;
   input [14:0] addr_out;
   input we, clk1, clk2;

   reg [3:0] q;
   reg [3:0] mem [32767:0];

   always @(negedge clk1) begin
      if (we)
         mem[addr_in] <= d;
   end

   always @(negedge clk2) begin
      q <= mem[addr_out];
   end
endmodule



module ram_header(qh, addr_inh, addr_outh, dh, weh, clk1, clk2);
  output [23:0] qh;
  input [23:0] dh;
  input [7:0] addr_inh;
  input [7:0] addr_outh;
  input weh, clk1, clk2;

  reg [23:0] qh;
  reg [23:0] memh [255:0];

  always @(negedge clk1) begin
    if (weh)
      memh[addr_inh] <= dh;
  end

  always @(negedge clk2) begin
    qh <= memh[addr_outh];
  end
endmodule



