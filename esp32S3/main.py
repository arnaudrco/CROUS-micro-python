
import network
import socket
#import camera
import time

# Config AP
SSID = 'ESP32-CAM-AP'
PWD = '12345678'
IP = '192.168.1.1'

# Config caméra
#camera.init(0, d0=5, d1=6, d2=7, d3=15, d4=16, d5=18, d6=8, d7=3,
#            xclk=39, pclk=21, vsync=47, href=42, si_d=11, si_clk=40,
#            format=camera.JPEG, framesize=camera.FRAME_VGA, xclk_freq=20000000)

# Démarre AP
ap = network.WLAN(network.AP_IF)
ap.active(True)
ap.config(essid=SSID, password=PWD)
ap.ifconfig((IP, '255.255.255.0', IP, IP))
print(f'AP actif: {ap.ifconfig()}')

# Serveur Web
def start_server():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((IP, 80))
    s.listen(5)
    print('Serveur démarré')

    while True:
        conn, addr = s.accept()
        request = conn.recv(1024).decode()
        if 'GET /stream' in request:
            conn.send('HTTP/1.1 200 OK\r\nContent-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n')
            while True:
                #frame = camera.capture()
                conn.send(b'--frame\r\nContent-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')
                time.sleep(0.05)  # ~20 FPS
        else:  # GET /
            #frame = camera.capture()
            conn.send('HTTP/1.1 200 OK\r\nContent-Type: image/jpeg\r\n\r\n')
            #conn.send(frame)
        conn.close()

start_server()
