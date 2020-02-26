
/*
 * GoT SHAME-Bot a.k.a Robunella
 * 25.02.2020 by Groonworld
 * 
 * A little bot to impersonate GoT's Septa Unella: 
 * Upon button press, activates a servo to ring a bell and then prints "SHAME! SHAME! SHAME!" to the LCD display.    
 */

#include <LiquidCrystal.h>
#include <Servo.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// initialize servo motor
Servo motor;

int pos = 1;
int line = 0;
int buttonPin = 13;

void setup() {
  
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows:
  
  pinMode(buttonPin, INPUT_PULLUP); // Set up the push-button
  
  motor.attach(4); // Set up the Servo motor
  motor.write(60); // Move to initial position.
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {

    // Ring the bell
    motor.write(130);
    delay(300);  
    motor.write(60);

    // Delay rest of code until after the bell has rung
    delay(600);    

    // Output "SHAME!" to the display three times.
    for (int i = 0; i < 3; i++) {
      if (i <= 1) {   // First two "shame"s go on the first line
        line = 0;   
      } else {
        line = 1;     // Third "shame" goes on the second line.
        pos = 5;
      }
      lcd.setCursor(pos, line);
      lcd.print("SHAME!");
      pos += 8;
      delay(1000);
    }
  
    delay(1500);
    resetEverything();
  }
}

/*  
 *  Erases all input from the display and resets 
 *  all variables to their initial values. 
 */
void resetEverything() {
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 16; k++) {
      lcd.setCursor(k, j);
      lcd.print(" ");
    }
  }
  pos = 1;
  line = 0;
}
