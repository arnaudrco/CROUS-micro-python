from machine import UART, Pin
led=Pin(8,Pin.OUT)

# UART1 pour ESP32-C3 : TX=GPIO21, RX=GPIO20 par défaut
# E220-900T : TX module -> RX ESP32, RX module -> TX ESP32
uart = UART(1, baudrate=9600, tx=21, rx=20)

time.sleep(1)  # Laisser le module démarrer

while True:
    uart.write('ANUMBY\n')
    print('Envoyé: Hello')
    time.sleep(1)
    led.value(0)
    uart.write('Bonjour\n')
    time.sleep(1)
    led.value(1)