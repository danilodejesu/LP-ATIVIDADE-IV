#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

struct informacao_do_aluno
{
    char nome[100];
    int dataNascimento;
    float nota1;
    float nota2;
    float media;
};
struct informacao_do_aluno aluno[3];
int i;
char name[40];
float z;

float calcularMedia(int j)
{
    aluno[j].media = (aluno[j].nota1 + aluno[j].nota2) / 2;
    return aluno[j].media;
}

char AprovadoOuNao(char *name)
{

    int j;
    for (i = 0; i < 3; i++)
    {
        if (strcmp(name, aluno[i].nome) == 0)
        {
            j = i;
            z = calcularMedia(j);

            if (z >= 7)
            {
                printf("Aluno aprovado.");
            }
            else
            {
                printf("Aluno REPROVADO");
            }
        }
    }
}

int main()
{
    float mediaIndividual;

    setlocale(LC_ALL, "portuguese");

    for (i = 0; i < 3; i++)
    {

        printf("Informe os dados do Aluno %d:\n", i + 1);

        fflush(stdin);
        printf("Digite o %d nome: ", 1 + i);
        gets(aluno[i].nome);
        fflush(stdin);

        printf("Digite ano de nascimento: ");
        scanf("%d", &aluno[i].dataNascimento);
        fflush(stdin);

        printf("Digite primeira nota: ");
        scanf("%f", &aluno[i].nota1);
        fflush(stdin);

        printf("Digite segunda nota: ");
        scanf("%f", &aluno[i].nota2);
        puts("");
    }

    fflush(stdin);
    printf("Digite o nome do aluno para verificamos se está APROVADO OU REPROVADO: \n");
    gets(name);
    fflush(stdin);

    AprovadoOuNao(name);

    return 0;
}