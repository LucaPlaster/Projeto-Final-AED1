// Domingos Alves Ramos Neto -> 202003558
// Luca Mascarenhas Plaster -> 202014610

#ifndef CONTA_H
#define CONTA_H

int qntConta = 0;

typedef struct Conta
{
    char agencia[10];
    char numConta[10];
    char cliente[50];
    int saldo;
} Conta;

typedef struct lista
{
    int tam;
    struct Conta *conta;
    struct lista *proximo;
} node;

typedef Conta *ptConta;

ptConta ptCon;

void menuConta();
void cadastrarConta();
void verificaCodigoCpf_Conta(Conta conta, int qntConta);
void listarTodasContas();
void listarContaCliente();
int saque();
int deposito();
void buscaBinaria(Conta *conta, int qntConta);
void ordenacaoConta(Conta str[]);

node *aloca();

#endif // CONTA_H