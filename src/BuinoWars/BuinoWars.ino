#include <SPI.h>
#include <Gamebuino.h>
#include <EEPROM.h>
Gamebuino gb;

// function ptr typedef for implementing a simple FSM 
typedef void (* StateHandler)();
StateHandler currentState = stateTitle;

const char GAME_ID[] PROGMEM = "GBWARS v0.01";

struct GameState
{
  char id[sizeof(GAME_ID)];
  
} gameState;


void setup(){
  Serial.begin(9600);
  gb.begin();
}

void loop(){
  if(gb.update())
    (*currentState)();
}



