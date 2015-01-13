/* buttons.c
 * Justin Bai (jbai@hmc.edu)
 * MicroPs (E155) Final Project - Pokemon Battle
 * Date Created: 2014-11-24
 * Last Updated: 2014-11-28
 */

/* Summary:
 * Reads four input pins (IN1, IN2, IN3, IN4) which convey a button that
 * was pressed. Displays the value of that button to the LEDs.
 */

#include <P32xxxx.h>

// Pins representing value of input button pressed
// Value is {IN3, IN2, IN1, IN0} (supports 1 hex digit)
//#define IN3 (char) PORTEbits.RE4
//#define IN2 (char) PORTEbits.RE5
//#define IN1 (char) PORTEbits.RE6
//#define IN0 (char) PORTEbits.RE7

// TRIS bits for those pins
#define TRIS3 TRISEbits.TRISE4
#define TRIS2 TRISEbits.TRISE5
#define TRIS1 TRISEbits.TRISE6
#define TRIS0 TRISEbits.TRISE7

unsigned char getButtonInput();


unsigned char getButtonInput() {
  // Only read more input if the buttons have been released after reading an input
  // (1 when button has been released since last input processed)
  // This means that holding a button down doesn't press it repeatedly
  // (though it also means that buttons need to be fully released before
  // pressing another one---simple though not maximally functional)
  unsigned char BUTTONS_WERE_RELEASED = 0;

  // Input value
  unsigned char inputVal;

  // Set value pins' TRIS bits to input
  TRIS3 = 1;
  TRIS2 = 1;
  TRIS1 = 1;
  TRIS0 = 1;

  // If using microMudd board's LEDs as output
  //TRISD = 0xFF00;

  // Do actual stuff
  while (1) {
    char IN3 = PORTEbits.RE4;
    char IN2 = PORTEbits.RE5;
    char IN1 = PORTEbits.RE6;
    char IN0 = PORTEbits.RE7;
    inputVal = IN3 * 8 + IN2 * 4 + IN1 * 2 + IN0; //??? data type of INx? casting necessary?

    // 0 cannot be used as a program input---it represents releasing all buttons
    if (inputVal == 0) {
      BUTTONS_WERE_RELEASED = 1;
    }

    // only read more input if the buttons have been released after reading an input
    else if (BUTTONS_WERE_RELEASED == 1) {
      BUTTONS_WERE_RELEASED = 0; // perhaps should do this at end, but w/e

      // do game logic
      //PORTD = inputVal;
      return inputVal;
    }
  }
}


unsigned char main() {
  //TRISD = 0xFF00;
  //PORTD = 0x0000;
  while (1) {/*PORTD =*/ getButtonInput();}
}


