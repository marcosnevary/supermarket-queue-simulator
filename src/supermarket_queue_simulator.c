#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CLIENTES 10
#define NUM_CAIXAS 3
#define TAMANHO_FILA 5

int fila_clientes[TAMANHO_FILA];
int posicao_entrada = 0;
int posicao_saida = 0;

sem_t semaforo_clientes;
sem_t semaforo_vagas;
pthread_mutex_t mutex_fila;

void *cliente(void *arg) {
    int id_cliente = *(int *)arg;

    sem_wait(&semaforo_vagas);
    pthread_mutex_lock(&mutex_fila);

    fila_clientes[posicao_entrada] = id_cliente;
    printf("Cliente %d entrou na fila na posicao %d\n", id_cliente, posicao_entrada);
    posicao_entrada = (posicao_entrada + 1) % TAMANHO_FILA;

    pthread_mutex_unlock(&mutex_fila);
    sem_post(&semaforo_clientes);

    return NULL;
}

void *caixa(void *arg) {
    int id_caixa = *(int *)arg;

    while (1) {
        sem_wait(&semaforo_clientes);
        pthread_mutex_lock(&mutex_fila);

        int cliente_atendido = fila_clientes[posicao_saida];
        printf("Caixa %d esta atendendo o cliente %d da posicao %d\n", id_caixa, cliente_atendido, posicao_saida);
        posicao_saida = (posicao_saida + 1) % TAMANHO_FILA;

        pthread_mutex_unlock(&mutex_fila);
        sem_post(&semaforo_vagas);

        sleep(rand() % 3 + 1);
        printf("Caixa %d terminou de atender o cliente %d\n", id_caixa, cliente_atendido);
    }

    return NULL;
}

int main() {
    pthread_t threads_clientes[NUM_CLIENTES];
    pthread_t threads_caixas[NUM_CAIXAS];
    int ids_clientes[NUM_CLIENTES], ids_caixas[NUM_CAIXAS];

    sem_init(&semaforo_clientes, 0, 0);
    sem_init(&semaforo_vagas, 0, TAMANHO_FILA);
    pthread_mutex_init(&mutex_fila, NULL);

    for (int i = 0; i < NUM_CAIXAS; i++) {
        ids_caixas[i] = i + 1;
        pthread_create(&threads_caixas[i], NULL, caixa, &ids_caixas[i]);
    }

    for (int i = 0; i < NUM_CLIENTES; i++) {
        ids_clientes[i] = i + 1;
        pthread_create(&threads_clientes[i], NULL, cliente, &ids_clientes[i]);
        usleep((rand() % 1000 + 500) * 1000);
    }

    for (int i = 0; i < NUM_CLIENTES; i++) {
        pthread_join(threads_clientes[i], NULL);
    }

    printf("Simulacao finalizada.\n");
    return 0;
}
