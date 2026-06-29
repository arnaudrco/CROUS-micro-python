/*
  RadioLib SX126x Settings Example

  This example shows how to change all the properties of LoRa transmission.
  RadioLib currently supports the following settings:
  - pins (SPI slave select, DIO1, DIO2, BUSY pin)
  - carrier frequency
  - bandwidth
  - spreading factor
  - coding rate
  - sync word
  - output power during transmission
  - CRC
  - preamble length
  - TCXO voltage
  - DIO2 RF switch control

  Other modules from SX126x family can also be used.

  For default module settings, see the wiki page
  https://github.com/jgromes/RadioLib/wiki/Default-configuration#sx126x---lora-modem

  For full API reference, see the GitHub Pages
  https://jgromes.github.io/RadioLib/
*/

// include the library
#include <RadioLib.h>

// Pins SX1262
#define NSS D0 // 15
#define DIO1 D1 // 5
#define RESET  D8 // 16
#define BUSY D2 // 4

SX1262 radio1 = new Module(NSS, DIO1, RESET, BUSY);

// or detect the pinout automatically using RadioBoards
// https://github.com/radiolib-org/RadioBoards
/*
#define RADIO_BOARD_AUTO
#include <RadioBoards.h>
Radio radio3 = new RadioModule();
*/

void setup() {
  Serial.begin(9600);

  Serial.print(F("[SX1262] Initializing ... "));
  int state = radio1.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) { delay(10); }
  }

  // initialize the second LoRa instance with
  // non-default settings
  // this LoRa link will have high data rate,
  // but lower range
 

  // you can also change the settings at runtime
  // and check if the configuration was changed successfully

  // set carrier frequency to 868 MHz
  if (radio1.setFrequency(868) == RADIOLIB_ERR_INVALID_FREQUENCY) {
    Serial.println(F("Selected frequency is invalid for this module!"));
    while (true) { delay(10); }
  }

  // set bandwidth to 250 kHz
  if (radio1.setBandwidth(250.0) == RADIOLIB_ERR_INVALID_BANDWIDTH) {
    Serial.println(F("Selected bandwidth is invalid for this module!"));
  //  while (true) { delay(10); }
  }

  // set spreading factor to 10
  if (radio1.setSpreadingFactor(12) == RADIOLIB_ERR_INVALID_SPREADING_FACTOR) {
    Serial.println(F("Selected spreading factor is invalid for this module!"));
 //   while (true) { delay(10); }
  }

  // set coding rate to 2
  if (radio1.setCodingRate(5) == RADIOLIB_ERR_INVALID_CODING_RATE) {
    Serial.println(F("Selected coding rate is invalid for this module!"));
 //   while (true) { delay(10); }
  }

  // set LoRa sync word to 0xAB
  if (radio1.setSyncWord(0xAB) != RADIOLIB_ERR_NONE) {
    Serial.println(F("Unable to set sync word!"));
    while (true) { delay(10); }
  }

  // set output power to 10 dBm (accepted range is -17 - 22 dBm)
  if (radio1.setOutputPower(22) == RADIOLIB_ERR_INVALID_OUTPUT_POWER) {
    Serial.println(F("Selected output power is invalid for this module!"));
    while (true) { delay(10); }
  }

  // set over current protection limit to 80 mA (accepted range is 45 - 240 mA)
  // NOTE: set value to 0 to disable overcurrent protection
  if (radio1.setCurrentLimit(80) == RADIOLIB_ERR_INVALID_CURRENT_LIMIT) {
    Serial.println(F("Selected current limit is invalid for this module!"));
    while (true) { delay(10); }
  }

  // set LoRa preamble length to 15 symbols (accepted range is 0 - 65535)
  if (radio1.setPreambleLength(15) == RADIOLIB_ERR_INVALID_PREAMBLE_LENGTH) {
    Serial.println(F("Selected preamble length is invalid for this module!"));
    while (true) { delay(10); }
  }

  // disable CRC
  if (radio1.setCRC(false) == RADIOLIB_ERR_INVALID_CRC_CONFIGURATION) {
    Serial.println(F("Selected CRC is invalid for this module!"));
    while (true) { delay(10); }
  }

  // Some SX126x modules have TCXO (temperature compensated crystal
  // oscillator). To configure TCXO reference voltage,
  // the following method can be used.
  if (radio1.setTCXO(2.4) == RADIOLIB_ERR_INVALID_TCXO_VOLTAGE) {
    Serial.println(F("Selected TCXO voltage is invalid for this module!"));
    while (true) { delay(10); }
  }

  // Some SX126x modules use DIO2 as RF switch. To enable
  // this feature, the following method can be used.
  // NOTE: As long as DIO2 is configured to control RF switch,
  //       it can't be used as interrupt pin!
  if (radio1.setDio2AsRfSwitch() != RADIOLIB_ERR_NONE) {
    Serial.println(F("Failed to set DIO2 as RF switch!"));
    // while (true) { delay(10); }
  }

  Serial.println(F("All settings succesfully changed!"));
}

void loop() {
  // nothing here
}
