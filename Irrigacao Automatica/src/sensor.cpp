#include <Arduino.h>
#include <config.h>

// Função para ativar o sensor ultrassônico
void ativarSensorUltrassonico(){
    // Configura os pinos do sensor ultrassônico
    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);
}

// Função para medir a distância usando o sensor ultrassônico
long medirDistancia(){
    // Envia um pulso de 10 microsegundos para o pino de trigger
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);

    // Lê o tempo do pulso de retorno no pino de echo
    long duration = pulseIn(ECHO, HIGH);

    // Calcula a distância em centímetros (velocidade do som é aproximadamente 343 m/s)
    long distance = duration * 0.034 / 2;

    return distance;
}

// Função para medir a umidade usando o potenciômetro
float medirUmidade() {
    // Lê o valor analógico do potenciômetro
    int valorAnalogico = analogRead(POT_UMIDADE);

    // Converte o valor analógico para um valor de umidade (0 a 100%)
    float umidade = (valorAnalogico / 4095.0) * 100.0;

    return umidade;
}