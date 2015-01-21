
extern const byte sprites[] PROGMEM;

const byte level1[] PROGMEM = {
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1, 1, 1, 12, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 17, 1, 1, 2, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 26, 10, 11, 1, 2, 2, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 17, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 17, 2, 2, 2, 2, 1, 1, 9, 10, 10, 18, 10, 10, 18, 10, 10, 27, 2, 2, 2, 2, 1, 1, 17, 4, 1, 17, 1, 1, 17, 4, 1, 1, 1, 2, 3, 3, 3, 3, 17, 3, 3, 28, 3, 1, 17, 1, 1, 1, 2, 2, 2, 2, 1, 1, 17, 1, 3, 3, 3, 3, 17, 3, 3, 1, 2, 2, 2, 2, 1, 1, 17, 4, 1, 1, 1, 1, 17, 1, 3, 3, 3, 3, 2, 1, 1, 1, 25, 10, 10, 18, 10, 10, 27, 4, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 4, 17, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 17, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 17, 4, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 17, 2, 2, 2, 2, 2, 2, 2, 2
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

const byte sprite[] PROGMEM = {8, 6, B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};

void drawBitmapUnrolled(int8_t x, int8_t y, const uint8_t *bitmap) {

  int8_t w = pgm_read_byte(bitmap);
  int8_t h = pgm_read_byte(bitmap + 1);
  bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
  int8_t i, j, byteWidth = (w + 7) >> 3;
  uint8_t * screen_line = gb.display.getBuffer() + x;
  const uint8_t * bitmap_line = bitmap;

  uint8_t dsty = y;
  uint8_t mask = _BV(y & 7);
  for (j = 0; j < h; j++, dsty++, bitmap_line+=byteWidth, mask = (mask & 0x80) ? 1 : (mask<<1))
  {
    int ofs = (dsty >> 3) * LCDWIDTH_NOROT;
    int8_t dstx = x;
    const uint8_t * bitmap_src = bitmap_line;
    uint8_t * ptr = screen_line + ofs;    
    int8_t i = w;
    while (i >= 8)
    {
      uint8_t pixels = pgm_read_byte(bitmap_src++);
      if (pixels & 0x80)
        ptr[0] |= mask;
      if (pixels & 0x40)
        ptr[1] |= mask;
      if (pixels & 0x20)
        ptr[2] |= mask;
      if (pixels & 0x10)
        ptr[3] |= mask;
      if (pixels & 0x08)
        ptr[4] |= mask;
      if (pixels & 0x04)
        ptr[5] |= mask;
      if (pixels & 0x02)
        ptr[6] |= mask;
      if (pixels & 0x01)
        ptr[7] |= mask;
       
      ptr += 8;
      i -= 8;
      dstx += 8;      
    }
    if (i)
    {
       uint8_t pixels = pgm_read_byte(bitmap_src);
       while (i--)
       {
         if (pixels & 0x80)
         gb.display.drawPixel(dstx, dsty);
         pixels <<= 1;
       }
     }     
  }

}

  
 void drawMap() {
  const byte * tile_line = level1 + posy * 16 + posx;
  for (int dy=0, sy=0; dy<8; dy++, sy+=SPRITE_SIZE, tile_line+=16)
  {
    const byte * tile = tile_line;
    for (int dx=0, sx=0; dx<14; dx++, sx+=SPRITE_SIZE)
    {
      byte sprite_num = pgm_read_byte(tile++) - 1;
      drawBitmapUnrolled(sx, sy, sprite);
      //gb.display.drawBitmap(sx, sy, sprite);
      //gb.display.drawBitmap(sx, sy, sprite);
      //gb.display.drawBitmap(sx, sy, sprite);
      //drawSprite(sx, sy, sprite_num%8, sprite_num/8);
      //drawSprite(sx, sy, sprite_num%8, sprite_num/8);
      //drawSprite(sx, sy, sprite_num%8, sprite_num/8);
    }
  }
}


