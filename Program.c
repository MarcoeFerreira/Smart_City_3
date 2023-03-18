/**
 * @file   Program.c
 * @brief  Chama todas as funções
 * 
 * @author Marco
 * @date   March 2023
 **/

#include "Cliente.h"
#include "Gestor.h"
#include "Transportes.h"


int main() {

	ListaClientes* Clientes = NULL;            //Costumer linked list inicialization
	ListaGestores* Gestores = NULL;           //Manager linked list inicialization
	ListaTransportes* transportes = NULL;    //Transport linked list inicialization


	printf("\n %d", ReadCustomersFile(&customers, CUSTOMER_TEXT_DIR));
	printf("\n %d", ReadManagersFile(&managers, MANAGER_TEXT_DIR));
	printf("\n %d", ReadTransportsFile(&transports, TRANSPORT_TEXT_DIR));

	Customer c1 = { 1, "dwdw", "dwd", "dwdw", 69420 };
	Customer c2 = { 2, "dydfy", "breb", "sdf", 12345 };
	Customer c3 = { 3, "ehg", "ertg", "fwef", 8994 };
	Customer c4 = { 4, "kym", "myu", "bn", 345 };

	Customer c1 = { 1, "dwdw", "dwd", "dwdw", 69420 };
	Customer c2 = { 2, "dydfy", "breb", "sdf", 12345 };
	Customer c3 = { 3, "ehg", "ertg", "fwef", 8994 };
	Customer c4 = { 4, "kym", "myu", "bn", 345 };



	ManagerList* sample = FindManager(managers, 1);

	EditCustomer(sample, c1);

	return 0;
}