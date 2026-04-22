#include <Arduino.h>
#include <sensor.h>
#include <indicadores_led.h>
#include <rele_bomba.h>
#include <tela_oled.h>

TelaOLED tela;

bool statusRele = 0;

void setup() {
  Serial.begin(115200);
  // Funcoes para ativar o sensor ultrassônico, os LEDs indicadores, 
  // o relé da bomba e a tela OLED
  ativarSensorUltrassonico();
  ativarLedsIndicadores();
  iniciarReleBomba();

  // Inicialização da tela OLED
  tela.inicializar();
}

void loop() {
  // Leitura da umidade do potenciômetro
  float umidade = medirUmidade();

  // Leitura da distância do sensor ultrassônico
  long distancia = medirDistancia();

  if (distancia >= 200){
    atualizarLedVermelho(); // Acende o LED vermelho

    while (distancia >= 30) {
      distancia = medirDistancia(); // Atualiza a leitura da distância
      tela.exibirValor("Distancia", distancia); // Exibe a distância atualizada na tela OLED
      delay(1000); // Pequena pausa para evitar leituras muito rápidas
    }
  } else if (distancia < 200 && distancia > 100){
    atualizarLedLaranja(); // Acende o LED laranja

    // Exibe mensagem de alerta na tela OLED
    tela.exibirMensagem("Recipiente com pouca agua!");
    delay(1000); // Pequena pausa para evitar leituras muito rápidas

  } else if (distancia <= 100 && distancia > 30){
    atualizarLedAmarelo(); // Acende o LED amarelo

    // Exibe mensagem de alerta na tela OLED
    tela.exibirMensagem("Recipiente com agua suficiente!");
    delay(1000); // Pequena pausa para evitar leituras muito rápidas

  }else if (distancia <= 30){
    atualizarLedVerde(); // Acende o LED verde

    // Exibe mensagem de alerta na tela OLED
    tela.exibirMensagem("Recipiente cheio!");
    delay(1000); // Pequena pausa para evitar leituras muito rápidas
  }

   // Exibe umidade e distância na tela OLED
  tela.exibirDoisValores("Umidade", umidade, "Distancia", distancia); 
  delay(1500); // Pequena pausa para evitar leituras muito rápidas

  if (umidade <= 20.0 && distancia < 170) {
    // Se a umidade estiver abaixo do limite e o recipiente tiver água suficiente, liga a bomba
    statusRele = 1; // Liga a bomba

  } else {
    if (umidade > 20.0) {
      // Se a umidade estiver acima do limite, nao liga a bomba
      tela.exibirMensagem("Umidade alta, bomba nao liga!");

    } else if (distancia >= 170) {
      // se o recipiente estiver quase vazio, nao liga a bomba
      tela.exibirMensagem("Recipiente abaixo do nivel minimo, bomba nao liga!");
    }
    statusRele = 0; // Desliga a bomba
    delay(1500); // Pequena pausa para evitar leituras muito rápidas
  }

  // Saida Centralizada para controle da bomba de água
  ligarBomba(statusRele); // Liga ou desliga a bomba com base no status do relé
  if (statusRele) {
    while (umidade < 85.0) {
      umidade = medirUmidade(); // Atualiza a leitura da umidade
      distancia = medirDistancia(); // Atualiza a leitura da distância

      tela.exibirValor("Umidade", umidade); // Exibe a umidade atualizada na tela OLED
      delay(1000); // Pequena pausa para evitar leituras muito rápidas

      if (distancia >= 200) {
        // se o recipiente estiver quase vazio, desliga a bomba
        tela.exibirMensagem("Recipiente abaixo do nivel minimo, adicione agua!");
        ligarBomba(0); // Desliga a bomba
        break; // Sai do loop para evitar que a bomba continue ligada
      }
    }  
  }
  

  // Impressão da distância medida no monitor serial para depuração
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Impressão do status da bomba no monitor serial para depuração
  Serial.print("Status da Bomba: ");
  Serial.println(statusRele ? "Ligada" : "Desligada");

  // Pequena pausa para evitar leituras muito rápidas
  delay(1000);
}
