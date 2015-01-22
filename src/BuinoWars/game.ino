
extern const byte sprites[][8] PROGMEM;

const uint8_t level1[] PROGMEM = {
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1, 1, 1, 12, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 17, 1, 1, 2, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 26, 10, 11, 1, 2, 2, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 17, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 17, 2, 2, 2, 2, 1, 1, 9, 10, 10, 18, 10, 10, 18, 10, 10, 27, 2, 2, 2, 2, 1, 1, 17, 4, 1, 17, 1, 1, 17, 4, 1, 1, 1, 2, 30, 30, 30, 30, 17, 30, 30, 28, 30, 1, 17, 1, 1, 1, 2, 2, 2, 2, 1, 1, 17, 1, 30, 30, 30, 30, 17, 30, 30, 1, 2, 2, 2, 2, 1, 1, 17, 4, 1, 1, 1, 1, 17, 1, 30, 30, 30, 30, 2, 1, 1, 1, 25, 10, 10, 18, 10, 10, 27, 4, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 4, 17, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 17, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 17, 4, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 17, 2, 2, 2, 2, 2, 2, 2, 2
};

int posx = 0;
int posy = 0;

void stateGame() {
  
  // if the user presses C then go back to the main menu
  if (gb.buttons.pressed(BTN_C))
    {
      currentState = stateMainMenu;
      return;
    }
    
  if (gb.buttons.pressed(BTN_LEFT))
    posx = max(0, posx-1);
  if (gb.buttons.pressed(BTN_RIGHT))
    posx = min(16-14, posx+1);
  if (gb.buttons.pressed(BTN_UP))
    posy = max(0, posy-1);
  if (gb.buttons.pressed(BTN_DOWN))
    posy = min(16-8, posy+1);    
    
  drawMap();
}



 
 void drawMap() {
  uint8_t water_offset = (gb.frameCount / 4) % 3;
  const byte * tile_line = level1 + posy * 16 + posx;
  for (uint8_t dy=0, sy=0; dy<8; dy++, sy+=SPRITE_SIZE, tile_line+=16)
  {
    const byte * tile = tile_line;
    for (uint8_t dx=0, sx=0; dx<14; dx++, sx+=SPRITE_SIZE)
    {
      uint8_t sprite_num = pgm_read_byte(tile++) - 1;
      if (sprite_num == WATER_SPRITE)
        sprite_num += water_offset;
      drawSprite(sx, sy, sprite_num);
    }
  }
}


