// read_input_write_display()
unsigned long current_debounce = 0;
unsigned long delay_debounce = BUTTON_DEBOUNCE_MS;
unsigned long buttonHoldI = 0;
unsigned long buttonHoldD = 0;

// beep() 
unsigned long current_beep = 0;
String output_concat = String(PULSE_CHAR) + " ";

// =================================================

/**
 * @brief Controls display and inputs
 *
 */
void read_input_write_display () {
  while (millis() - current_debounce >= delay_debounce) {
    // Reset delay
    current_debounce = millis();

    // Adjust BPM by increments of 10 or 1
    uint8_t last_bpm = bpm;
    if (millis() - buttonHoldI >= BUTTON_HOLD_TIME_MS && digitalRead(INC) && bpm + 10 <= MAX_BPM) bpm += 10;
    else if (digitalRead(INC) && bpm + 1 <= MAX_BPM) bpm += 1;
    else if (millis() - buttonHoldD >= BUTTON_HOLD_TIME_MS && digitalRead(DEC) && bpm - 10 >= MIN_BPM) bpm -= 10;
    else if (digitalRead(DEC) && bpm - 1 >= MIN_BPM) bpm -= 1;

    // Reset to 120 BPM if both buttons are pressed - Avoids need of pressing hardware reset button
    if (digitalRead(INC) && digitalRead(DEC)) bpm = DEFAULT_BPM;
    
    // Reset timers on button release 
    if (!digitalRead(INC)) buttonHoldI = millis();
    if (!digitalRead(DEC)) buttonHoldD = millis();

    // Update display when transitioning over from 3 digits BPM to 2 digits BPM 
    if (last_bpm >= 100 && bpm < 100) lcd_clear_line(1);
    
    // Update display if BPM changes
    if (last_bpm != bpm) lcd_write("BPM: " + (String) bpm, 1);

    // Metronome tone toggle
    if (digitalRead(PLAY)) enable = !enable;
  }
}

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
    tone(SPEAKER, 550, 100);
    
    if (visual.equals(String(PULSE_CHAR) + ' ' + String(PULSE_CHAR) + ' ' + String(PULSE_CHAR) + ' ' + String(PULSE_CHAR) + ' ')) {
      visual = String(PULSE_CHAR) + " ";
      lcd_clear_line(2);
    }
    else visual += output_concat;

    lcd_write(visual, 2);
  }
}
