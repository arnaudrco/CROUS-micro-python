// Balise toutes les 2 secondes
#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // Configuration des broches TX et RX


  
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);   // Communication série avec l'ordinateur
  HC12.begin(9600);     

}

void loop() {
  digitalWrite(LED_BUILTIN, (millis()/1000)%2); 
  if (  (millis()/1000)%2 )   HC12.write("TEST 1234567890");

}
