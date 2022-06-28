// Domingos Alves Ramos Neto -> 202003558
// Luca Mascarenhas Plaster -> 202014610

#include <stdio.h>
#include "cliente.h"
#include "conta.h"

void menuPrincipal()
{

    char comando[2];

    do
    {
        system(CLS);
        printf("=============== Bem vindo! =================\n"
               "Digite um comando para prosseguir:\n"
               "C - Gerenciar Clientes\n"
               "T - Gerenciar Contas\n"
               "S - Sair\n");

        scanf("%s", comando);
        system(CLS);

        switch (comando[0])
        {
        case 'C':
            menuCliente();
            break;

        case 'T':
            menuConta();
            break;

        case 'S':
            exit(0);
            break;

        default:
            printf("Opcao invalida !\n");
        }

    } while (comando[0] != 'S');
    system(CLS);
}

void menuCliente()
{

    char comando[2];
    char buscar[50];
    int continuar;

    Cliente cliente[qntCliente];
    ptCliente imprimeClienteEncontrado;

    do
    {

        printf("============ Gerenciar Clientes ============\n"
               "Digite um comando para prosseguir:\n"
               "C - Cadastrar um cliente\n"
               "L - Listar todos os clientes cadastrados\n"
               "B - Buscar cliente ja cadastrado\n"
               "A - Atualizar um cliente cadastrado\n"
               "E - Excluir um cliente cadastrado\n"
               "O - Ordenar e listar clientes por tamanho\n"
               "S - Sair\n");

        scanf("%s", comando);

        system(CLS);

        switch (comando[0])
        {
        case 'C':
            cadastrarCliente(novoCliente());
            break;

        case 'L':
            listarClientes();
            break;

        case 'B':

            imprimeClienteEncontrado = buscarCliente();
            system(CLS);
            printf("Codigo: %s", imprimeClienteEncontrado->codigo);
            printf("Nome: %s", imprimeClienteEncontrado->nome);
            printf("CPF: %s", imprimeClienteEncontrado->cpf);
            printf("Telefone: %s", imprimeClienteEncontrado->telefone);
            printf("Endereco: %s\n\n", imprimeClienteEncontrado->endereco);

            printf("Aperte ENTER para continuar");
            continuar = getchar();
            system(CLS);

            break;

        case 'A':
            atualizarCliente();
            break;

        case 'E':
            excluirCliente();
            break;

        case 'S':
            menuPrincipal();
            break;

        case 'O':
            OrdenacaoCliente(ptCli);
            break;

        default:
            printf("Opcao invalida !\n");
        }

    } while (comando[0] != 'S');
    system(CLS);
}

Cliente novoCliente()
{

    Cliente cliente;

    fflush(stdin);
    printf("Informe o codigo do cliente: ");
    fgets(cliente.codigo, sizeof(ptCli->codigo), stdin);
    fflush(stdin);
    printf("\nInforme o nome do cliente: ");
    fgets(cliente.nome, sizeof(ptCli->nome), stdin);
    fflush(stdin);
    printf("\nInforme o CPF do cliente: ");
    fgets(cliente.cpf, sizeof(ptCli->cpf), stdin);
    fflush(stdin);
    printf("\nInforme o telefone do cliente: ");
    fgets(cliente.telefone, sizeof(ptCli->telefone), stdin);
    fflush(stdin);
    printf("\nInforme o endereco do cliente: ");
    fgets(cliente.endereco, sizeof(ptCli->endereco), stdin);
    fflush(stdin);

    verificaCodigo_Cpf(cliente, qntCliente);

    return cliente;
}

void cadastrarCliente(Cliente cliente)
{

    char continuar;
    ptCli = (ptCliente)realloc(ptCli, 100 * sizeof(Cliente));

    if (ptCli == NULL)
    {
        printf("erro na alocacao de memoria");
        exit(1);
    }

    ptCli[qntCliente] = cliente;
    qntCliente++;

    printf("\nCliente cadastrado com sucesso!\n");

    printf("Aperte ENTER para continuar");
    continuar = getchar();
    system(CLS);
}

void verificaCodigo_Cpf(Cliente cliente, int qntCliente)
{

    int continuar;

    for (int i = 0; i < qntCliente; i++)
    {
        if (strcmp(ptCli[i].codigo, cliente.codigo) == 0)
        {
            printf("Cliente ja cadastrado com o mesmo codigo, tente novamente\n"
                   "Aperte ENTER para continuar ");
            fflush(stdin);
            continuar = getchar();
            system(CLS);
            menuCliente();
        }
        if (strcmp(ptCli[i].cpf, cliente.cpf) == 0)
        {
            printf("Cliente ja cadastrado com o mesmo CPF, tente novamente\n"
                   "Aperte ENTER para continuar ");
            fflush(stdin);
            continuar = getchar();
            system(CLS);
            menuCliente();
        }
    }
}

