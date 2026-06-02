
import tkinter as tk
import serial
import threading

PORT = '/dev/ttyUSB0'


class E22RSSI:
    def __init__(self):
        self.ser = serial.Serial(PORT, 9600, timeout=1)  # À adapter
        self.root = tk.Tk()
        self.root.title("E22 RSSI")
        self.label = tk.Label(self.root, text="RSSI: -- dBm", font=('Arial', 24))
        self.label.pack(padx=20, pady=20)
        self.update_rssi()

    def update_rssi(self):
        if self.ser.in_waiting >= 4:
            data = self.ser.read(4)
            if data[0] == 0xC0:
                rssi_raw = data[2]
                rssi_dbm = (rssi_raw - 256) / 1.6
                self.label.config(text=f"RSSI: {rssi_dbm:.1f} dBm")
        self.root.after(100, self.update_rssi)

    def run(self):
        self.root.mainloop()
        self.ser.close()

if __name__ == "__main__":
    app = E22RSSI()
    app.run()
