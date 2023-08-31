/**
 * @brief Inits I2C display
 * 
 */
void lcd_start() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  return;
}

/**
 * @brief Writes a message on the top display line
 * @param text Message to write to the top of the display
 * @param line Line number to write on, not zero-indexed
 *
 */
void lcd_write(String text, uint8_t line) {
  lcd.setCursor(0, line - 1);
  lcd.print(text);
  return;
}

/**
 * @brief Clears line x only on LCD display 2x16
 * @param line Line to clear, not zero-indexed
 * 
 */
void lcd_clear_line(uint8_t line) {
  lcd.setCursor(0, line - 1);
  lcd.print("                ");
}