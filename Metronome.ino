// read_input_write_display()
unsigned long current_debounce = 0;
unsigned long delay_debounce = 125;
unsigned long buttonHoldI = 0;
unsigned long buttonHoldD = 0;

// beep() 
unsigned long current_beep = 0;
String output_concat = "| ";

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
    if (millis() - buttonHoldI >= 1500 && digitalRead(inc) && bpm + 10 <= 240) bpm += 10;
    else if (digitalRead(inc) && bpm + 1 <= 240) bpm += 1;
    else if (millis() - buttonHoldD >= 1500 && digitalRead(dec) && bpm - 10 >= 40) bpm -= 10;
    else if (digitalRead(dec) && bpm - 1 >= 40) bpm -= 1;

    // Reset to 120 BPM if both buttons are pressed - Avoids need of pressing hardware reset button
    if (digitalRead(inc) && digitalRead(dec)) bpm = 120;
    
    // Reset timers on button release 
    if (!digitalRead(inc)) buttonHoldI = millis();
    if (!digitalRead(dec)) buttonHoldD = millis();

    // Update display when transitioning over from 3 digits BPM to 2 digits BPM 
    if (last_bpm >= 100 && bpm < 100) lcd_clear_line(1);
    
    // Update display if BPM changes
    if (last_bpm != bpm) lcd_write("BPM: " + (String) bpm, 1);

    // Metronome tone toggle
    if (digitalRead(play)) enable = !enable;
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
    tone(speaker, 550, 100);

    if (visual.equals("| | | | ")) {
      visual = "| ";
      lcd_clear_line(2);
    }
    else visual += output_concat;

    lcd_write(visual, 2);
  }
}
