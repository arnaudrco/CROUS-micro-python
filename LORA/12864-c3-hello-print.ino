/*

 HELLO 
*/

#include <Arduino.h>
#include <U8x8lib.h>

U8X8_ST7567_ENH_DG128064I_4W_SW_SPI  u8x8( /* clock=*/ 6, /* data=*/ 7, /* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3);

int i,j; // affiche un compteur

void setup(void){

    Serial.begin(115200);
 delay(100);
     Serial.println(F("7567a"));
  u8x8.begin();  delay(100); // initDisplay
  u8x8.setPowerSave(0);
//  u8x8.setContrast(200);
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
u8x8.setCursor(0, 0);
u8x8.println("Hello 7567a");  
u8x8.println("0123456789012345");  
    delay(500);
    u8x8.setCursor(0, 0);
}

void loop(void)
{
if (i++ >= 8) { // pas plus de 8 lignes
  u8x8.setCursor(0, 0); // retour ligne 0
  i=0;
}
u8x8.print("Line :");  
u8x8.println(j++); 
  delay(500);
}
