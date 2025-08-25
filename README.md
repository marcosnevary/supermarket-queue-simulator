# 🛒 Simulador de Fila de Supermercado

Este projeto foi desenvolvido na disciplina de **Sistemas Operacionais** do curso de **Ciência da Computação** da **Universidade Federal do Pará (UFPA)**, ministrada pelo **Prof. Dr. Marcos Tulio Amaris Gonzalez**.

O objetivo é simular o funcionamento de um supermercado com múltiplos caixas e clientes usando **threads**, **semáforos** e **mutex**.

## Descrição

- Os clientes entram na fila de atendimento.
- Os caixas atendem os clientes em ordem de chegada.
- O uso de **semáforos** e **mutex** garante o controle do acesso à fila.

## Execução

1. Clone este repositório:
    ```bash
    git clone https://github.com/marcosnevary/supermarket-queue-simulator.git
    cd supermarket-queue-simulator
    ```
2. Compile:
    ```
    make
    ```
3. Execute:
    ```
    ./supermarket_queue_simulator
    ```
4. Limpe o exeutável:
    ```
    make clean
    ```

## Autores

- Carlos Arthur Lima da Silva — 202404940015
- Marcos Vinicius Brito de Araujo — 202404940009
- Mauricio Aires Pinheiro — 202404940003
- Murillo Martins Figueira — 202404940034
