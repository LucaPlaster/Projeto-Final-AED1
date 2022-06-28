// Luca Mascarenhas Plaster -> 202014610
// Domingos Alves Ramos Neto -> 202003558
#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>
#include <string.h>
#include "conta.h"
// Domingos Alves Ramos Neto -> 202003558
// Luca Mascarenhas Plaster -> 202014610

#ifdef _WIN32
#define CLS "cls"
#elif __linux__
#define CLS "clear"
#endif

int qntCliente = 0;

typedef struct Cliente
{ // estrutura de um Cliente
    char codigo[50];
    char nome[50];
    char cpf[50];
    char telefone[10];
    char endereco[30];

} Cliente;

typedef Cliente *ptCliente; // criar uma variavel do tipo ponteiro de cliente

ptCliente ptCli;

void menuPrincipal();
void menuCliente();
Cliente novoCliente();
void cadastrarCliente(Cliente cliente);
void verificaCodigo_Cpf(Cliente cliente, int qntCliente);
void listarClientes();
ptCliente buscarCliente();
void atualizarCliente();
void excluirCliente();
void OrdenacaoCliente();

#endif // CLIENTE_H

// Busca binaria em conta, ordenação em conta, implementação da lista.