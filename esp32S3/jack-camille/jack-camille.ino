// TEST  sur carte S3 Zero, le 1/1/2026 ArnaudRCO
//  options outils > partition > HUGE APP et SPRAM > QSPI
// Source :  https://www.xtronical.com/i2sinternetradio/
// IDE Arduino 2.3.4
// Core  ESP32 d'Espressif en version 3.1.0  
// Bibliothèque : https://github.com/schreibfaul1/ESP32-audioI2S  ( en VERSION  3.0.12)
// version avec led rouge = pas de connexion 




#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <Adafruit_NeoPixel.h>

#define PIN        21 // Which pin on the Arduino is connected to the NeoPixels?
Adafruit_NeoPixel pixels(1, PIN, NEO_GRB + NEO_KHZ800);
/* GPIOs utilisés ici pour l'ampli BF I2S  MAX98357A, autres choix possibles
#define I2S_DOUT      10  // DIN connection 
#define I2S_BCLK      11  // Bit clock 
#define I2S_LRC       12  // Left Right Clock

#define GND  13
#define I2S_LRC  12
#define I2S_DOUT  11
#define I2S_BCLK 10
#define SCK  9


*/



#define I2S_LRC  2
#define I2S_DOUT  3
#define I2S_BCLK 4
#define SCK  5 

Audio audio;



//gets called when WiFiManager enters configuration mode
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
  //entered config mode, make led toggle faster

}


void connectWifi() {
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  WiFiManager wm;
  wm.setAPCallback(configModeCallback);
  if (!wm.autoConnect()) {
    Serial.println("failed to connect and hit timeout");

    pixels.setPixelColor(0, pixels.Color(150, 0, 0)); // rouge
    pixels.show();   // Send the updated pixel colors to the hardware.
    
          delay(1000);
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();

  }
  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

      pixels.setPixelColor(0, pixels.Color(0, 150, 0)); // vert
    pixels.show();   // Send the updated pixel colors to the hardware.

} 

void setup() {


        pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
      pixels.setPixelColor(0, pixels.Color(0, 0, 150)); // bleu
    pixels.show();   // Send the updated pixel colors to the hardware.
    
       delay(100);
  
 // pinMode(GND, OUTPUT); // board prise jack" "PCM5100" GND
  // digitalWrite(GND, LOW);
  pinMode(SCK, OUTPUT); // board prise jack" "PCM5100" GND
  digitalWrite(SCK, LOW);
  delay(100);
  
  Serial.begin(115200);
   connectWifi();
  /*
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED) delay(1500); */
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(6); // 0...21

  audio.connecttohost("https://icecast.radiofrance.fr/monpetitfranceinter-midfi.aac");

  //audio.connecttohost("http://icecast.radiofrance.fr/fipjazz-midfi.mp3");
  //audio.connecttohost("http://icecast.radiofrance.fr/fipworld-midfi.mp3");
  //audio.connecttohost("http://icecast.radiofrance.fr/fip-midfi.mp3");
  //audio.connecttohost("http://icecast.radiofrance.fr/franceinfo-midfi.mp3");
  //audio.connecttohost("http://tsfjazz.ice.infomaniak.ch/tsfjazz-high.mp3");
}


void loop()
{
  audio.loop();
}
