import socket
import threading

SERVER_IP = '127.0.0.1' 
PORT = 12345

def receive_messages(sock):
    while True:
        try:
            msg = sock.recv(1024).decode()
            if msg:
                print(msg)
        except:
            print("[Błąd] Połączenie z serwerem utracone.")
            sock.close()
            break

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
    client.connect((SERVER_IP, PORT))
    print("[Połączono z serwerem czatu]")
    
    threading.Thread(target=receive_messages, args=(client,), daemon=True).start()

    while True:
        message = input()
        if message.lower() == "exit":
            break
        client.sendall(message.encode())
