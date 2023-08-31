unsigned long current_debounce = 0;
unsigned long delay_debounce = 125;
unsigned long buttonHoldI = 0;
unsigned long buttonHoldD = 0;
/**
 * @brief Controls display and inputs
 *
 */
void read_input_write_display () {
  while (millis() - current_debounce >= delay_debounce) {
    // Reset delay
    current_debounce = millis();

    // Action
    uint8_t last_bpm = bpm;
    if (millis() - buttonHoldI >= 1500 && digitalRead(inc) && bpm + 10 < 240) {
      bpm += 10;
    }
    else if (millis() - buttonHoldD >= 1500 && digitalRead(dec) && bpm - 10 > 0) {
      bpm -= 10;
    }
    else if (digitalRead(inc) && bpm + 1 < 240) {
      // Start recording hold time
      bpm += 1;
    }
    else if (digitalRead(dec) && bpm - 1 > 40) {
      bpm -= 1;
    }
    
    // Reset timers on button release 
    if (!digitalRead(inc)) buttonHoldI = millis();
    if (!digitalRead(dec)) buttonHoldD = millis();

    // Update display if BPM changes
    if (last_bpm != bpm) lcd_write_top("BPM: " + (String) bpm);

    // Metronome tone toggle
    if (digitalRead(play)) enable = !enable;
  }
}

unsigned long current_beep = 0;
/**
 * @brief Causes speaker to beep wrt input delay
 * @param delay_beep ms required for input BPM
 *
 */
void beep(unsigned long delay_beep) {
  while (millis() - current_beep >= delay_beep) {
    // Reset delay
    current_beep = millis();

    // Action
    tone(speaker, 550, 100);
  }
}
