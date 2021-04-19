#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "def.h"

void bubblesortNaipes(Carta *mao, int index)
{
    Carta aux;

    for (int i = 0; i < index - 1; i++)
    {
        for (int k = i + 1; k < index; k++)
        {
            //Ordenação por pontos
            if (mao[i].numero > mao[k].numero)
            {
                aux = mao[i];
                mao[i] = mao[k];
                mao[k] = aux;
            }
        }
    }
}

void valorCarta(char *carta, Carta *mao)
{
    char valor;
    char lixoBuffer;
    char naipeAtual[5];

    sscanf(carta, "%c", &valor);

    if (valor == '1')
    {
        //Recebe o valor (1), um lixoBuffer (0), e o naipeAtual
        sscanf(carta, "%c %c %s", &valor, &lixoBuffer, naipeAtual);
    }
    else
    {
        //Recebe somente o valor e o naipeAtual
        sscanf(carta, "%c %s", &valor, naipeAtual);
    }

    //Colocando o valor recebido
    if (valor == '1')
    {
        mao->numero = 10;
    }
    else if (valor == 'A')
    {
        mao->numero = 1;
    }
    else if (valor == 'J')
    {
        mao->numero = 11;
    }
    else if (valor == 'Q')
    {
        mao->numero = 12;
    }
    else if (valor == 'K')
    {
        mao->numero = 13;
    }
    else
    {
        mao->numero = valor - '0';
    }

    strcpy(mao->naipe, naipeAtual);
}

void tratamentoNaipe(Carta *mao, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
{
    if ((strcmp(mao->naipe, "♥") == 0))
    {
        strcpy(maoCopas[indexCopas].naipe, mao->naipe);
        maoCopas[indexCopas].numero = mao->numero;
        indexCopas++;
    }
    if ((strcmp(mao->naipe, "♦") == 0))
    {
        strcpy(maoOuro[indexOuro].naipe, mao->naipe);
        maoOuro[indexOuro].numero = mao->numero;
        indexOuro++;
    }
    if ((strcmp(mao->naipe, "♠") == 0))
    {
        strcpy(maoEspadas[indexEspadas].naipe, mao->naipe);
        maoEspadas[indexEspadas].numero = mao->numero;
        indexEspadas++;
    }
    if ((strcmp(mao->naipe, "♣") == 0))
    {
        strcpy(maoPaus[indexPaus].naipe, mao->naipe);
        maoPaus[indexPaus].numero = mao->numero;
        indexPaus++;
    }
}

void printMaoNaipes(Carta *mao, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus, FILE *saida)
{
    int i = 0;
    //Print Mão Copas
    fprintf(saida, "Mao copas: [ ");
    for (i = 0; i < indexCopas; i++)
    {
        fprintf(saida, "%d%s ", maoCopas[i].numero, maoCopas[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexCopas);

    //Print Mão Ouro
    fprintf(saida, "Mao ouro: [ ");
    for (i = 0; i < indexOuro; i++)
    {
        fprintf(saida, "%d%s ", maoOuro[i].numero, maoOuro[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexOuro);

    //Print Mão Espadas
    fprintf(saida, "Mao espadas: [ ");
    for (i = 0; i < indexEspadas; i++)
    {
        fprintf(saida, "%d%s ", maoEspadas[i].numero, maoEspadas[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexEspadas);

    //Print Mão Paus
    fprintf(saida, "Mao Paus: [ ");
    for (i = 0; i < indexPaus; i++)
    {
        fprintf(saida, "%d%s ", maoPaus[i].numero, maoPaus[i].naipe);
    }
    fprintf(saida, "] index: %d\n", indexPaus);
}