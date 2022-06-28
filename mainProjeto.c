/*
 * ============================================================================
 *
 *        PEQUI BANK
 * 
 *        Filenames:  mainProjeto.c / cliente.c / cliente.h / conta.c / conta.h
 *
 *        Description:  Projeto de banco digital para cliente e conta.
 *
 *        Createds:  07/04/2022
 *        Compiler:  gcc
 *
 *         Author:  Domingos Alves Ramos Neto e Luca Mascarenhas Plaster
 *   Organization:  Algoritmo e Estrutura de Dados 1
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "conta.c"
#include "cliente.c"

int main()
{
    menuPrincipal();
    free(ptCli);

    return 0;
}