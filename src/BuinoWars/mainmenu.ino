// main menu
const char strPlay[] PROGMEM = "Play";
const char strExit[] PROGMEM = "Exit";
const char* const main_menu[] PROGMEM = {strPlay, strExit};
#define MENULENGTH (sizeof(main_menu) / sizeof(const char *))

void stateMainMenu() {
  int result = gb.menu(main_menu, MENULENGTH);
  switch(result) {
    
    // play
    case 0: 
      currentState = stateGame;
      return;
      
    // Exit
    case 1:
      currentState = stateTitle;
      break;
  }
}

