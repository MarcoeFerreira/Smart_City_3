/**
 * @file   Gestor.h
 * @brief  Estrutura Gestor e Assinatura da função
 * 
 * @author Marco
 * @date   March 2023
 **/
#include <stdlib.h>
#include <stdbool.h>

#ifndef GESTOR_H_
#define GESTOR_H_

#define NOME_SIZE 40
#define MORADA_SIZE 80
#define EMAIL_SIZE 60
#define PASSWORD_SIZE 30


typedef struct Gestor Gestor;
struct Manager {
	char name[NOME_SIZE];
	char email[EMAIL_SIZE];
	char password[PASSWORD_SIZE];
	Gestor* next;
};

/*
  false - Erro a colocar na memoria
  true - Adicionado com sucesso
 */

bool AddGestor(Gestor** head, Gestor sourceGestor);

/**

   vai buscar o gestor num apontador do index
   retorna o Gestor apontado com um index especifico
 * @return Manager pointer with the specified index
 */
Manager* GetGestot(Gestor* head, int index);

#endif
