/*
 
- ESP32-C3 | ST7567A
- GPIO6 | SCK
- GPIO7 | MOSI
- GPIO4 | CS
- GPIO5 | DC
- GPIO3 | RST
- 3V3 | VCC
- GND | GND


*/

 
#include <U8g2lib.h>

U8G2_ST7567_ENH_DG128064_F_4W_SW_SPI display(U8G2_R0, /* clock=*/ 6, /* data=*/ 7, /* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3);
// U8G2_ST7567_128X64_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3);
// U8G2_ST7567_128X64_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 6, /* data=*/ 7, /* cs=*/ 4, /* dc=*/ 5, /* reset=*/ 3);

HardwareSerial mySerial(1); // UART1



// Temps entre 2 requêtes (ms)
unsigned long lastQuery = 0;
const unsigned long queryInterval = 3000;
int comptage; // comptage du nombre de messages émis
int ligne ; // ligne pleine
#define characteres   120 // nombre de charactères max 

void setup() {
   Serial.begin(115200);
    mySerial.begin(9600, SERIAL_8N1, 20, 21); // RX=20, TX=21
  display.begin();
 // u8g2.setContrast(50); // Contraste (0-255)
  display.setFont(u8g2_font_6x10_tf);
 // u8g2.setFont(u8g2_font_fub20_tf);
// u8g2.setFont(u8g2_font_nlogis12_tf);
  display.setFontMode(0);

    Serial.println("Hi, I'm going to send message!");
 
  mySerial.println("Hello, world?");
    display.clearBuffer();
  display.drawStr(10, 10, "ESP32C3");
  display.sendBuffer();
  delay(1000);
}

void loop() {
    char c;
  if (mySerial.available()) {
    Serial.write(c= mySerial.read());
/*     digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  digitalWrite(LED_BUILTIN,HIGH );    // turn the LED off by making the voltage LOW
*/

 if(ligne++ > characteres){

      display.clearBuffer();
      
 //   display.clearDisplay();
//      display.setTextSize(1);
//  display.setTextColor(SSD1306_WHITE);
//  display.setCursor(0,0);

  ligne = 0;
 } 
  if(c == 32) display.print(c) ; else { // " "
//    display.printf("%02X", c);
  };
  
 
  //display.print(c);
  // display.display();
  
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
      if (millis() - lastQuery > queryInterval) {
    lastQuery = millis();
    mySerial.print(comptage++);mySerial.print(" ");
    if( comptage > 100 ) comptage = 0;// comptage 99 max
  }

}
