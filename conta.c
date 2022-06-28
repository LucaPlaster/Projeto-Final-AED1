// Domingos Alves Ramos Neto -> 202003558
// Luca Mascarenhas Plaster -> 202014610

#include <stdio.h>
#include "conta.h"
#include "cliente.h"

void menuConta()
{

    char comando[2];
    char buscar[50];
    int continuar;

    Conta *conta;
    node *lista;

    *aloca();

    do
    {

        printf("============ Gerenciar Contas ============\n"
               "Digite um comando para prosseguir\n"
               "R - Listagem de todas as contas cadastradas\n"
               "C - Cadastrar uma conta para um cliente.\n"
               "L - Lista dados da conta de um cliente\n"
               "B - Busca por Agencia\n"
               "O - Ordenar e listar contas por tamanho\n"
               "S - Sair\n");

        scanf("%s", comando);

        system("cls");

        switch (comando[0])
        {
        case 'R':
            listarTodasContas();
            break;

        case 'C':
            cadastrarConta();
            break;

        case 'L':
            listarContaCliente();
            break;

        case 'B':
            buscaBinaria(ptCon, qntConta);
            break;

        case 'O':
            ordenacaoConta(ptCon);
            break;

        case 'S':
            menuPrincipal();

        default:
            printf("Opcao invalida !\n");
        }

    } while (comando[0] != 'S');

    free(lista);
    system("cls");
}

void verificaCodigoCpf_Conta(Conta conta, int qntConta)
{
    int continuar;

    for (int j = 0; j < qntConta; j++)
    {
        if (strcmp(ptCon[j].agencia, conta.agencia) == 0)
        {
            printf("Conta ja cadastrada com o mesma agencia, tente novamente\n"
                   "Aperte ENTER para continuar ");
            fflush(stdin);
            continuar = getchar();
            system("cls");
            menuConta();
        }
        if (strcmp(ptCon[j].numConta, conta.numConta) == 0)
        {
            printf("Cliente ja cadastrado com o mesmo numero de conta, tente novamente\n"
                   "Aperte ENTER para continuar ");
            fflush(stdin);
            continuar = getchar();
            system("cls");
            menuConta();
        }
    }
}

