#include <P32xxxx.h>
#include <FSIO.h>
#include "bitbang.h"

#define SCK3A PORTBbits.RB14
#define SDO3A PORTFbits.RF5

// #define MAX_SPRITE_BUFFER_SIZE 2112
#define MAX_SPRITE_BUFFER_SIZE 3000


/* Notes on spriteSelect / text streams
 *
 * Sprite Select
 *   0: Player 1 main sprite.
 *   1: Player 2 main sprite.
 *   2-7: The "switch pokemon" sprites at the bottom, 2-7 is left-to-right
 *
 * Text Stream Select
 *   0-3: Moves 0-3.
 *   4+: Unimplemented.
 */


/**********************/
/*** IMPLEMENTATION ***/
/**********************/

void sendCompressedSpriteFile(unsigned long int cmd,
                              unsigned int numBytes,
                              unsigned char * filepath) {

  unsigned char spriteBuf[MAX_SPRITE_BUFFER_SIZE]; // DO NOT OVERFILL

  FSFILE * pointer;

  pointer = FSfopen(filepath, "r"); // read mode
  if (pointer == NULL) {while(1);}

  if (FSfread(spriteBuf, 1, numBytes, pointer) != numBytes) {while(1);}

  if (FSfclose(pointer)) {while(1);}

  sendCompressedSprite(cmd, numBytes, &spriteBuf[0]);
}



// cmd should be spriteSelect
void sendCompressedSprite(unsigned long int cmd,
                          unsigned int numBytes, // header plus data
                          unsigned char * data) {
  unsigned int i = 0;

  sendCharViaBitBanging((unsigned char)((cmd & 0xFF000000) >> 24));
  sendCharViaBitBanging((unsigned char)((cmd & 0x00FF0000) >> 16));
  sendCharViaBitBanging((unsigned char)((cmd & 0x0000FF00) >> 8)); // should be cmdType 0
  sendCharViaBitBanging((unsigned char)((cmd & 0x000000FF)));

  while (i < numBytes) {
    sendCharViaBitBanging(data[i]);
    sendCharViaBitBanging(data[i+1]);
    sendCharViaBitBanging(data[i+2]);
    sendCharViaBitBanging(data[i+3]);
    i += 4;
  }
}


void sendText(unsigned char streamID, unsigned char * text) {
  int i;
  int j;

  sendCharViaBitBanging(0);
  sendCharViaBitBanging(0);
  sendCharViaBitBanging(1); // cmdType == 1 for text
  sendCharViaBitBanging(streamID);

  for (i = 0; i < 12; i += 4) {
    for (j = 0; j < 4 && text[i + j]; ++j) {
      sendCharViaBitBanging((char)toupper(text[i + j]));
    }
    if (j < 4) {
      i += j;
      break;
    }
  }

  for (; i < 12; ++i) {
    sendCharViaBitBanging(' ');
  }
}



void updateHealthBarImages(unsigned char percentHealthPlayer1,
                           unsigned char percentHealthPlayer2) {
  sendCharViaBitBanging(percentHealthPlayer1);
  sendCharViaBitBanging(percentHealthPlayer2);
  sendCharViaBitBanging(2); // cmdType 2
  sendCharViaBitBanging(0);
}

void updateMenuState(unsigned char menuState, unsigned char playerTurn) {
  sendCharViaBitBanging(menuState);
  sendCharViaBitBanging(playerTurn); // 0:none; 1: player 1; 2: player 2
  sendCharViaBitBanging(3);
  sendCharViaBitBanging(0);
}

void sendFullScreenMessage( unsigned char streamID, unsigned char * text) {
  int i;
  int j;

  sendCharViaBitBanging(0);
  sendCharViaBitBanging(0);
  sendCharViaBitBanging(4);
  sendCharViaBitBanging(streamID);

  for (i = 0; i < 80; i += 4) {
    for (j = 0; j < 4 && text[i + j]; ++j) {
      sendCharViaBitBanging((char)toupper(text[i + j]));
    }
    if (j < 4) {
      i += j;
      break;
    }
  }
  for (; i < 80; ++i) {
    sendCharViaBitBanging(' ');
  }
}

void animateMainSprites() {
  sendCharViaBitBanging(0);
  sendCharViaBitBanging(0);
  sendCharViaBitBanging(5);
  sendCharViaBitBanging(0);
}


// not very timing-friendly, would want to reorganize to get that
void sendCharViaBitBanging(unsigned char q) {

  SDO3A = (q & 128) >> 7; // hopefully this works since q is unsigned
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 64) >> 6;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 32) >> 5;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 16) >> 4;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 8) >> 3;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 4) >> 2;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 2) >> 1;
  SCK3A = 1;
  SCK3A = 0;

  SDO3A = (q & 1);
  SCK3A = 1;
  SCK3A = 0;
}



