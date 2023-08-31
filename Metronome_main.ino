// Config
#include "config.h"

// Display
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Core variables
uint8_t bpm = DEFAULT_BPM;
bool enable = false;
String visual = ""; /* Variable moved here for scoping purposes */

void setup() {
  // Init GPIO
  pinMode(INC, INPUT);
  pinMode(DEC, INPUT);
  pinMode(PLAY, INPUT);
  pinMode(SPEAKER, OUTPUT);

  // Debug
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Starting");

  // Initialize the LCD
  lcd_start();
  lcd.print("BPM: " + (String) bpm);
}

void loop() {
  // Metronome output on toggle
  if (enable) beep(60000/bpm);
  else if (!visual.equals("")) {
    visual = "";
    lcd_clear_line(2);
  }
  
  // Read pins
  read_input_write_display();
}

