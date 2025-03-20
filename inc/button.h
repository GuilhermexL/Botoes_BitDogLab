#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h"

// Definição dos pinos dos botões
#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6

// Tempo de debounce em milissegundos
#define DEBOUNCE_TIME_MS 50

// Variável para armazenar o tempo da última interrupção
static volatile uint32_t last_interrupt_time = 0;

// Inicializa os botões
void button_init(uint button_pin);

// Lê o estado de um botão (retorna true se pressionado, false caso contrário)
bool button_read(uint pin);

// Verifica se o botão foi pressionado (detecção de borda de descida)
bool button_pressed(uint pin);

// Verifica se o botão foi solto (detecção de borda de subida)
bool button_released(uint pin);

// Aguarda até que um botão seja pressionado (bloqueante)
void button_wait_press(uint pin);

// Configura uma interrupção no botão
void button_callback(uint gpio, uint32_t events);

#endif
