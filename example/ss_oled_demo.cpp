
#include "pico/stdlib.h"
#include "ss_oled.hpp"

// RPI Pico
#define SDA_PIN 4
#define SCL_PIN 5
#define PICO_UART i2c0
#define I2C_SPEED 100 * 1000


#define OLED_WIDTH 128
#define OLED_HEIGHT 64


int main() {

static uint8_t ucBuffer[1024];
uint8_t uc[8];
int i, j, rc;
char szTemp[32];
picoSSOLED myOled(OLED_128x64, 0x3c, 0, 0, PICO_UART, SDA_PIN, SCL_PIN, I2C_SPEED);
    
  rc = myOled.init() ;
  myOled.set_back_buffer(ucBuffer);
  
  while (1) {
	  
  if (rc != OLED_NOT_FOUND)
  { 
    myOled.fill(0,1);
    myOled.set_contrast(127);
    myOled.write_string(0,0,0,(char *)"**************** ", FONT_8x8, 0, 1);
    myOled.write_string(0,4,1,(char *)"Pi Pico SS_OLED", FONT_8x8, 0, 1);
    myOled.write_string(0,8,2,(char *)"running on the", FONT_8x8, 0, 1);
    myOled.write_string(0,8,3,(char *)"SSD1306 128x64", FONT_8x8, 0, 1);
    myOled.write_string(0,4,4,(char *)"monochrome OLED", FONT_8x8, 0, 1);
    myOled.write_string(0,24,5,(char *)"Written By L BANK", FONT_8x8, 0, 1);
    myOled.write_string(0,24,6,(char *)"Pico by M KOOIJ", FONT_8x8, 0, 1);
    myOled.write_string(0,0,7,(char *)"**************** ", FONT_8x8, 0, 1);
    sleep_ms(5000);
  }

  myOled.fill(0,1);
  myOled.write_string(0,0,0,(char *)"Now with 5 font sizes", FONT_6x8, 0, 1);
  myOled.write_string(0,0,1,(char *)"6x8 8x8 16x16", FONT_8x8, 0, 1);
  myOled.write_string(0,0,2,(char *)"16x32 and a new", FONT_8x8, 0, 1);
  myOled.write_string(0,0,3,(char *)"Stretched", FONT_12x16, 0, 1);
  myOled.write_string(0,0,5,(char *)"from 6x8", FONT_12x16, 0, 1);
  sleep_ms(5000);
  

  int x, y;
  myOled.fill(0, 1);
  myOled.write_string(0,0,0,(char *)"Backbuffer Test", FONT_NORMAL,0,1);
  myOled.write_string(0,0,1,(char *)"96 lines", FONT_NORMAL,0,1);
  sleep_ms(2000);
  for (x=0; x<OLED_WIDTH-1; x+=2)
	{
	myOled.draw_line(x, 0, OLED_WIDTH-x, OLED_HEIGHT-1, 1);
	};
  for (y=0; y<OLED_HEIGHT-1; y+=2)
    {
    myOled.draw_line(OLED_WIDTH-1,y, 0,OLED_HEIGHT-1-y, 1);
    };
  myOled.write_string(0,0,1,(char *)"Without backbuffer", FONT_SMALL,0,1);
  sleep_ms(2000);
  myOled.fill(0,1);
  for (x=0; x<OLED_WIDTH-1; x+=2)
  {
    myOled.draw_line(x, 0, OLED_WIDTH-1-x, OLED_HEIGHT-1, 0);
  }
  for (y=0; y<OLED_HEIGHT-1; y+=2)
  {
    myOled.draw_line(OLED_WIDTH-1,y, 0,OLED_HEIGHT-1-y, 0);
  }
  myOled.dump_buffer(ucBuffer);
  myOled.write_string(0,0,1,(char *)"With backbuffer", FONT_SMALL,0,1);
  sleep_ms(2000);
  }

  return 0;
} // main
