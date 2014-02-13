#include <toneAC.h>
#include "math.h"
#include <LiquidCrystal.h>

int freq = 0;
int state = 0;
const int pot = A0;

// initialize the library with the numbers of the interface pins
// LiquidCrystal lcd(rs,rw,en,d4,d5,d6,d7);
LiquidCrystal lcd(13, 12, 8, 5, 4, 3, 2);



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(40, 2);
 // Serial.begin(9600);
  
  lcd.print("Welcome ");
  lcd.println("to PSC!");
  delay(500);
  // set up Serial library at 9600 bps
  
  pinMode(pot, INPUT);

}

void loop() {

  freq = map( analogRead(pot), 0, 1023, 0, 61);
  
  toneAC(freq); // Play the frequency (150 Hz to 15 kHz in 10 Hz steps).
//  Serial.println(freq);

  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(freq);
  lcd.setCursor(0, 1);
  lcd.print("Hz");
  delay(500);

   }

