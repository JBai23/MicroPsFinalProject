module pokemonBattle(input  logic       clk,
                     input  logic       sck, //jbai
                     input  logic       mosi, //jbai
                     output logic       vgaclk, // 25 MHz VGA clock
                     output logic       hsync, vsync, sync_b, blank_b, //jbai to monitor & DAC
                     output logic [7:0] r, g, b, // to video DAC
							output logic [3:0] row, // for keypad
							input  logic [3:0] col, // for keypad
							output logic [3:0] buttonVal); // for keypad

  vga battleDisplay(clk, sck, mosi, vgaclk, hsync, vsync, sync_b, blank_b, r, g, b);
  
  keypadReader kpr(clk, row, col, buttonVal);

endmodule
