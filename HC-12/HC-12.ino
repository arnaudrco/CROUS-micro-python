#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // Configuration des broches TX et RX
int pot = A0;

void setup() {
  Serial.begin(9600);   // Communication série avec l'ordinateur
  HC12.begin(9600);     
  pinMode(pot, INPUT);
}

void loop() {
  int val = map(analogRead(pot), 0, 1024, 0, 255);
  HC12.write("TEST 1234567890");
  HC12.write(val);
  Serial.println(val);
}
