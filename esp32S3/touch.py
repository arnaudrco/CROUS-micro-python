# testé sur S3 super mini 
# la broche 48 sert à la fois pour la LED rouge et la couleur NEOPIXEL
from machine import TouchPad, Pin
import time
from machine import Pin
import time
led=Pin(48,Pin.OUT)
touch_pin = TouchPad(Pin(4, mode=Pin.IN))
threshold = 30000
while True:
    touch_value = touch_pin.read()
    print(touch_value)
    if touch_value > threshold:
        print("Fil touché")
        led.value(1)
    else:
        led.value(0)
    time.sleep_ms(500)
