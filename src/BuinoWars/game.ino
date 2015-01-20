

void stateGame() {
  if (gb.buttons.pressed(BTN_C))
    {
      currentState = stateMainMenu;
      return;
    }
    
  gb.display.println("Main game screen");
}

