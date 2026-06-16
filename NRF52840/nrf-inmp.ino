/*

Câblage nRF52840 ProMicro <-> INMP441 I2S

VDD 3V3 3.3V uniquement
GND GND Masse
SD  P0.25 I2S DIN  >>
WS  P0.24 I2S LRCLK >> 
SCK P0.23 I2S SCLK  >> 24
L/R GND Canal gauche.  ( ou VDD pour droit)

 */
#define CLK 20
#define DOUT 22
#define WS 24

#include <bluefruit.h>
#include <PDM.h>

BLEDis bledis;
BLEUart bleuart;

int i;

void setup() {
  Serial.begin(115200);
pinMode(LED_BUILTIN, OUTPUT);
  Bluefruit.begin();
  Bluefruit.setName("Micro-nRF52");

  bledis.setManufacturer("DIY");
  bledis.setModel("INMP441");
  bledis.begin();

  bleuart.begin();

  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addService(bleuart);
  Bluefruit.ScanResponse.addName();
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
  
  Serial.println("NRF52840 ");

       digitalWrite(LED_BUILTIN, LOW);
    // wait for 30 milliseconds to see the dimming effect
    delay(500);
       digitalWrite(LED_BUILTIN, HIGH);
    // wait for 30 milliseconds to see the dimming effect
    delay(500);
       digitalWrite(LED_BUILTIN, LOW);
    // wait for 30 milliseconds to see the dimming effect
    delay(500);
       digitalWrite(LED_BUILTIN, HIGH);
    // wait for 30 milliseconds to see the dimming effect
    delay(500);

  PDM.onReceive(onPDMdata);
  PDM.setBufferSize(512);
  // P0.23 = CLK, P0.25 = DOUT, P0.24 = WS
 // PDM.setPins(23, 25, 24);

   PDM.setPins(CLK, DOUT, WS);
    
  if (!PDM.begin(1, 16000)) {
    Serial.println("PDM fail");
    while (1) fade();
     
  }
}

void onPDMdata() {
  int bytesAvailable = PDM.available();
  char sampleBuffer[512];
  PDM.read(sampleBuffer, bytesAvailable);
  if (Bluefruit.connected()) {
    bleuart.write(sampleBuffer, bytesAvailable);
  }
}

void loop() {
  fade();  
  Serial.println(i++);
}

void fade() { // fade pour LED_RED
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_BUILTIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_BUILTIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
