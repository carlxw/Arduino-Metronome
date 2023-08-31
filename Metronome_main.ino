// Display
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Init pins
#define inc       2
#define dec       3
#define play      4
#define speaker   5

// Metronome variables
uint8_t bpm = 120;
bool enable = false;

void setup() {
  // Init GPIO
  pinMode(inc, INPUT);
  pinMode(dec, INPUT);
  pinMode(play, INPUT);
  pinMode(speaker, OUTPUT);

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
  
  // Read pins
  read_input_write_display();
}

