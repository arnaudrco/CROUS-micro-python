# S3 zero

Tester la mémoire, le fonctionnement audio en mode I2S ? Pas facile de comprendre pourquoi certaines options sont indispensables ; j'ai pris un exemple avec un banc de test webradio avec une sortie sur une prise de type écouteur pour brancher sur un lecteur de CD. 

<img width="492" height="511" alt="image" src="https://github.com/user-attachments/assets/4dd60450-a2f4-4af3-82b3-b6afb220cf8b" />

## materiel 

esp32S3 Zero 
jack PCM5100 



// TEST  sur carte S3 Zero, le 1/1/2026 ArnaudRCO
//  options outils > partition > HUGE APP et SPRAM > QSPI
// Source :  https://www.xtronical.com/i2sinternetradio/
// IDE Arduino 2.3.4
// Core  ESP32 d'Espressif en version 3.1.0  
// Bibliothèque : https://github.com/schreibfaul1/ESP32-audioI2S  ( en VERSION  3.0.12)


