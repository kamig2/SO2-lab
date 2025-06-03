import socket
import threading

HOST = '0.0.0.0'
PORT = 12345

clients = []

def handle_client(client_socket, addr):
    print(f"[NOWY UŻYTKOWNIK] {addr} dołączył.")
    clients.append(client_socket)

    while True:
        try:
            msg = client_socket.recv(1024).decode()
            if not msg:
                break
            broadcast(f"{addr}: {msg}", client_socket)
        except:
            break

    print(f"[ROZŁĄCZONO] {addr}")
    clients.remove(client_socket)
    client_socket.close()

def broadcast(message, sender_socket):
    for client in clients:
        if client != sender_socket:
            try:
                client.sendall(message.encode())
            except:
                pass

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
    server.bind((HOST, PORT))
    server.listen()
    print(f"[START] Serwer czatu działa na porcie {PORT}...")

    while True:
        client_socket, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(client_socket, addr))
        thread.start()
