import time
from machine import I2C, Pin, ADC
from LCD_Display import LcdApi, I2CLcd

"""LCD Section"""
i2c = I2C(0, sda=Pin(8), scl=Pin(9), freq=400000) 
lcd = I2CLcd(i2c, 0x27, 4, 20)

lcd.putstr("Demo Drone ANUMBY")
lcd.move_to(0, 1)
lcd.putstr("ESP32-C3 OK!")


# init ADC
adc0 = ADC(0, atten=ADC.ATTN_11DB)
adc1 = ADC(1, atten=ADC.ATTN_11DB)


lcd.topdata("Demo Drone ANUMBY") #Starts the top data line
time.sleep(1)

while True:
    # Lire ADC
    val0 = adc0.read()
    val1 = adc1.read()
    lcd.move_to(0, 2)
    lcd.putstr("X:" + str(val0))
    lcd.move_to(0, 3)
    lcd.putstr("Y:" + str(val1))
    time.sleep(1)
