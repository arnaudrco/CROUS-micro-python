#!/usr/bin/env python3
"""
Auto-répondeur LXMF pour test de distance Reticulum.
Répond "OK" + RSSI/SNR à chaque message reçu.
L'identité est sauvegardée pour garder le même hash entre les relances.
S'annonce sur le réseau au démarrage et toutes les 15 minutes.

Usage :
  1. Lancer rnsd dans un terminal
  2. Lancer ce script dans un autre terminal
"""

import sys
sys.stdout.reconfigure(line_buffering=True)

import RNS
import LXMF
import time
import os
import threading

DISPLAY_NAME   = "Pi zero V1.3-AutoRep"
IDENTITY_PATH  = os.path.expanduser("~/.config/lxmf_autoresponder_identity")
ANNOUNCE_EVERY = 900  # secondes (15 minutes)

local_destination = None
router = None

def message_received(message):
    rssi = message.rssi if hasattr(message, 'rssi') and message.rssi else "?"
    snr  = message.snr  if hasattr(message, 'snr')  and message.snr  else "?"

    print(f"\n[RX] Message reçu de : {RNS.prettyhexrep(message.source_hash)}")
    print(f"     Contenu : {message.content.decode('utf-8') if message.content else '(vide)'}")
    contenu =  message.content.decode('utf-8') if message.content else '(vide)'
    print(f"     RSSI : {rssi} dBm  |  SNR : {snr} dB")

    reponse = LXMF.LXMessage(
        destination    = message.source,
        source         = local_destination,
        content        = f"OK | RSSI={rssi} dBm | SNR={snr} dB : {contenu}",
        title          = "Auto-repondeur : ACK",
        desired_method = LXMF.LXMessage.DIRECT,
    )
    router.handle_outbound(reponse)
    print(f"[TX] Réponse OK envoyée")

def announce_loop():
    while True:
        local_destination.announce()
        print(f"[ANN] Annonce envoyée sur le réseau")
        time.sleep(ANNOUNCE_EVERY)

def main():
    global router, local_destination

    RNS.Reticulum()

    # Charge l'identité existante ou en crée une nouvelle
    if os.path.exists(IDENTITY_PATH):
        identity = RNS.Identity.from_file(IDENTITY_PATH)
        print(f"Identité chargée depuis {IDENTITY_PATH}")
    else:
        identity = RNS.Identity()
        identity.to_file(IDENTITY_PATH)
        print(f"Nouvelle identité créée et sauvegardée dans {IDENTITY_PATH}")

    router = LXMF.LXMRouter(storagepath="/tmp/lxmf_autoresponder")
    router.register_delivery_callback(message_received)

    # register_delivery_identity retourne la destination LXMF
    local_destination = router.register_delivery_identity(identity, display_name=DISPLAY_NAME)

    print(f"Auto-répondeur LXMF démarré")
    print(f"Adresse LXMF : {RNS.prettyhexrep(local_destination.hash)}")
    print(f"En attente de messages... (Ctrl+C pour quitter)\n")

    # Lancer le thread d'annonce
    ann_thread = threading.Thread(target=announce_loop)
    ann_thread.daemon = True
    ann_thread.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nArrêt.")

if __name__ == "__main__":
    main()
