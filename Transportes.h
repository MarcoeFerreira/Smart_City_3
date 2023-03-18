/**
 * @file   Transportes.h
 * @brief  Estrutura transportes e Assinatura da função
 *
 * @author Marco
 * @date   March 2023
 **/

#include <stdlib.h>
#include <stdbool.h>

#ifndef TRANSPORTES_H_
#define TRANSPORTES_H_

#define Nome_SIZE 40
#define EMAIL_SIZE 60
#define PASSWORD_SIZE 30
#define ADRESS_SIZE 80
#define LOCALIZACAO_SIZE 80

typedef enum {
	autocarro,
	trotinete,
	bicicleta
} TipodeTransporte;

typedef struct Transportes Transportes;

struct Transport {
	TipodeTransporte tipo;
	float cargaBateria;
	float custoAluguer;
	char localizacao[LOCALIZACAO_SIZE];
	Transportes* next;
};

/**
 * pede um transporte
 * adiciona um novo transporte a lista
 * retorna True - adicionado com sucesso
 * retorna False - Erro na alocaçao de memoria
 */
bool AddTransportes(Transportes** head, Transportes sourceTransportes);


Transport* GetTransportes(Transportes* head, int index);

#endif