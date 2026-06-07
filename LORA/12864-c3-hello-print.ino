/*


*/

#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

// U8G2_ST7567_ENH_DG128064_F_4W_SW_SPI display(U8G2_R0, /* clock=*/ 6, /* data=*/ 7, /* cs=*/ 3, /* dc=*/ 5, /* reset=*/ 4);

//U8X8_ST7567_ENH_DG128064_4W_SW_SPI u8x8(/* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8); 
U8X8_ST7567_ENH_DG128064I_4W_SW_SPI  u8x8( /* clock=*/ 6, /* data=*/ 7, /* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3);
// U8X8_ST7567_ENH_DG128064_4W_HW_SPI u8x8(/* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3); 



int i;

void setup(void)
{

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
  
}

void loop(void)
{


u8x8.print("Line :");  
u8x8.println(i++);  

  delay(500);
}
