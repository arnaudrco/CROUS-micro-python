# Récepteur bluetooth avec esp32

CODE https://github.com/anumby-source/jouets/blob/main/a2dp-i2s/README.MD

<img width="249" height="328" alt="image" src="https://github.com/user-attachments/assets/29a3d41a-9778-4663-8314-1f28cf3a3e3c" />

ATTENTION La dernière broche (SCK) doit être à GND. Pour comprendre le fonctionnement, voici un montage avec 2 composants esp32 et un lecteur PCM5100 soudé sur un connecteur femelle

<img width="644" height="554" alt="image" src="https://github.com/user-attachments/assets/bfb2782a-65ba-4758-abd0-3cf22bb7e120" />

le montage est réalisé en montant mal <> femelle

<img width="310" height="314" alt="image" src="https://github.com/user-attachments/assets/35eb8d4b-0b39-405d-8306-2b49f69c2e07" />


ESP Pin	I2S Signal	PCM5102 Pin
* GPIO15	LRCK	LRCK
* GPIO2	DATA	DIN
* GPIO4	BCK	BCK

# Visualiser le son

vers une LED ou un baregraph 

<img width="504" height="351" alt="image" src="https://github.com/user-attachments/assets/15dd341f-2e47-40a7-b184-4fe6b164ec10" />
  
affiche l'amplitude du son (rms) 

<img width="166" height="163" alt="image" src="https://github.com/user-attachments/assets/7e56b3a8-7373-45b7-af70-72d8b8d58120" />

# lire depuis une source BT

A finir : le programme donne seulement du bruit  ; j'utilise la librairie A2DP source et sink

xxxx-a2dp.ino


