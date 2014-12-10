#ifndef BBANG_H
#define BBANG_H 1

/*************************/
/*** PROTOTYPES ***/
/*************************/

// not tested
// NOTE: REQUIRES PRE-DEFINED MAX BUFFER SIZE
/* sendCompressedSpriteFile
 *
 * A wrapper to use sendCompressedSprite without manually managing the file reading.
 */
void sendCompressedSpriteFile(unsigned long int cmd,
                              unsigned int numBytes,
                              unsigned char * filepath);

/* sendCompressedSprite
 *   cmd: value indicating which sprite box to send to
 *   numBytes: number of bytes in compressed file (header and pixel data combined)
 *   data: a buffer containing the compressed file data
 */
void sendCompressedSprite(unsigned long int cmd,
                          unsigned int numBytes,
                          unsigned char * data);

/* sendText
 *   streamID: value indicating which text box to send to
 *   text: actual text to write (12 characters required, anything longer is truncated)
 */
void sendText(unsigned char streamID, unsigned char * text);

// not tested
void updateHealthBarImages(unsigned char percentHealthPlayer1,
                           unsigned char percentHealthPlayer2);

/*
 * 0: none
 * 1: run
 * 2: switch
 * 4: fight
 */
 //playerTurn: 0:none; 1: player 1; 2: player 2
void updateMenuState(unsigned char menuState, unsigned char playerTurn);

void sendFullScreenMessage(unsigned char streamID, unsigned char * text);

void animateMainSprites();

void sendCharViaBitBanging(unsigned char q);

#endif