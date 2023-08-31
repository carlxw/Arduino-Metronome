/**
 * @brief Inits I2C display
 * 
 */
void lcd_start() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  return;
}

/**
 * @brief Writes a message on the top display line
 * @param text Message to write to the top of the display
 *
 */
void lcd_write_top(String text) {
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print(text);
  return;
}