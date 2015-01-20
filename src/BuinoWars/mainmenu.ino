
// main menu
const char strNewGame[] PROGMEM = "New Game";
const char strContinueGame[] PROGMEM = "Continue Game";
const char strSave[] PROGMEM = "Save";
const char strExit[] PROGMEM = "Exit";

const char* const continue_menu[] PROGMEM = {strContinueGame, strSave, strExit};
#define CONTINUE_MENU_LENGTH (sizeof(continue_menu) / sizeof(const char*))

const char* const new_menu[] PROGMEM = {strNewGame, strExit};
#define NEW_MENU_LENGTH (sizeof(new_menu) / sizeof(const char*))

void stateMainMenu() {
  boolean valid = isValidGame();
  if (valid)
  {
    // continuing game
    int result = gb.menu(continue_menu, CONTINUE_MENU_LENGTH);
    switch(result) {
      case 0: currentState = stateGame; break;
      case 1: currentState = stateSaving; break;
      default: currentState = stateTitle; break;
    }
  }
  else
  {
    // new game
    int result = gb.menu(new_menu, NEW_MENU_LENGTH);
    switch(result) {
      case 0: newGame(); currentState = stateGame; break;
      default: currentState = stateTitle; break;
    }
  }
}

