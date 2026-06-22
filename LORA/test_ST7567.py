"""

SCL/SCK GPIO4   
SDA/MOSI GPIO6
RS/DC   GPIO5
RST GPIO7
CS  GPIO10

"""
from machine import Pin, SPI
from framebuf import FrameBuffer, MONO_VLSB
from ST7567 import ST7567

print("SPI init")
spi = SPI(1,
            baudrate=200_000,
            polarity=1,
            phase=1,
            sck=Pin(4),
            mosi=Pin(6)) # under 20Mhz is OK

print("LCD init")
lcd = ST7567(spi,
            dc=Pin(5),  # data/command
            cs=Pin(10),  # chipselect, likely not needed for a single SPI device
            rst=Pin(7), # reset
            contrast=0x1F)

print("Loop")
buffer = bytearray(128*64//8)
fb = FrameBuffer(buffer, 128, 64, MONO_VLSB)
counter = 0

while True:
    try:
        fb.fill(0)
        fb.text("*Sitronix ST7567*",0,0)
        fb.text(f"Temp: 23.{counter%99:02d}C", 0, 8)
        fb.text("RH:   67.89 %", 0, 16)
        fb.text("====----====----",0,24)
        fb.text("Temp: 21.09 C",0,32)
        fb.text("987.65 hPa",0,40)
        # Running line at screen bottom to test refresh rate
        fb.pixel( counter   %128,63,1)
        fb.pixel((counter+1)%128,63,1)
        fb.pixel((counter+2)%128,63,1)
        fb.pixel((counter+3)%128,63,1)
        fb.pixel((counter+4)%128,63,1)
        fb.pixel((counter+5)%128,63,1)
        fb.pixel((counter+6)%128,63,1)
        fb.pixel((counter+7)%128,63,1)

        lcd.show(buffer)
        counter += 1
    except KeyboardInterrupt:
        break