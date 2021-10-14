# servomoteur sur pin D4 (GPIO 2 )

from machine import Pin, PWM
import time


servo = PWM(Pin(2), freq=50, duty=77)

time.sleep(1)

#servo.duty(30) butée basse 0°
#servo.duty(122) butée haute 180°

while True:
    servo.duty(30)
    time.sleep(1)
    servo.duty(130)
    time.sleep(1)


