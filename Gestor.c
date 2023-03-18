/**
 * @file   Gestor.c
 * @brief  estruturas e funçoes e ficheiro do Gestor 
 * 
 * @author Marco
 * @date   March 2023
 **/
#include <stdbool.h>
#include "Gestor.h"


bool AddGestor(ListaGestores** head, Gestor sourceGestor) {

	//Creates a new space in memory to Allocate the manager
	ListaGestores* newGestor = (GestorList*) malloc(sizeof(gestorList));

	if (newGestor == NULL) {
		free(newGestor);
		return false;
	}

	newGestor->manager = sourceGestor;
	newGestor->next = NULL;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newGestor;
		return true;
	}

	//Else finds the last element of the list
	ListaGestores* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newGestor;
	return true;
}




GestorList* GetGestor(GestorList* head, int index) {

									
	if (head == NULL) return NULL;	//Checks if the list is empty
									// Vai buscar o gestor ao seu apontador na lista pelo seu index
GestorList* current = head;			// Retorna o apontador com um inex especifico
									// retorna NULL se o index for invalido 

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

int lerficheiroGestor(GestorList** head, char* fileName) {

	Gestor current = { 0 };

	FILE* file;								//Lê todos os managers do ficheiro
											//Três possiveis respostas : Lido com sucesso
											//							 Erro na abertura do ficheiro
											//							 Erro na Leitura
	fopen_s(&file, fileName, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf(buffer, "%d;%[^;];%[^;];%s\n",
			&current.name, current.email, current.password) != 4)
			return 3;

		AddGestor(head, current);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Saves all the managers from a list into a file.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The list is empty
 */
int SaveListaGestores(GestorList* head, char* fileName) {

	if (head == NULL) return 3;

	GestorList* current = head;

	FILE* file;

	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	do
	{
		fwrite(&(current->Gestor), sizeof(GestorList), 1, file);

		current = current->next;
	} while (current != NULL);

	fclose(file);
	return 1;
}