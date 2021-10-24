import socket
import threading

HOST = '127.0.0.1'
PORT = 5500

server =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))

server.listen()

clients = []
nicknames = []

#broadcast
def broadcast(message):
    for client in clients:
        client.send(message)

#handle
def handle(client):
    while True:
        try:
            message = client.recv(1024)
            print("{} says {}".format(nicknames[clients.index(client)],message))
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            nicknames.remove(nickname)
            break





#receive
def receive():
    while True:
        client, address = server.accept()
        print("Connected with {}".format(str(address)))

        client.send("NICK".encode('utf-8'))
        nickname = client.recv(1024)

        nicknames.append(nickname)
        clients.append(client)

        print("Nickname of the client is {}".format(nickname))
        broadcast("{} Connected to the server\n".format(nickname).encode('utf-8'))
        client.send("Connected to the server".encode('utf-8'))

        thread = threading.Thread(target=handle, args=(client,))  #comma to make this a tuple 
        thread.start()

print("Server running....")
receive()
