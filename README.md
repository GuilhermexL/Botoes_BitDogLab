# Projeto de Controle dos Botões na BitDogLab

<p align="center">
  <img src="images/VirtusCC.png" alt="Virtus">
</p>

## Autores

- [Aryelson Gonçalves](https://github.com/aryelson1)  
- [Guilherme Santos](https://github.com/GuilhermexL)  

---

## Descrição do Projeto

Este projeto implementa um controle de botões utilizando a placa BitDogLab e a Raspberry Pi Pico. O código foi desenvolvido para interagir com botões, permitindo a detecção de pressionamentos, solturas e a configuração de interrupções. As principais funcionalidades incluem:

- Inicialização dos botões como entradas.
- Leitura do estado dos botões.
- Detecção de pressionamentos e solturas (bordas de descida e subida).
- Espera bloqueante por pressionamento.
- Configuração de interrupções para eventos de botão.

---

## Arquitetura do Projeto

![Placa](images/Placa_profile.png)

### 1. Hardware Utilizado

- 1x Placa BitDogLab
- 2 Botões (para ativar e interromper funcionalidades)

### 2. Conexões

- Botão 1: Pino GPIO5 (para ativar funcionalidades)
- Botão 2: Pino GPIO6 (para interromper funcionalidades)

---

## Funcionalidades dos Botões

O projeto oferece as seguintes funcionalidades relacionadas aos botões, implementadas através de funções específicas:

### `void button_init(uint button_pin)`

- **Descrição:** Inicializa o pino do botão como entrada.
- **Detalhes:**
  - Configura o pino especificado como entrada com pull-up.
  - Prepara o pino para leitura de estados e detecção de bordas.

### `bool button_read(uint pin)`

- **Descrição:** Lê o estado atual do botão.
- **Detalhes:**
  - Retorna `true` se o botão estiver pressionado (nível lógico baixo).
  - Retorna `false` se o botão estiver solto (nível lógico alto).

### `bool button_pressed(uint pin)`

- **Descrição:** Verifica se o botão foi pressionado (detecção de borda de descida).
- **Detalhes:**
  - Retorna `true` se o botão foi pressionado desde a última leitura.
  - Implementa lógica para detectar apenas uma transição de solto para pressionado.

### `bool button_released(uint pin)`

- **Descrição:** Verifica se o botão foi solto (detecção de borda de subida).
- **Detalhes:**
  - Retorna `true` se o botão foi solto desde a última leitura.
  - Implementa lógica para detectar apenas uma transição de pressionado para solto.

### `void button_wait_press(uint pin)`

- **Descrição:** Aguarda até que o botão seja pressionado (função bloqueante).
- **Detalhes:**
  - Fica em loop até que o botão seja pressionado.
  - Útil para esperar por uma entrada do usuário antes de prosseguir.

### `void button_callback(uint gpio, uint32_t events)`

- **Descrição:** Configura uma função de callback para interrupções no botão.
- **Detalhes:**
  - Permite associar uma função a eventos de borda (descida ou subida) no pino do botão.
  - Útil para implementar ações assíncronas baseadas em pressionamentos de botão.

---

## Como Compilar e Executar

### Requisitos

- **Visual Studio Code** (ou outra IDE compatível)
- **Extensão Raspberry Pi Pico** (para desenvolvimento com Raspberry Pi Pico)
- **Raspberry Pi Pico SDK** (versão 1.5.1)

### Passos para Compilação

1. Clone o repositório do projeto.
2. Abra o projeto no Visual Studio Code.
3. Importe o projeto utilizando a extensão Raspberry Pi Pico.
4. Configure o SDK para a versão 1.5.1.

### Passos para Execução

1. Conecte a Raspberry Pi Pico ao computador via USB.
2. Carregue o arquivo `.uf2` gerado na Pico.
   - Alternativamente, instale o **Zadig** para executar diretamente do VSCode.
3. Interaja com os botões para testar as funcionalidades.

---

## Conclusão

Este projeto demonstra como controlar e interagir com botões utilizando a Raspberry Pi Pico e a placa BitDogLab. Ele pode ser expandido para incluir novas funcionalidades, como a integração com outros sensores ou a criação de sistemas interativos mais complexos.

---

## Referências

- [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)  
- [Documentação oficial da Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/)  

---