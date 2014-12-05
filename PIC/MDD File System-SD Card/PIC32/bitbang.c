#include <P32xxxx.h>

#define SCK3A PORTBbits.RB14
#define SDO3A PORTFbits.RF5

void sendCompressedSprite(unsigned long int cmd,
                          unsigned int numBytes,
                          unsigned char * data);

void sendCharViaBitBanging(unsigned char q);

void sendText(unsigned char streamID, unsigned char * text);

void sendText(unsigned char streamID, unsigned char * text) {
  unsigned int i = 0;
  sendCharViaBitBanging(0);
  sendCharViaBitBanging(0);
  sendCharViaBitBanging(1); // cmdType == 1 for text
  sendCharViaBitBanging(streamID);

  while (i < 12) {
    sendCharViaBitBanging(text[i]);
    sendCharViaBitBanging(text[i+1]);
    sendCharViaBitBanging(text[i+2]);
    sendCharViaBitBanging(text[i+3]);
    i += 4;
  }
}


void sendCompressedSprite(unsigned long int cmd,
                          unsigned int numBytes,
                          unsigned char * data) {
  unsigned int i = 0;
 //unsigned char cmda = (cmd & 0xFF000000) >> 24;
  sendCharViaBitBanging((unsigned char)((cmd & 0xFF000000) >> 24));
  sendCharViaBitBanging((unsigned char)((cmd & 0x00FF0000) >> 16));
  sendCharViaBitBanging((unsigned char)((cmd & 0x0000FF00) >> 8));
  sendCharViaBitBanging((unsigned char)((cmd & 0x000000FF)));

  while (i < numBytes) {
    sendCharViaBitBanging(data[i]);
    sendCharViaBitBanging(data[i+1]);
    sendCharViaBitBanging(data[i+2]);
    sendCharViaBitBanging(data[i+3]);
    i += 4;
  }
}


// not very timing-friendly, would want to reorganize to get that
void sendCharViaBitBanging(unsigned char q) {
/*
  SDO3A = (q & 1);
  SCK3A = 1;
  //Nop();
  SCK3A = 0;

  SDO3A = (q & 2) >> 1;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 4) >> 2;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 8) >> 3; // hopefully this works since q is unsigned
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 16) >> 4;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 32) >> 5;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 64) >> 6;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 128) >> 7;
  SCK3A = 1;
  SCK3A = 0;
*/

  SDO3A = (q & 128) >> 7;
  Nop();
  Nop();
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 64) >> 6;
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 32) >> 5;
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 16) >> 4; // hopefully this works since q is unsigned
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 8) >> 3;
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 4) >> 2;
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 2) >> 1;
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;

  SDO3A = (q & 1);
  Nop();
  SCK3A = 1;
  Nop();
  SCK3A = 0;


}



