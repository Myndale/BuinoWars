
const byte sprites[][8] PROGMEM = {
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xac, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xbc, 0xec, 0xf8, 0xfc, 0xac, 0xf8},
        {6, 6, 0xfc, 0xac, 0xfc, 0xac, 0xac, 0xac},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xac, 0xac, 0xfc, 0xac, 0xfc, 0xac},
        {6, 6, 0xf8, 0xf8, 0xa8, 0xf8, 0xa8, 0xf8},
        {6, 6, 0xfc, 0xe8, 0xbc, 0xec, 0xfc, 0xf8},
        {6, 6, 0xfc, 0xa8, 0xfc, 0xac, 0xfc, 0xa8},
        {6, 6, 0xfc, 0xbc, 0xec, 0xbc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xac, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xf8, 0xfc, 0xfc, 0xfc, 0xf8},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xec, 0xa8, 0xa8, 0xac},
        {6, 6, 0xa8, 0xa8, 0xb8, 0xfc, 0xfc, 0xf8},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xa8, 0xfc, 0xac, 0xfc, 0xf8},
        {6, 6, 0xfc, 0xa8, 0xfc, 0xec, 0xfc, 0xa8},
        {6, 6, 0xfc, 0xf8, 0xfc, 0xac, 0xfc, 0xf8},
        {6, 6, 0xfc, 0xac, 0xfc, 0xbc, 0xfc, 0xac},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xf8, 0xfc, 0xec, 0xbc, 0xe8},
        {6, 6, 0xfc, 0xf8, 0xfc, 0xac, 0xfc, 0xa8},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xbc, 0xec, 0xbc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xac},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc},
        {6, 6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc}
};

/*
void drawSprite(int screenx, int screeny, int spritex, int spritey) {
  uint8_t w = pgm_read_byte(sprites);
  uint8_t h = pgm_read_byte(sprites + 1);
  gb.display.setColor(BLACK);
  for (int dy=0; dy<SPRITE_SIZE; dy++)
    for (int dx=0; dx<SPRITE_SIZE; dx++)
    {
      int offset = ((spritey*SPRITE_SIZE)+dy) * w + (spritex*SPRITE_SIZE)+dx;
      int8_t block = pgm_read_byte(sprites + 2 + offset/8);
      int8_t mask = 0x80 >> (offset%8);
      if (block & mask)
        gb.display.drawPixel(screenx+dx, screeny+dy);
    }
}

void drawSprite(int screenx, int screeny, int spritex, int spritey) {
  uint8_t w = pgm_read_byte(sprites);
  uint8_t h = pgm_read_byte(sprites + 1);
  uint8_t * buffer = gb.display.getBuffer();
  gb.display.setColor(BLACK);
  uint16_t sprite_line = (spritey*SPRITE_SIZE) * w;
  uint8_t sprite_offset_x = spritex*SPRITE_SIZE;
  for (int dy=0; dy<SPRITE_SIZE; dy++, sprite_line+=w, screeny++)
  {    
    uint16_t row = (screeny / 8) * LCDWIDTH;
    uint16_t sprite_addr = sprite_line + sprite_offset_x;
    uint8_t screen_mask = 0x01 << (screeny % 8);
    uint8_t sprite_mask = 0x80 >> (sprite_addr%8);
    for (int dx=0; dx<SPRITE_SIZE; dx++, sprite_addr++)
    {      
      uint8_t block = pgm_read_byte(sprites + 2 + sprite_addr/8);
      if (block & sprite_mask)
      {        
        uint8_t sx = screenx + dx;        
        int addr = sx + row;        
        buffer[addr] |= screen_mask;
      }
      sprite_mask = (sprite_mask==1) ? 0x80 :  (sprite_mask>>1);
    }
  }
}

void drawSpriteAnimated(int screenx, int screeny, int spritex, int spritey, int animx, int animy) {
  uint8_t w = pgm_read_byte(sprites);
  uint8_t h = pgm_read_byte(sprites + 1);
  gb.display.setColor(BLACK);
  for (int dy=0; dy<SPRITE_SIZE; dy++)
    for (int dx=0; dx<SPRITE_SIZE; dx++)
    {
      int sy = dy + animx;
      if (sy > ) sy -= SPRITE_SIZE;
      int offset = ((spritey*SPRITE_SIZE)+dy) * w + (spritex*SPRITE_SIZE)+dx;
      int8_t block = pgm_read_byte(sprites + 2 + offset/8);
      int8_t mask = 0x80 >> (offset%8);
      if (block & mask)
        gb.display.drawPixel(screenx+dx, screeny+dy);
    }
}
*/
