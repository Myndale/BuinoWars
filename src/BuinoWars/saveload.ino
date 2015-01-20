
void restoreGame() {
  
  // copy from eeprom to the game state
  for (int i=0; i<sizeof(gameState); i++)
    ((uint8_t*)&gameState)[i] = EEPROM.read(i);
}

void saveGame() {
  for (int i=0; i<sizeof(gameState); i++)
    EEPROM.write(i, ((uint8_t*)&gameState)[i]);
}

void newGame() {
  strcpy_P(gameState.id, GAME_ID);
}

boolean isValidGame() {
  return strcmp_P(gameState.id, GAME_ID) == 0;
}

void stateSaving() {
  saveGame();
  gb.popup(F("Saved!"), 40);
  currentState = stateMainMenu;
}
