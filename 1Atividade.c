#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

struct informacao_de_contato
{
    char nome[100];
    char telefone[50];
    char email[50];
};

struct informacao_de_contato contato[3];
int i = 0;

char *conversor(char *name)
{
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        if (strcmp(name, contato[i].nome) == 0)
        {
            j = i;
            return contato[j].telefone;
        }
    }

    return 0;
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    char *x;
    char name[40];
    char resultado[40];

    for (i = 0; i < 3; i++)
    {

        printf("Digite o %d nome:", i + 1);
        gets(contato[i].nome);

        fflush(stdin);

        printf("Digite o telefone:");
        gets(contato[i].telefone);

        fflush(stdin);

        printf("Digite o email:");
        gets(contato[i].email);
        puts("");
    }
    fflush(stdin);
    printf("Digite o nome para achar contato:");
    gets(name);
    fflush(stdin);

    x = conversor(name);

    if (x == 0)
    {
        printf("Contato n�o encontrado.\n");
    }
    else
    {
        printf("O n�mero de telefone de %s �: %s\n", name, x);
    }

    return 0;
}
