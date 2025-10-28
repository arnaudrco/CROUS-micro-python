import machine, neopixel
from time import sleep_ms

print("test NEO")

n = 1    # number of pixels in your strip
p = 21   # GPIO number that will control the strip

np = neopixel.NeoPixel(machine.Pin(p), n)

# Flashes three times in the order of Red, Green, and Blue for 0.5 seconds each, then turns off.
for i in range(1):
    np[0] = (255, 0, 0)  # red
    np.write()
    sleep_ms(500)
    np[0] = (0, 0, 255)  # green
    np.write()
    sleep_ms(500)
    np[0] = (0, 255, 0)  # blue
    np.write()
    sleep_ms(500)
    np[0] = (255, 255, 0)  # red
    np.write()
    sleep_ms(500)
    np[0] = (255, 0, 255)  
    np.write()
    sleep_ms(500)
    np[0] = (0, 255, 255)  
    np.write()
    sleep_ms(500)

np[0] = (0, 0, 0)  # clear
np.write()