void cadastrarConta()
{

    int continuar;
    Conta conta;
    char codigoCpf[50];
    int naoAchou, i;
    char nome[50];

    fflush(stdin);
    printf("Informe o codigo ou o CPF do cliente: ");
    fgets(codigoCpf, 15, stdin);
    fflush(stdin);

    if (qntCliente == 0)
    {
        printf("Nao existem clientes!\n"
               "Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system("cls");
        menuConta();
    }

    for (i = 0; i < qntCliente; i++)
    {
        if ((strcmp(ptCli[i].codigo, codigoCpf) == 0) || (strcmp(ptCli[i].cpf, codigoCpf) == 0))
        {
            naoAchou = 1;
            printf("Insira os dados da conta para o cliente:");
            fflush(stdin);
            printf("\nAgencia: ");
            fgets(conta.agencia, sizeof(ptCon->agencia), stdin);
            fflush(stdin);
            printf("\nNumero da conta: ");
            fgets(conta.numConta, sizeof(ptCon->numConta), stdin);
            fflush(stdin);

            for (int p = 0; p < sizeof(ptCli[i].nome); p++)
            {
                conta.cliente[p] = ptCli[i].nome[p];
            }

            conta.saldo = 0;

            verificaCodigoCpf_Conta(conta, qntConta);

            break;
        }
        naoAchou = 0;
    }

    if (naoAchou == 0)
    {
        printf("Cliente nao encontrado\n\n"
               "Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system("cls");
        cadastrarConta();
    }

    ptCon = (ptConta)realloc(ptCon, 200 * sizeof(Conta));

    if (ptCon == NULL)
    {
        printf("erro na alocacao de memoria");
        exit(1);
    }

    ptCon[qntConta] = conta;
    qntConta++;

    printf("Conta cadastrada com sucesso!\n\n");

    printf("Aperte ENTER para continuar");
    continuar = getchar();
    system("cls");
}

void listarTodasContas()
{

    int continuar;
    system("cls");

    if (qntConta == 0)
    {
        printf("Nao existem contas!\n"
               "Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system("cls");
        menuConta();
    }

    printf("Lista da(s) %d contas cadastradas\n\n", qntConta);

    for (int j = 0; j < qntConta; j++)
    {
        printf("Conta numero %d\n", j + 1);
        printf("Agencia: %s", ptCon[j].agencia);
        printf("\n");
        printf("Numero da conta: %s", ptCon[j].numConta);
        printf("Cliente: %s", ptCon[j].cliente);
        printf("Saldo: %s\n\n", ptCon[j].saldo);
    }

    printf("Aperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system("cls");
}

void listarContaCliente()
{

    int continuar, naoAchou, semConta;
    char codigo[50];
    system("cls");

    printf("Informe o codigo ou o CPF do cliente: ");
    fflush(stdin);
    fgets(codigo, 15, stdin);

    if (qntCliente == 0)
    {
        printf("Nao existem clientes!\n"
               "Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system("cls");
        menuConta();
    }

    for (int i = 0; i < qntCliente; i++)
    {
        if ((strcmp(ptCli[i].codigo, codigo) == 0) || (strcmp(ptCli[i].cpf, codigo) == 0))
        {
            naoAchou = 1;
            for (int j = 0; j < qntConta; j++)
            {

                if (strcmp(ptCli[i].nome, ptCon[j].cliente) == 0)
                {
                    semConta = 1;
                    printf("Conta numero %d\n", j + 1);
                    printf("Agencia: %s", ptCon[j].agencia);
                    printf("\n");
                    printf("Numero de conta: %s", ptCon[j].numConta);
                    printf("Cliente: %s", ptCon[j].cliente);
                    printf("Saldo: %s\n\n", ptCon[j].saldo);
                }
            }
            if (semConta == 0)
            {
                printf("O cliente nao possui contas\n\n"
                       "Aperte ENTER para continuar ");
                fflush(stdin);
                continuar = getchar();
                system("cls");
                menuConta();
            }
            break;
        }
        naoAchou = 0;
    }

    if (naoAchou == 0)
    {
        printf("Cliente nao encontrado\n\n"
               "Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system("cls");
        menuConta();
    }

    printf("Aperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system(CLS);
}

void buscaBinaria(Conta *conta, int qntConta)
{ // Busca Binária
    char Agencia[10];
    int continuar;
    int inf = 0;
    int sup = qntConta - 1;

    system(CLS);
    printf("Digite a agencia que deseja buscar: ");
    scanf("%s", &Agencia);

    for (int i = 0; i < strlen(conta->agencia - 1); i++)
    {
        if (conta->agencia[i] == '\n')
        {
            conta->agencia[i] = '\0';
        }
    }

    while (inf <= sup)
    {
        int meio = inf + (sup - inf) / 2;

        for (int j = 0; j < qntCliente; j++)
        {
            if (strcmp(Agencia, conta->agencia) == 0)
            {
                printf("Conta numero %d\n", j + 1);
                printf("Agencia: %s\n", ptCon[j].agencia);
                printf("Numero de conta: %s", ptCon[j].numConta);
                printf("Cliente: %s", ptCon[j].cliente);
                printf("Saldo: %s\n\n", ptCon[j].saldo);
            }
        }

        if (conta->agencia < Agencia)
        {
            inf = meio + 1;
        }
        else
        {
            sup = meio - 1;
        }
    }

    printf("Aperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system(CLS);
}

node *aloca()
{
    node *novo = (node *)malloc(sizeof(node));

    if (!novo)
    {
        printf("Sem espaco na memoria!\n");
        exit(1);
    }
    else
    {
        novo->proximo = NULL;
        novo->tam = 0;
        return novo;
    }
}

void ordenacaoConta(Conta str[])
{ // InsertionSort O(N^2)
    int i, j, continuar;
    Conta temp[qntConta];

    if (qntCliente == 0)
    {
        printf("Nao existem clientes cadastrados!\n\n");

        printf("Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system(CLS);
        menuConta();
    }

    for (i = 1; i < qntConta; i++)
    {
        if (strlen(str[i - 1].cliente) > strlen(str[i].cliente))
        {
            temp[i] = str[i];
            j = i - 1;
            do
            {
                str[j + 1] = str[j];
                j--;
            } while (j >= 0 && strlen(str[j].cliente) >= strlen(temp[j].cliente));
            str[j + 1] = temp[i];
        }
    }

    for (i = 0; i < qntConta; i++)
        printf("Nome %d: %s\n", i + 1, str[i].cliente);

    printf("Ordenado por insertion Sort O(n^2)");

    printf("\n\nAperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system(CLS);
    menuCliente();
}
