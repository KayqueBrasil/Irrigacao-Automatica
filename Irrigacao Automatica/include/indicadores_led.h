#ifndef INCIDADORES_LED_H
#define INCIDADORES_LED_H

// Protótipo da função para configurar os pinos dos LEDs indicadores
void ativarLedsIndicadores();


/*
Protótipos das funções para controlar os LEDs indicadores de acordo com o CM
do sensor ultrassônico:
*/

void atualizarLedVerde();
void atualizarLedAmarelo();
void atualizarLedVermelho();
void atualizarLedLaranja();

#endif