
/*
 * GoT SHAME! Bot
 * 25.02.2020 by Groonworld
 * 
 * Goal: Upon button press, activates a servo to ring a bell and then prints "SHAME! SHAME! SHAME!" to the LCD display.
 * 
 * Current state: Printing "Shame" to the LCD display on button press works as desired.
 * 
 * Next:  - Add servo
 *       
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int POS = 1;
int LINE = 0;
int buttonApin = 13;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  //Set up the push-button
  pinMode(buttonApin, INPUT_PULLUP);
}

void loop() {
  // Prints "SHAME!" to the LCD three times.
  if (digitalRead(buttonApin) == LOW) {
    delay(500);
  for (int i = 0; i < 3; i++) {
    if (i <= 1) {   // First two "shame"s go on the first line
      LINE = 0;   
    } else {
      LINE = 1;     // Third "shame" goes on the second line.
      POS = 5;
    }
    lcd.setCursor(POS, LINE);
    lcd.print("SHAME!");
    POS += 8;
    delay(1000);
  }
  
  delay(1500);
  wipe();
  }
}

/*  
 *   Erases all input from the display and resets 
 *  all variables to their initial values. 
 */
void wipe() {
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 16; k++) {
      lcd.setCursor(k, j);
      lcd.print(" ");
    }
  }
  POS = 1;
  LINE = 0;
}
 
