#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

// Definição do nome do aluno
#define NOME_ALUNO "Lucas_Simbelis"

// Criação do semáforo binário
SemaphoreHandle_t xSemaphore;

// Declaração das tarefas
void tarefa1(void *pvParameters);
void tarefa2(void *pvParameters);
void tarefa3(void *pvParameters);

void app_main(void)
{
    // Criação do semáforo binário
    xSemaphore = xSemaphoreCreateBinary();

    if (xSemaphore == NULL) {
        printf("Falha ao criar semáforo.\n");
        return;
    }

    // Inicializa o semáforo com valor 1 (permitindo a execução da tarefa 1)
    xSemaphoreGive(xSemaphore);

    // Criação das tarefas
    xTaskCreate(tarefa1, "Tarefa 1", 2048, NULL, 1, NULL);
    xTaskCreate(tarefa2, "Tarefa 2", 2048, NULL, 2, NULL);
    xTaskCreate(tarefa3, "Tarefa 3", 2048, NULL, 3, NULL);
}

void tarefa1(void *pvParameters)
{
    while (1) {
        // Espera para pegar o semáforo
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
            printf("[Tarefa 1] Executou - %s\n", NOME_ALUNO);

            // Dá o semáforo para a próxima tarefa
            xSemaphoreGive(xSemaphore);

            // Atraso de 1 segundo
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}

void tarefa2(void *pvParameters)
{
    while (1) {
        // Espera para pegar o semáforo
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
            printf("[Tarefa 2] Executou - %s\n", NOME_ALUNO);

            // Dá o semáforo para a próxima tarefa
            xSemaphoreGive(xSemaphore);

            // Atraso de 1 segundo
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}

void tarefa3(void *pvParameters)
{
    while (1) {
        // Espera para pegar o semáforo
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
            printf("[Tarefa 3] Executou - %s\n", NOME_ALUNO);

            // Dá o semáforo para a próxima tarefa
            xSemaphoreGive(xSemaphore);

            // Atraso de 1 segundo
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}
