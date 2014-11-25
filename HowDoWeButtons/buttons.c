/* buttons.c
 * Justin Bai (jbai@hmc.edu)
 * MicroPs (E155) Final Project - Pokemon Battle
 * Date Created: 2014-11-24
 * Last Updated: 2014-11-24
 */

/* Summary:
 * Reads three input pins (IN1, IN2, IN3) which convey the button that
 * was pressed. Displays the button pressed to the LEDs.
 */

#define IN1 PORTBbits.RB7
#define IN2 PORTBbits.RB8
#define IN3 PORTBbits.RB9

 // set the trisb bits?

unsigned char BUTTONRESET = 0;
unsigned char inputVal;

TRISD = 0xFF00;

while (1) {
  inputVal = IN1 + IN2 << 1 + IN3 << 2; // data type of PORTBbits.RB7 - casting necessary (?)

  if (inputVal == 0) {
    BUTTONRESET = 1;
  }

  else if (BUTTONRESET == 1) {
    BUTTONRESET = 0; // perhaps should do this at end, but w/e
    processedVal = inputVal;

    // do game logic
    PORTD = processedVal;
  }
}