void listarClientes()
{

    char continuar;
    int i;

    if (qntCliente == 0)
    {
        printf("Nao existem clientes cadastrados!\n\n");

        printf("Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system(CLS);
        menuCliente();
    }

    printf("Lista do(s) %d clientes cadastrados\n\n", qntCliente);

    for (i = 0; i < qntCliente; i++)
    {
        printf("Cliente numero %d\n", i + 1);
        printf("Codigo: %s", ptCli[i].codigo);
        printf("Nome: %s", ptCli[i].nome);
        printf("CPF: %s", ptCli[i].cpf);
        printf("Endereco: %s", ptCli[i].endereco);
        printf("Telefone: %s\n\n", ptCli[i].telefone);
    }

    printf("Aperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system(CLS);
}

void atualizarCliente()
{
    char continuar, nome[50], telefone[10], endereco[30];
    char codigoCpf[15];
    int naoAchou;

    printf("Digite o codigo do Cliente que deseja atualizar: ");
    fflush(stdin);
    fgets(codigoCpf, 15, stdin);
    system(CLS);

    for (int i = 0; i < qntCliente; i++)
    {

        if ((strcmp(ptCli[i].codigo, codigoCpf) == 0) || (strcmp(ptCli[i].cpf, codigoCpf) == 0))
        {

            naoAchou = 1;
            printf("\nInsira o nome: ");
            fflush(stdin);
            fgets(ptCli[i].nome, sizeof(ptCli->nome), stdin);
            printf("\nInsira o telefone: ");
            fgets(ptCli[i].telefone, sizeof(ptCli->telefone), stdin);
            printf("\nInsira o endereco: ");
            fgets(ptCli[i].endereco, sizeof(ptCli->endereco), stdin);

            printf("Aperte ENTER para continuar ");
            fflush(stdin);
            continuar = getchar();
            system(CLS);
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
        system(CLS);
        atualizarCliente();
    }
}

ptCliente buscarCliente()
{

    int naoAchou, continuar;
    char buscar[50];
    ptCliente cliente;

    printf("Digite o codigo/nome/CPF do cliente que queira buscar: ");
    fflush(stdin);
    fgets(buscar, 50, stdin);

    for (int i = 0; i < qntCliente; i++)
    {
        if ((strcmp(ptCli[i].codigo, buscar) == 0) || (strcmp(ptCli[i].nome, buscar) == 0) || (strcmp(ptCli[i].cpf, buscar) == 0))
        {
            naoAchou = 1;
            cliente = &ptCli[i];
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
        system(CLS);
        menuCliente();
    }

    return cliente;

    printf("\n\nAperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system(CLS);
}

void excluirCliente()
{

    int continuar, naoAchou;
    char comando[2];
    char codigoCpf[15];

    ptCliente cliente;

    printf("Digite o codigo ou o CPF do Cliente que deseja excluir: ");
    fflush(stdin);
    fgets(codigoCpf, 15, stdin);
    system(CLS);

    for (int i = 0; i < qntCliente; i++)
    {

        if ((strcmp(ptCli[i].codigo, codigoCpf) == 0) || (strcmp(ptCli[i].cpf, codigoCpf) == 0))
        {

            printf("Cliente numero %d\n", i + 1);
            printf("Codigo: %s", ptCli[i].codigo);
            printf("Nome: %s", ptCli[i].nome);
            printf("CPF: %s", ptCli[i].cpf);
            printf("Endereco: %s", ptCli[i].endereco);
            printf("Telefone: %s\n\n", ptCli[i].telefone);

            printf("Digite S para confirmar a exclusao, ou N para negar: ");

            fflush(stdin);
            fgets(comando, 2, stdin);

            switch (comando[0])
            {
            case 'S':

                naoAchou = 1;
                while (i < qntCliente - 1)
                {
                    ptCli[i] = ptCli[i + 1];
                    i++;
                }

                qntCliente--;

                printf("Aperte ENTER para continuar ");
                fflush(stdin);
                continuar = getchar();
                system(CLS);
                break;

            case 'N':
                system(CLS);
                menuCliente();

            default:
                excluirCliente();
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
        system(CLS);
        excluirCliente();
    }
}

void OrdenacaoCliente(Cliente str[])
{ // SelectioSort O(N^2)
    int i, j, continuar;
    Cliente temp[qntCliente];

    if (qntCliente == 0)
    {
        printf("Nao existem clientes cadastrados!\n\n");

        printf("Aperte ENTER para continuar ");
        fflush(stdin);
        continuar = getchar();
        system(CLS);
        menuCliente();
    }

    for (i = 0; i < qntCliente; i++)
        for (j = i + 1; j <= qntCliente - 1; j++)
            if (strlen(str[i].nome) > strlen(str[j].nome))
            {
                temp[i] = str[i];
                str[i] = str[j];
                str[j] = temp[i];
            }

    for (i = 0; i < qntCliente; i++)
        printf("Nome %d: %s\n", i + 1, str[i].nome);

    printf("Ordenado por selection Sort O(n^2)");

    printf("\n\nAperte ENTER para continuar ");
    fflush(stdin);
    continuar = getchar();
    system(CLS);
}