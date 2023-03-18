/**
 * @file   Cliente.h
 * @brief  Estrutura do Cliente
 * 
 * @author Marco
 * @date   March 2023
 **/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define CLIENTE_DIR "Copiar o caminho da pasta"

#define MORADA_SIZE 80
#define NAME_SIZE 40
#define NIF_SIZE 15


typedef struct Cliente Cliente;
struct Cliente {
	char nome[NAME_SIZE];
	char nif[NIF_SIZE];
	char morada[MORADA_SIZE];
	float saldo;
	Cliente* next;
};


bool AddCliente(Cliente** head, Cliente sourceCustomer);


Cliente* GetCliente(Cliente* head, int index);

/*
 * @return 1 - Lido com sucesso
 * @return 2 - Erro no sscanf_s
 * @return 3 - Error ao abrir o ficheiro
 */
int ReadClientesFiles(Cliente** head);

#endif