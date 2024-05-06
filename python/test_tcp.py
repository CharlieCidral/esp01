import socket

ip = "192.168.0.28"
port = 4210

addr = (ip, port)
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(addr)
server_socket.listen(5)  # Permite até 5 conexões simultâneas

print("Aguardando conexões...")

while True:
    client_socket, client_addr = server_socket.accept()
    print(f"Conexão estabelecida com {client_addr}")

    while True:
        data = client_socket.recv(1024)  # Recebe os dados
        if not data:
            break
        print(f"Dados recebidos: {data.decode()}")

    print(f"Conexão com {client_addr} encerrada")
    client_socket.close()
