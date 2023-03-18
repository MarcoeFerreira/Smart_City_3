/**
 * @file   Transportes.c
 * @brief  Assinaturas das funções e struct do transporte
 * 
 * @author Narco
 * @date   March 2023
 **/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef TRANSPORTES_H_
#define TRANSPORTES_H_

#define TRANSPORTES_TEXT_DIR "Caminho para importar de txt"
#define TRANSPORTES_BIN_DIR "Caminho para guardar em txt"

#define NOME_SIZE 40
#define EMAIL_SIZE 60
#define PASSWORD_SIZE 30
#define MORADA_SIZE 80
#define LOCALIZACAO_SIZE 80


typedef enum {
	autocarro,
	trotinete,
	bicicleta
} TipoTransporte;

typedef struct {
	int id;
	TipoTransporte type;
	float autonomia;
	float preco;
	char localizacao[LOCALIZACAO_SIZE];
} Transportes;

typedef struct ListaTransportes ListaTransportes;
struct TransportList {
	Transportes transporte;
	ListaTransportes* next;
};
							

bool AddTransportes(ListaTransportes** head, Transportes sourceTransport);

//vai buscar um transporte e "pega" no primeiro
//Retorna uma de duas opções :
//							 Adicionado com sucesso
//                           Erro a alocar a memoria 

ListaTransportes* GetTransportes(ListaTransportes* head, int index);

//Lê todos os transportes do ficheiro para uma lista
//Retorna uma de tres opcoes opções :
//							 Lido com sucesso
//                           Erro a abrir o ficheiro
//							 Errro de Leitura


int ReadTransportesFile(ListaTransportes** head, char* fileName);

//Guarda todos os transportes do ficheiro para uma lista
//Retorna uma de tres opcoes opções :
//							 Guardado com sucesso
//                           Erro a abrir o ficheiro
//							 A lista esta vazia

int SaveTransportesAsFile(ListaTransportes* head, char* fileName);

#endif