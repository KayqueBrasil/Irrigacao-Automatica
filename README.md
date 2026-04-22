# ESP32 Irrigation System

Sistema de irrigação automatizado utilizando ESP32, com monitoramento de umidade do solo e controle inteligente de bomba d'água.

---

## Sobre o Projeto

Este projeto tem como objetivo automatizar o processo de irrigação, tornando-o mais eficiente e evitando falta de água no sistema.

O sistema realiza:
- Leitura da umidade do solo (simulada com potenciômetro)
- Monitoramento do nível de água com sensor ultrassônico
- Acionamento automático da bomba com base nos valores coletados

---

## Funcionalidades

- Leitura de umidade do solo via entrada analógica *(simulada com potenciômetro)*  
- Monitoramento do nível de água com sensor ultrassônico  
- Controle automático da bomba de água via relé  
- Feedback visual com LEDs de status  
- Exibição de dados em display OLED  
- Estrutura modular do código  

---

##  Tecnologias Utilizadas

- ESP32  
- C++ (Arduino Framework)  
- Display OLED (SSD1306)  
- Sensor Ultrassônico (HC-SR04)  
- Potenciômetro (simulação de sensor de umidade)  
- VS Code + PlatformIO  
- Wokwi (simulação) 

---

## 🔌 Estrutura do Projeto
include/
├── config.h
├── indicadores_led.h
├── rele_bomba.h
├── sensor.h
└── tela_oled.h

src/
├── indicadores_led.cpp
├── main.cpp
├── rele_bomba.cpp
├── sensor.cpp
└── tela_oled.cpp

---

##  Lógica de Funcionamento

1. O potenciômetro simula o nível de umidade do solo  
2. O sensor ultrassônico mede o nível de água no reservatório  
3. O sistema avalia o nível da água:
   - LEDs indicam o estado atual  
   - Caso esteja abaixo do mínimo → bloqueia operação  
4. O sistema verifica a umidade do solo:
   - Se abaixo do setpoint e houver água disponível → ativa a bomba  
5. A irrigação continua até:
   - A umidade atingir o valor ideal  
   - Ou o nível de água se esgotar  
6. Caso a água acabe, o sistema desliga a bomba e retorna ao monitoramento

---

## Possíveis Melhorias

- Integração com Wi-Fi para monitoramento remoto  
- Continuar regando de onde parou
- Uso de MQTT para comunicação IoT  
- Histórico de dados (log)  
- Controle manual via botão ou app  

---

## Como Executar

1. Abra o VS Code com a extensão PlatformIO  
2. Crie um projeto com a placa: DOIT ESP32 DEVKIT V1
3. Instale a biblioteca:
- Adafruit SSD1306  

4. Substitua as pastas:
- `include/`
- `src/`

5. Adicione na raiz do projeto:
- `wokwi.toml`
- `diagram.json`

6. Compile e execute o projeto  

---

## Demonstração
- Imagem do circuito:
<img width="1003" height="817" alt="image" src="https://github.com/user-attachments/assets/c3b2ae25-a100-41d7-b46f-343a299b59c9" />

- Video da simulação:
https://github.com/user-attachments/assets/23673a6b-ca18-46e4-b92b-b6aab421d53b

- Link Wokwi: https://wokwi.com/projects/462011896573960193

---

## Autor

- GitHub: https://github.com/KayqueBrasil  
- LinkedIn: https://www.linkedin.com/in/kayque-brasil  
---
