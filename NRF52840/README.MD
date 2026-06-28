Attention sur certaine versions mise à jour bootloader nécessaire

https://github.com/arnaudrco/exemples/blob/main/NRF52/README.md

# [Banc-de-test-microphone-MEMS](https://github.com/anumby-source/jouets/wiki/Banc-de-test-microphone-MEMS)

<img width="386" height="382" alt="image" src="https://github.com/user-attachments/assets/c1c43792-d496-4627-805d-5bb1d8f4e4ea" />


# micro Bluetooth

micro Bluetooth avec une ProMicro nRF52840 + INMP441. C’est le combo classique pour un micro BLE audio.

1. Câblage nRF52840 ProMicro <-> INMP441 I2S

<img width="767" height="729" alt="image" src="https://github.com/user-attachments/assets/dd53284c-bb1d-4a0c-ab70-509071b39231" />

*INMP441*	*nRF52840 ProMicro*	*Note*
* VDD	3V3	3.3V uniquement
* GND	GND	Masse
* SD	P0.25	I2S DIN
* WS	P0.24	I2S LRCLK
* SCK	P0.23	I2S SCLK
* L/R	GND	Canal gauche. Mets à VDD pour droit

CODE nrf-inmp.ino
