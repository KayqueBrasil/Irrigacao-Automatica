#include <Arduino.h>
#include <config.h>

// Função para ativar o relé da bomba
void iniciarReleBomba(){ 
    pinMode(RELE_BOMBA, OUTPUT); // Configura o pino do relé como saída
}

// Função para ligar a bomba
void ligarBomba(bool estado){
    digitalWrite(RELE_BOMBA, estado); // Ativa o relé (liga ou desliga a bomba)
}