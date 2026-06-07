/*
 
------------ BALISE avec affichage 12864 ---------------------
 
E220         ----- Wemos D1 mini
 * M0         ----- GND
 * M1         ----- GND
 * TX         ----- PIN D2 
 * RX         ----- PIN D3 
 * AUX        ----- Not connected
 * VCC        ----- 3.3v/5v
 * GND        ----- GND
 *

ST7567A
- D5 (GPIO14) | SCK
- D7 (GPIO13) | SDA (MOSI)
- D1 (GPIO5) | RST
- D2 (GPIO4) | CS
- D0 (GPIO16) | A0 (RS)
- 3V3 | VCC
- GND | GND

*/




// U8G2_ST7567_ENH_DG128064_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* cs=*/ 4, /* dc=*/ 16, /* reset=*/ 5);




#include "Arduino.h"
#include <SoftwareSerial.h>
#include <U8x8lib.h>

U8X8_ST7567_ENH_DG128064I_4W_SW_SPI  display( /* clock=*/ 14, /* data=*/ 13, /* cs=*/ D2, /* dc=*/ D6, /* reset=*/ D1);
//U8X8_ST7567_ENH_DG128064I_4W_SW_SPI  display( /* clock=*/ 14, /* data=*/ 13, /* cs=*/ D0, /* dc=*/ D6, /* reset=*/ D8);
// U8X8_ST7567_ENH_DG128064I_4W_HW_SPI display(/* cs=*/ D0, /* dc=*/ D6, /* reset=*/ D8); 

SoftwareSerial mySerial(D4, D3); // TX RX
// HardwareSerial mySerial(1); // UART1



// Temps entre 2 requêtes (ms)
unsigned long lastQuery = 0;
const unsigned long queryInterval = 3000;
int comptage; // comptage du nombre de messages émis
int ligne ; // ligne pleine
#define characteres   120 // nombre de charactères max 

void setup() {
   Serial.begin(115200);
   mySerial.begin(9600);
 display.begin();  delay(100); // initDisplay
  display.setPowerSave(0);
  display.setFont(u8x8_font_amstrad_cpc_extended_r);
display.setCursor(0, 0);
display.setInverseFont(1);
display.println("LORA 7567");  
    delay(500);
    display.setInverseFont(0);
 //  display.setCursor(0, 1);

    Serial.println("Hi, I'm going to send message!");
 
  mySerial.println("Hello, world?");
  delay(1000);
}

void loop() { // ---------- reception de n caracteres -----------
   byte data[2048];
  char c;
  int n ; // nb de caractères disponible
  if (n=mySerial.available()) {
      Serial.print("nb de caractères disponible ");
      Serial.println(n);
    // écriture du tableau data
    for (int i = 0; i <= n; i++) {
      c = mySerial.read();
      Serial.write(c); // renvoie le caractère
      data[i] = c;
      if ((i==n) && (c != 32) )
        display.println(c); else display.print(c);
      
    }
  }

  if (Serial.available()) { // ------------- emission ------------ 
    mySerial.write(Serial.read());
  }
      if (millis() - lastQuery > queryInterval) {
    lastQuery = millis();
    mySerial.print(comptage++);mySerial.print(" ");
    if( comptage > 100 ) comptage = 0;// comptage 99 max
  }

}
