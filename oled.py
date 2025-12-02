from machine import Pin, I2C
import ssd1306
import time

# Configurer la communication I2C
gnd = Pin(5, Pin.OUT)
plus = Pin(6, Pin.OUT)
plus.value(1)
gnd.value(0)

i2c = I2C(0, sda=Pin(8), scl=Pin(7))
#i2c = I2C(0, sda=Pin(4), scl=Pin(3))

# Configurer l'écran OLED (128x64 pixels) sur le bus I2C
# SSD1306_I2C est une sous-classe de FrameBuffer. FrameBuffer fournit un support pour les primitives graphiques.
# http://docs.micropython.org/en/latest/pyboard/library/framebuf.html
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

# Effacer l'écran en le remplissant de blanc, puis afficher la mise à jour
oled.fill(1)
oled.show()
time.sleep(1)  # Attendre 1 seconde

# Effacer l'écran à nouveau en le remplissant de noir
oled.fill(0)
oled.show()
time.sleep(1)  # Attendre encore une seconde

# Afficher du texte sur l'écran OLED
oled.text('Hello,', 0, 0)  # Afficher "Hello," à la position (0, 0)
oled.text('ANUMBY', 0, 16)  # Afficher "sunfounder.com" à la position (0, 16)

# La ligne suivante envoie ce qu'il faut afficher à l'écran
oled.show()
