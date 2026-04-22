#include <Arduino.h>
#include <tela_oled.h>
#include <Wire.h>
#include <config.h>

// Definições para o display OLED
#define SCREEN_WIDTH 128 // Largura do display OLED em pixels
#define SCREEN_HEIGHT 64 // Altura do display OLED em pixels
#define OLED_RESET     -1 // Reset pin # (ou -1 se compartilhado com o microcontrolador)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Implementação da classe TelaOLED
// Construtor que inicializa o display OLED com as dimensões e pino de reset definidos
TelaOLED::TelaOLED() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {
}

// Método para inicializar o display OLED
void TelaOLED::inicializar() {
    Wire.begin(SDA_PIN, SCL_PIN);// Inicializa a comunicação I2C com os pinos definidos

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   // Endereço I2C do display
        Serial.println(F("Falha na alocação do SSD1306"));
        for (;;);               // Loop infinito se a alocação falhar
    }

    display.clearDisplay();     // Limpa o buffer do display
    display.setTextSize(1);     // Define o tamanho do texto
    display.setTextColor(SSD1306_WHITE);    // Define a cor do texto
    display.setCursor(0, 0);    // Define a posição do cursor
    display.println(F("Sistema de monitoramento")); // Exibe mensagem de inicialização
    display.display();          // Atualiza o display para mostrar a mensagem
}

// Método para exibir uma mensagem no display OLED
void TelaOLED::exibirMensagem(const char* mensagem) {
    display.clearDisplay();     // Limpa o buffer do display
    display.setCursor(0, 0);    // Define a posição do cursor
    display.println(mensagem);  // Exibe a mensagem fornecida
    display.display();          // Atualiza o display para mostrar a mensagem
}

// Método para exibir um valor numérico com um rótulo no display OLED
void TelaOLED::exibirValor(const char* label, long valor) {
    display.clearDisplay();     // Limpa o buffer do display
    display.setCursor(0, 0);    // Define a posição do cursor
    display.print(label);       // Exibe o rótulo fornecido
    display.print(": ");        // Adiciona um separador entre o rótulo e o valor
    display.println(valor);     // Exibe o valor numérico fornecido
    display.display();          // Atualiza o display para mostrar o rótulo e o valor
}
void TelaOLED::exibirDoisValores(const char* label1, long valor1, const char* label2, long valor2) {
    display.clearDisplay();     // Limpa o buffer do display
    display.setCursor(0, 0);    // Define a posição do cursor
    display.print(label1);      // Exibe o primeiro rótulo fornecido
    display.print(": ");        // Adiciona um separador entre o rótulo e o valor
    display.println(valor1);    // Exibe o primeiro valor numérico fornecido

    display.print(label2);      // Exibe o segundo rótulo fornecido
    display.print(": ");        // Adiciona um separador entre o rótulo e o valor
    display.println(valor2);    // Exibe o segundo valor numérico fornecido

    display.display();          // Atualiza o display para mostrar os rótulos e os valores
}

void TelaOLED::limparTela() {
    display.clearDisplay();     // Limpa o buffer do display
    display.display();          // Atualiza o display para mostrar a tela limpa
}
