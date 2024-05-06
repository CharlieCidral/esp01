import socket

# Configurações do servidor
UDP_IP = "0.0.0.0"  # O servidor escutará em todas as interfaces disponíveis
UDP_PORT = 4210

# Criação do socket UDP
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print("Servidor UDP iniciado")

while True:
    data, addr = sock.recvfrom(1024)  # Tamanho máximo do buffer é 1024 bytes
    print("Mensagem recebida:", data.decode())
