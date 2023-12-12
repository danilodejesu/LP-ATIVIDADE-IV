#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContaBancaria
{
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    int tipoConta; // Alterei para int, pois parece representar um tipo numérico
};

struct ContaBancaria banco[99];
int c = 0;
int j = 0;
int i = 0;
int opcao;
char resp[50];
int nConta;
float valor;
float sacar;

// Função para deposito
float depositando(float valor_recebido, float salario_recebido)
{
    salario_recebido = salario_recebido + valor_recebido;
    return salario_recebido;
}

// Função para saque
float sacando(float saque_recebido, float salario_recebido)
{
    salario_recebido = salario_recebido - saque_recebido;
    return salario_recebido;
}

void imprimirSaldo()
{
    printf("Saldo atual: R$%.2f\n", banco[j].saldo);
}

int main()
{
    do
    {
        c = c + 1;
        printf("Digite o nome do titular: ");
        fgets(banco[c].nomeTitular, sizeof(banco[c].nomeTitular), stdin);

        printf("Digite o número da conta: ");
        scanf("%d", &banco[c].numeroConta);

        printf("Digite seu saldo: ");
        scanf("%f", &banco[c].saldo);

        printf("Escolha o tipo de conta (1 - Conta corrente, 2 - Conta poupança): ");
        scanf("%d", &banco[c].tipoConta);
        getchar(); // Consumir o caractere de nova linha após a leitura do tipoConta
        puts("");

        printf("Continuar cadastrando CONTAS? [s/n] ");
        fgets(resp, sizeof(resp), stdin);
        puts("");

    } while (strcmp(resp, "s\n") == 0 || strcmp(resp, "S\n") == 0);

    // Exibindo o menu
    do
    {
        puts("");
        puts("");
        printf("Digite a conta para fazer as operações: ");
        scanf("%d", &nConta);

        for (i = 1; i <= c; i++)
        {
            if (nConta == banco[i].numeroConta)
            {
                j = i;
                break;
            }
        }

        printf("\nMenu:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Consultar Saldo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor para depósito: ");
            scanf("%f", &valor);

            banco[j].saldo = depositando(valor, banco[j].saldo);

            puts("");
            printf("Deposito feito com sucesso!\n");
            printf("Seu saldo atual é R$%.2f\n", banco[j].saldo);
            break;
        case 2:
            printf("Digite o valor para sacar: ");
            scanf("%f", &sacar);

            banco[j].saldo = sacando(sacar, banco[j].saldo);

            puts("");
            printf("Saque feito com sucesso!\n");
            printf("Seu saldo atual é R$%.2f\n", banco[j].saldo);
            break;
        case 3:
            imprimirSaldo();
            break;
        case 0:
            printf("Saindo do programa. Até mais!\n");
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}
