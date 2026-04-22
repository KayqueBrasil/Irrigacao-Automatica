#include <Arduino.h>
#include <config.h>

// Função para configurar os pinos dos LEDs como saída
void ativarLedsIndicadores() {
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_LARANJA, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
}

/*
Função para atualizar os LEDs indicadores com base na distância medida
- LED_VERMELHO: Indica que o nível de água está crítico (distância muito alta).
- LED_LARANJA: Indica que o nível de água está baixo (distância alta).
- LED_AMARELO: Indica que o nível de água está moderado (distância média).
- LED_VERDE: Indica que o nível de água está adequado (distância baixa).
*/
void atualizarLedVermelho(){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
}
void atualizarLedLaranja(){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_LARANJA, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
}
void atualizarLedAmarelo(){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, LOW);
}
void atualizarLedVerde(){
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, LOW);
}