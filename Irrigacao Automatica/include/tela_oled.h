#ifndef TELA_OLED_H
#define TELA_OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Classe para gerenciar o display OLED
class TelaOLED {
public:
    TelaOLED();
    void inicializar();
    void exibirMensagem(const char* mensagem);
    void exibirValor(const char* label, long valor);
    void exibirDoisValores(const char* label1, long valor1, const char* label2, long valor2);
    void limparTela();
private:
    Adafruit_SSD1306 display;
};

#endif // TELA_OLED_H