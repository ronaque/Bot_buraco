#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *puxar(Carta *lixo, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
{
    int i;

    if ((strcmp(lixo->naipe, "♥") == 0))
    {
        for (i = 0; i < indexCopas; i++)
        {
            //Valor de lixo está entre 2 valores
            if (lixo->numero == maoCopas[i].numero + 1 && lixo->numero == maoCopas[i + 1].numero - 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoCopas[i].numero, maoCopas[i].naipe, maoCopas[i + 1].numero, maoCopas[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está depois dos 2 valores
            else if (lixo->numero == maoCopas[i].numero + 2 && lixo->numero == maoCopas[i + 1].numero + 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoCopas[i].numero, maoCopas[i].naipe, maoCopas[i + 1].numero, maoCopas[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está antes dos 2 valores
            else if (lixo->numero == maoCopas[i].numero - 1 && lixo->numero == maoCopas[i + 1].numero - 2)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoCopas[i].numero, maoCopas[i].naipe, maoCopas[i + 1].numero, maoCopas[i + 1].naipe);
                return getDiscard;
            }
        }
    }
    if ((strcmp(lixo->naipe, "♦") == 0))
    {
        for (i = 0; i < indexOuro; i++)
        {
            //Valor de lixo está entre 2 valores
            if (lixo->numero == maoOuro[i].numero + 1 && lixo->numero == maoOuro[i + 1].numero - 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoOuro[i].numero, maoOuro[i].naipe, maoOuro[i + 1].numero, maoOuro[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está depois dos 2 valores
            else if (lixo->numero == maoOuro[i].numero + 2 && lixo->numero == maoOuro[i + 1].numero + 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoOuro[i].numero, maoOuro[i].naipe, maoOuro[i + 1].numero, maoOuro[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está antes dos 2 valores
            else if (lixo->numero == maoOuro[i].numero - 1 && lixo->numero == maoOuro[i + 1].numero - 2)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoOuro[i].numero, maoOuro[i].naipe, maoOuro[i + 1].numero, maoOuro[i + 1].naipe);
                return getDiscard;
            }
        }
    }
    if ((strcmp(lixo->naipe, "♠") == 0))
    {
        for (i = 0; i < indexEspadas; i++)
        {
            //Valor de lixo está entre 2 valores
            if (lixo->numero == maoEspadas[i].numero + 1 && lixo->numero == maoEspadas[i + 1].numero - 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoEspadas[i].numero, maoEspadas[i].naipe, maoEspadas[i + 1].numero, maoEspadas[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está depois dos 2 valores
            else if (lixo->numero == maoEspadas[i].numero + 2 && lixo->numero == maoEspadas[i + 1].numero + 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoEspadas[i].numero, maoEspadas[i].naipe, maoEspadas[i + 1].numero, maoEspadas[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está antes dos 2 valores
            else if (lixo->numero == maoEspadas[i].numero - 1 && lixo->numero == maoEspadas[i + 1].numero - 2)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoEspadas[i].numero, maoEspadas[i].naipe, maoEspadas[i + 1].numero, maoEspadas[i + 1].naipe);
                return getDiscard;
            }
        }
    }
    if ((strcmp(lixo->naipe, "♣") == 0))
    {
        for (i = 0; i < indexPaus; i++)
        {
            //Valor de lixo está entre 2 valores
            if (lixo->numero == maoPaus[i].numero + 1 && lixo->numero == maoPaus[i + 1].numero - 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoPaus[i].numero, maoPaus[i].naipe, maoPaus[i + 1].numero, maoPaus[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está depois dos 2 valores
            else if (lixo->numero == maoPaus[i].numero + 2 && lixo->numero == maoPaus[i + 1].numero + 1)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoPaus[i].numero, maoPaus[i].naipe, maoPaus[i + 1].numero, maoPaus[i + 1].naipe);
                return getDiscard;
            }
            //Valor de lixo está antes dos 2 valores
            else if (lixo->numero == maoPaus[i].numero - 1 && lixo->numero == maoPaus[i + 1].numero - 2)
            {
                sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoPaus[i].numero, maoPaus[i].naipe, maoPaus[i + 1].numero, maoPaus[i + 1].naipe);
                return getDiscard;
            }
        }
    }

    strcpy(getDiscard, "GET_STOCK");
    return getDiscard;
}