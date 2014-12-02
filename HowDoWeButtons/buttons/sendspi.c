#include <P32xxxx.h>


void initspi3(void);
char spi3_send_receive(long int send);
int sendCompressedSprite(long int cmd, int numcolors, int numPixels, char * data); // filepath


//jbai modified from provided code (spi.c)
void initspi3(void) {
  long int junk; //jbai

  SPI3CONbits.ON = 0; // disable SPI to reset any previous state
  junk = SPI3BUF; // read SPI buffer to clear the receive buffer
  SPI3BRG = 7; //jbai (comment change) set BAUD rate
  SPI3CONbits.MSTEN = 1; // enable master mode
  SPI3CONbits.CKE = 1; // set clock-to-data timing (data centered on rising SCK edge) 
  SPI3CONbits.ON = 1; // turn SPI on
  SPI3CONbits.MODE32 = 1; //jbai allows us to use only *one* 32-bit packet
}


//jbai modified from provided code (spi.c)
char spi3_send_receive(long int send) { //jbai
  SPI3BUF = send; // send data to slave
  while (!SPI3STATbits.SPIBUSY); // wait until received buffer fills, indicating data received 
  return SPI3BUF; // return received data and clear the read buffer full
}


int sendCompressedSprite(long int cmd, int numcolors, int numPixels, char * data) { // filepath

  const int numPixelsPerByte = 2;

  spi3_send_receive(cmd);

  int i = 0;
  while (i < numcolors + numPixels / (4 * numPixelsPerByte)) {
    spi3_send_receive( (long int)(data[i])<<24 +
                      (long int)(data[i+1])<<16 +
                      (long int)(data[i+2])<<8 +
                      (long int)(data[i+3]));
    i += 4;
  }
}


