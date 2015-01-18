
void restoreGame() {
  
  // copy from eeprom to the game state
  for (int i=0; i<sizeof(gameState); i++)
    ((uint8_t*)&gameState)[i] = EEPROM.read(i);
  
  // if it's not a valid save then start a new game
  if (strcmp_P(gameState.id, GAME_ID))
  {
    gb.popup(F("New Game!"), 100);
    newGame();
    saveGame();
  }
}

void saveGame() {
  for (int i=0; i<sizeof(gameState); i++)
    EEPROM.write(i, ((uint8_t*)&gameState)[i]);
  
}

void newGame() {
  strcpy_P(gameState.id, GAME_ID);
}

