# Controle Remoto com ESP8266 e Capacitive Touch
Este projeto visa criar um controle remoto utilizando um módulo ESP8266 (ESP01) e sensores de toque capacitivo. Ele permite enviar informações do ESP8266 para um computador usando Wi-Fi e UDP (User Datagram Protocol), e recebe essas informações em um programa Python.

### Funcionamento
O ESP8266 está configurado para ler o estado de dois sensores de toque capacitivo e enviar esses estados para um computador por meio de mensagens UDP. Quando um dos sensores é acionado, uma mensagem indicando qual sensor foi acionado é enviada para o endereço IP especificado na rede local.

O programa Python aguarda essas mensagens UDP e as exibe no console. Ele também mantém uma lista de endereços IP dos clientes que se conectaram ao servidor.

### Pré-requisitos
- Arduino IDE ou plataforma semelhante para programar o ESP8266.
- Conhecimento básico de Arduino e programação em Python.
- Módulo ESP8266 (ESP01) com capacidade Wi-Fi.
- Sensores de toque capacitivo.
- Uma rede Wi-Fi para conectar o ESP8266 e o computador.
### Configuração do Hardware
1. Conectar os sensores de toque capacitivo ao ESP8266.
2. Conectar o ESP8266 à rede Wi-Fi local.
### Configuração do Software
#### ESP8266 (send.ino)
1. Substitua as constantes ssid, password e host com as informações da sua rede Wi-Fi e o endereço IP do computador que receberá as mensagens UDP.
2. Verifique e faça o upload do código para o ESP8266.
#### Python (receive.py)
1. Substitua UDP_IP e UDP_PORT com o endereço IP e porta em que o ESP8266 está enviando as mensagens UDP.
2. Execute o script Python.
### Uso
1. Após a configuração do hardware e do software, acione os sensores de toque capacitivo.
2. As mensagens indicando qual sensor foi acionado serão exibidas no console Python.
### Links uteis
[Datasheet wifi-module](https://www.microchip.ua/wireless/esp01.pdf)
[Datasheet ESP8266EX](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf)
[Input usage](https://electronics.stackexchange.com/questions/347396/esp8266-gpio0-or-gpio2-as-input)
[Input/Output usage](https://embarcados.com.br/configurando-gpio-do-esp8266-01/#GPIO0-e-GPIO2-como-Input)
### Avisos
Os arquivos testados com os componentes de hardware foram: send.ino e receive.py, os demais arquivos foram apenas para fins de aprendizado e testes. Ou seja, este projeto ainda está em fase de desenvolvimento e pode conter bugs ou falhas. Recomenda-se revisar e ajustar o código conforme necessário antes de utilizá-lo em produção.
