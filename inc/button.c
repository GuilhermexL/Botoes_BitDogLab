#include "button.h"
#include <stdio.h>

// Variáveis para armazenar o último estado e o tempo da última mudança de estado
static bool last_state[BUTTON_B_PIN + 1] = {false};
static uint32_t last_time[BUTTON_B_PIN + 1] = {0};

// Inicializa o botão no pino especificado
void button_init(uint button_pin)
{
    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_IN);
    gpio_pull_up(button_pin);
}

// Lê o estado de um botão (retorna true se pressionado, false caso contrário)
bool button_read(uint pin) {
    return !gpio_get(pin);  // Retorna true se o botão estiver pressionado (LOW)
}

// Verifica se o botão foi pressionado (detecção de borda de descida com debounce)
bool button_pressed(uint pin) {
    bool current_state = button_read(pin);
    uint32_t now = to_ms_since_boot(get_absolute_time());

    if (current_state && !last_state[pin] && (now - last_time[pin] > DEBOUNCE_TIME_MS)) {
        last_state[pin] = current_state;
        last_time[pin] = now;
        return true;
    }

    last_state[pin] = current_state;
    return false;
}

// Verifica se o botão foi solto (detecção de borda de subida com debounce)
bool button_released(uint pin) {
    bool current_state = button_read(pin);
    uint32_t now = to_ms_since_boot(get_absolute_time());

    if (!current_state && last_state[pin] && (now - last_time[pin] > DEBOUNCE_TIME_MS)) {
        last_state[pin] = current_state;
        last_time[pin] = now;
        return true;
    }

    last_state[pin] = current_state;
    return false;
}

// Aguarda até que um botão seja pressionado (bloqueante)
void button_wait_press(uint pin) {
    while (!button_read(pin)) {
        sleep_ms(10);  // Espera 10 ms para evitar leituras excessivas
    }
}

// Callback de interrupção para detecção de borda
void button_callback(uint gpio, uint32_t events) {
    uint32_t now = to_ms_since_boot(get_absolute_time());

    // Verifica se o tempo desde a última interrupção é maior que o tempo de debounce
    if ((now - last_interrupt_time) > DEBOUNCE_TIME_MS) {
        if (events & GPIO_IRQ_EDGE_FALL) {
            printf("Botão no GPIO %d foi pressionado com interrupção!\n", gpio);
        }
        last_interrupt_time = now;  // Atualiza o tempo da última interrupção
    }
}