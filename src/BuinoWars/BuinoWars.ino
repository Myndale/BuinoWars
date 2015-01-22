#include <SPI.h>
#include <Gamebuino.h>
#include <EEPROM.h>
Gamebuino gb;

#define SPRITE_SIZE 6
#define WATER_SPRITE 29

// function ptr typedef for implementing a simple FSM 
typedef void (* StateHandler)();
StateHandler currentState = stateTitle;

const char GAME_ID[] PROGMEM = "BWARS v0.01";

struct GameState
{
  char id[sizeof(GAME_ID)];
  
} gameState;


void setup(){
  Serial.begin(9600);
  gb.begin();
  
  // todo: take this out, it's only for development
  //newGame();
  //currentState = stateGame;
}

void loop(){
  if(gb.update())
    (*currentState)();
}



