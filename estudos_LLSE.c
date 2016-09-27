#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct no
{
    int codigo;
    char nome[20];
    struct no *next;
} no;

struct no *inicio, *corrente, *auxiliar;

void EnterData()
{
    printf("Insira o codigo: ");
    scanf("%d", &corrente->codigo);
    fflush(stdin);
    printf("Insira o nome: ");
    scanf("%s", corrente->nome);
    fflush(stdin);
}

void Insercao(no **Lista)
{
    if(auxiliar == NULL)
    {
        corrente = (no *)malloc(sizeof(no));
        auxiliar = corrente;
        corrente->next = NULL;
        inicio = corrente;
        EnterData();
    }
    else
    {
        corrente = (no *)malloc(sizeof(no));
        EnterData();
        auxiliar->next = corrente;
        corrente->next = NULL;
        auxiliar = corrente;
    }
    printf("Registro inserido com sucesso!\n\n");
    system("pause");
    system("cls");
}

void Exibicao(no **Lista)
{
    if(inicio == NULL)
    {
        printf("Lista vazia!\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            printf("Codigo: %d\nNome: %s\n\n", auxiliar->codigo, auxiliar->nome);
            auxiliar = auxiliar->next;
        }
        system("pause");
        system("cls");
    }
}

void Pesquisa(no **Lista)
{
    int achou, xcod;

    if(inicio == NULL)
    {
        printf("Lista vazia!\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Digite o codigo a ser pesquisado: ");
        achou = 0;
        scanf("%d", &xcod);
        fflush(stdin);

        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            if(xcod == auxiliar->codigo)
            {
                printf("Codigo: %d\nNome: %s\n\n", auxiliar->codigo, auxiliar->nome);
                achou = 1;
            }
            else
            {
                auxiliar = auxiliar->next;
            }

            if(achou == 0)
            {
                printf("Registro nao encontrado!\n\n");
                system("pause");
                system("cls");
            }
        }
    }
}

void Remocao(no **Lista)
{
    int achou, xcod;

    if(inicio == NULL)
    {
        printf("Lista vazia!\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        auxiliar = inicio;
        achou = 0;
        printf("Digite o codigo a ser removido: ");
        scanf("%d", &xcod);
        fflush(stdin);

        if(auxiliar->codigo == xcod)
        {
            inicio = inicio->next;
            free(auxiliar);
            printf("Registro removido com sucesso!\n\n");
            system("pause");
            system("cls");
            achou = 1;
        }
        else
        {
            corrente = auxiliar->next;

            while(corrente != NULL)
            {
                if(corrente->codigo == xcod)
                {
                    auxiliar->next = corrente->next;
                    free(corrente);
                    printf("Registro removido com sucesso!\n\n");
                    system("pause");
                    system("cls");
                    achou = 1;
                }
                else
                {
                    auxiliar = auxiliar->next;
                    corrente = corrente->next;
                }

                if(achou == 0)
                {
                    printf("Registro nao encontrado!\n\n");
                    system("pause");
                    system("cls");
                }
            }
        }
    }
}

int main(void)
{


    system("color 0B");
    int opcao;

    inicio = NULL;
    corrente = NULL;
    auxiliar = NULL;

    menu:
    printf("\t\t\t\t\tLISTA LINEAR SIMPLESMENTE ENCADEADA\n\t\t\t\t\t\tPor Leticia Ferreira\n\n");
    printf("Selecione a sua opcao abaixo:\n\n");
    printf("1. Inserir\n2. Exibir\n3. Pesquisar\n4. Remover\n5. Sair\n\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch(opcao)
    {
        case 1: Insercao(&inicio);
        goto menu;
        break;

        case 2: Exibicao(&inicio);
        goto menu;
        break;

        case 3: Pesquisa(&inicio);
        goto menu;
        break;

        case 4: Remocao(&inicio);
        goto menu;
        break;

        case 5: exit(0);
        break;

        default: printf("Opcao invalida!\n\n");
        system("pause");
        system("cls");
        goto menu;
    }

    return 0;
}
