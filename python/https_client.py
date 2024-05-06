import socket
import ssl

HOST = '0.0.0.0'  # Endereço IP do servidor
PORT = 4210        # Porta HTTPS

# Configura o socket TCP/IP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen(5)

print(f"Aguardando conexões em {HOST}:{PORT}")

while True:
    # Aceita a conexão
    client_socket, client_address = server_socket.accept()
    print(f"Conexão estabelecida com {client_address}")

    # Configura o contexto SSL
    context = ssl.create_default_context(ssl.Purpose.CLIENT_AUTH)
    context.load_cert_chain(certfile="cert.pem", keyfile="key.pem")  # Certificado SSL/TLS e chave privada

    # Wrap do socket para usar SSL
    ssl_client_socket = context.wrap_socket(client_socket, server_side=True)

    # Recebe os dados do cliente
    data = ssl_client_socket.recv(1024)
    if data:
        print(f"Dados recebidos: {data.decode()}")

    # Fecha a conexão com o cliente
    ssl_client_socket.close()
