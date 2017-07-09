#define PACK_PIXEL(r, g, b) ( ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3) )
#include <kos.h>
#include <stdio.h>

int drawPixel(int x, int y, int color) {
  switch(color) {
    case 0: //vram_s[ x + (y * 320)] = PACK_PIXEL(28, 85, 86);
    return 1;
    break;
    case 1: vram_s[ x + (y * 320)] = PACK_PIXEL(24, 187, 73);
    return 1;
    break;
    case 2: vram_s[ x + (y * 320)] = PACK_PIXEL(107, 70, 4);
    return 1;
    break;
    case 3: vram_s[ x + (y * 320)] = PACK_PIXEL(149, 245, 40);
    return 1;
    break;
    case 4: vram_s[ x + (y * 320)] = PACK_PIXEL(209, 52, 20);
    return 1;
    break;
    case 5: vram_s[ x + (y * 320)] = PACK_PIXEL(221, 155, 17);
    return 1;
    break;
    case 6: vram_s[ x + (y * 320)] = PACK_PIXEL(110, 20, 22);
    return 1;
    break;
    case 7: vram_s[ x + (y * 320)] = PACK_PIXEL(247, 223, 39);
    return 1;
    break;
    case 8: vram_s[ x + (y * 320)] = PACK_PIXEL(244, 239, 221);
    return 1;
    break;
    case 9: vram_s[ x + (y * 320)] = PACK_PIXEL(28, 85, 86);
    return 1;
    break;
    case 10: vram_s[ x + (y * 320)] = PACK_PIXEL(24, 24, 24);
    return 1;
    break;
  }
  return 0;
}

int spriteData[] = {
0 , 0 , 6 , 0 , 0 , 6 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 6 , 0 , 6 , 6 , 0 , 0 , 6 , 6 , 6 , 6 , 6 , 0 , 0 , 0 , 0 , 0 , 0 ,
6 , 0 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 , 6 , 6 , 6 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 , 0 , 0 ,
6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 , 0 , 
24, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 ,
24, 24, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 10,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 , 6 , 6 , 6 , 0 , 0 , 0 ,
};

int drawSprite(int x, int y, int* Data) {
  int i;
  int j;
  int pixelCounter = 0;

  for(i = 0; i < 16; i++) {
    for(j = 0; j < 16; j++) {
      drawPixel( (x + j), (y + i), Data[pixelCounter]);
      pixelCounter++;
    }
  }
}

int main(void) {
 int quit = 0;
 int x = 2;
 int y = 3;

pvr_init_defaults();

vid_set_mode(DM_320x240, PM_RGB565);

  while(!quit) {
    drawSprite(x, y, spriteData);
  }
}
 
