/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses ROUGE to find the pin with the internal LED
*/
#define ROUGE 3
#define VERT 4
#define BLEU 5

#define ORANGE 18

#define BLANC 19

#define DELAY 100

void setup() {
  pinMode(ROUGE, OUTPUT);     // Initialize the ROUGE pin as an output
    pinMode(VERT, OUTPUT);     // Initialize the ROUGE pin as an output
     pinMode(BLEU, OUTPUT);     // Initialize the ROUGE pin as an output
      pinMode(BLANC, OUTPUT);     // Initialize the ROUGE pin as an output
          pinMode(ORANGE, OUTPUT);     // Initialize the ROUGE pin as an output
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(ROUGE, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(DELAY);   
  digitalWrite(ROUGE, LOW);   // Turn the LED on (Note that LOW is the voltage level
  delay(DELAY);  
  
  digitalWrite(VERT, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(DELAY);   
   digitalWrite(VERT, LOW);   // Turn the LED on (Note that LOW is the voltage level
  delay(DELAY); 

  digitalWrite(BLEU, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(DELAY);   
    digitalWrite(BLEU, LOW);  // Turn the LED off by making the voltage HIGH
  delay(DELAY); 

  
                    // Wait for a second
  digitalWrite(BLANC, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(DELAY);   

         digitalWrite(BLANC, LOW);   // Turn the LED on (Note that LOW is the voltage level
    delay(DELAY);
    digitalWrite(ORANGE, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(DELAY);   
      digitalWrite(ORANGE, LOW);   // Turn the LED on (Note that LOW is the voltage level
  delay(DELAY);  




  

}
