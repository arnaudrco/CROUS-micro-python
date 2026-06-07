/*
 HELLO
 fonction type FEED pour afficher des lignes 
*/

#include <Arduino.h>
#include <U8x8lib.h>

U8X8_ST7567_ENH_DG128064I_4W_SW_SPI  display( /* clock=*/ 6, /* data=*/ 7, /* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3);

int i,j; // affiche un compteur

void setup(void){

    Serial.begin(115200);
 delay(100);
     Serial.println(F("7567a"));
  display.begin();  delay(100); // initDisplay
  display.setPowerSave(0);
//  u8x8.setContrast(200);
  display.setFont(u8x8_font_amstrad_cpc_extended_r);

    display.setInverseFont(1);
display.println("LORA 7567");  
    delay(500);
    display.setInverseFont(0);
        display.setCursor(0, 1);
}

void loop(void)
{
if (i++ >= 5) { // pas plus de 5 lignes
  display.setCursor(0, 1); // retour ligne 0
  i=0;
}
display.print("Ligne :");  
display.println(j++); 
  delay(500);
}
