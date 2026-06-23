# afficher avec python sur écran 128 x 64

<img width="394" height="567" alt="image" src="https://github.com/user-attachments/assets/7e2c844a-3bae-4376-81d4-c32ce8a9756f" />

CODE : ST7567.py et test_ST7567.py

# Balise en Python

<img width="400" height="415" alt="image" src="https://github.com/user-attachments/assets/2a0125a2-dd0f-40ac-99a9-e4fa95537eb4" />

Balise Python avec module LORA LR30

UART1 pour ESP32-C3 : TX=GPIO21, RX=GPIO20 par défaut
E220-900T : TX module -> RX ESP32, RX module -> TX ESP32
uart = UART(1, baudrate=9600, tx=21, rx=20)

CODE hello.py

# afficher sur écran lcd 128x64

Ce n'est pas encore la fonction "feed" ; 1 ligne reste en mode inversé et 7 lignes sont affichées

<img width="585" height="609" alt="image" src="https://github.com/user-attachments/assets/960550c8-7c1c-4873-b631-ce22f265f434" />

12864-c3-hello-print.ino

# Balise 12864 avec esp8266

<img width="607" height="590" alt="image" src="https://github.com/user-attachments/assets/b31d8982-db14-47f6-b099-8f4bca3ee4db" />

12864-esp-tab.ino

# balise réalisée avec un c3


- ESP32-C3 | ST7567A
- GPIO6 | SCK
- GPIO7 | MOSI
- GPIO4 | CS
- GPIO5 | DC
- GPIO3 | RST
- 3V3 | VCC
- GND | GND


<img width="554" height="617" alt="image" src="https://github.com/user-attachments/assets/6e9af0b1-67e1-49f0-a98f-c7b2e6fbf39c" />

12864-c3-balise.ino


# qualité de transmission (RSSI) pour LLCC68

code pour balise avec RSSI

il faut un fil de mise à zero M0 et M1 pour les modules EBYTE 

<img width="347" height="588" alt="image" src="https://github.com/user-attachments/assets/88fb0eff-8f93-4201-beb7-307c220f5518" />


une balise affichant la qualité de la transmission (RSSI) ; pour les modules DX SMART (LR22 ici) il n'est pas nécessaire de shunter M0 M1

<img width="903" height="655" alt="image" src="https://github.com/user-attachments/assets/1290427f-c84a-46b5-b710-abea32ef6f98" />

# Autres modèles

Balises réalisées sur https://github.com/arnaudrco/exemples/blob/main/LORA-blink/README.md

