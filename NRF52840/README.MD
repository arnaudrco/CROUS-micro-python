Attention sur certaine versions mise à jour bootloader nécessaire

https://github.com/arnaudrco/exemples/blob/main/NRF52/README.md

# faire clignoter une LED

nrf-fading.ino

<img width="484" height="410" alt="image" src="https://github.com/user-attachments/assets/1cceb750-d7da-4af1-a1bf-55912345f029" />

pas facile à utiliser ; beaucoup d'essais infructueux notés dans les forums ; j'ai écrit un test pour faire clignoter une simple LED :

* pin 1 0.24
* pin 2 0.10
* pin 3 1.15 

# [Banc-de-test-microphone-MEMS](https://github.com/anumby-source/jouets/wiki/Banc-de-test-microphone-MEMS)

<img width="386" height="382" alt="image" src="https://github.com/user-attachments/assets/c1c43792-d496-4627-805d-5bb1d8f4e4ea" />


# micro Bluetooth

nrf-inmp.ino

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

 


