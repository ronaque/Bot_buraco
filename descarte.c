#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char checarValor(int valor)
{
    if (valor == 1)
    {
      return 'A';
    }
    else if(valor == 10)
    {
      return '1';
    }
    else if(valor == 11)
    {
      return 'J';
    }
    else if(valor == 12)
    {
      return 'Q';
    }
    else if (valor == 13)
    {
      return 'K';
    }
    else{
      return valor + '0';
    }
}

char *descartar(Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
{
    int i;
    int distanciaD, distanciaE, maiorDistanciaD, indexDistancia;

    char valor;

    FILE* saida = fopen("descarte", "w");

    //Procurar por cartas iguais
      //Cartas iguais copas
      for (i = 0; i < indexCopas; i++)
      {
          if (maoCopas[i].numero == maoCopas[i + 1].numero)
          {
            fprintf(saida,"cartas iguais copas");
            valor = checarValor(maoCopas[i].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[i].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoCopas[i].naipe);
            }
            fclose(saida);
            return discardCard;
          }
      }
      //Cartas iguais Ouro
      for (i = 0; i < indexOuro; i++)
      {
          if (maoOuro[i].numero == maoOuro[i + 1].numero)
          {
            fprintf(saida,"cartas iguais ouro");
            valor = checarValor(maoOuro[i].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoOuro[i].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoOuro[i].naipe);
            }
            fclose(saida);
            return discardCard;
          }
      }
      //Cartas iguais Espadas
      for (i = 0; i < indexEspadas; i++)
      {
          if (maoEspadas[i].numero == maoEspadas[i + 1] .numero)
          {
            fprintf(saida,"cartas iguais espadas");
            valor = checarValor(maoEspadas[i].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoEspadas[i].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoEspadas[i].naipe);
            }
            fclose(saida);
            return discardCard;
          }
      }
      //Cartas iguais Paus
      for (i = 0; i < indexPaus; i++)
      {
          if (maoPaus[i].numero == maoPaus[i + 1].numero)
          {
            fprintf(saida,"cartas iguais paus");
            valor = checarValor(maoPaus[i].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoPaus[i].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoPaus[i].naipe);
            }
            fclose(saida);
            return discardCard;
          }
      }
    //

    //Se não houver cartas iguais, retire carta do menor index
      //Menor index Copas
      if (indexCopas < indexOuro && indexCopas <  indexEspadas && indexCopas < indexPaus && indexCopas > 0)
      {
          if (indexCopas == 1)
          {
            fprintf(saida,"index copas 1");
            valor = checarValor(maoCopas[0].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[0].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoCopas[0].naipe);
            }
            fclose(saida);
            return discardCard;
          }
          else
          {
              for (i = 0; i < indexCopas; i++)
              {
                  distanciaD = maoCopas[i + 1].numero -   maoCopas[i].numero;
                  distanciaE = maoCopas[i].numero - maoCopas  [i - 1].numero;
                  if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
                  {
                      maiorDistanciaD = distanciaD;
                      indexDistancia = i;
                  }
                  else if (maiorDistanciaD < distanciaD)
                  {
                      indexDistancia = i + 1;
                  }
                  else{
                    indexDistancia = i;
                  }
              }
          }
          fprintf(saida,"valor distante copas\n");
          valor = checarValor(maoCopas[indexDistancia].numero);
          if(valor == '1'){
            sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[indexDistancia].naipe);
          }
          else{
          sprintf(discardCard, "DISCARD %c%s",valor,maoCopas[indexDistancia].naipe);
          }
          // fprintf(saida, "%s", discardCard);
          fclose(saida);
          return discardCard;
      }
      //Menor index Ouro
      else if (indexOuro < indexCopas && indexOuro <  indexEspadas && indexOuro < indexPaus && indexOuro > 0)
      {
          if (indexOuro == 1)
          {
            fprintf(saida,"index ouro 1");
            valor = checarValor(maoOuro[0].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoOuro[0].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoOuro[0].naipe);
            }
            fclose(saida);
            return discardCard;
          }
          else
          {
              for (i = 0; i < indexOuro; i++)
              {
                  distanciaD = maoOuro[i + 1].numero -  maoOuro[i].numero;
                  distanciaE = maoOuro[i].numero - maoOuro[i  - 1].numero;
                  if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
                  {
                      maiorDistanciaD = distanciaD;
                      indexDistancia = i;
                  }
                  else if (maiorDistanciaD < distanciaD)
                  {
                      indexDistancia = i + 1;
                  }
                  else{
                    indexDistancia = i;
                  }
              }
          }
          fprintf(saida,"valor distante ouro");
          valor = checarValor(maoOuro[indexDistancia].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoOuro[indexDistancia].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoOuro[indexDistancia].naipe);
            }
            fclose(saida);
            return discardCard;
      }
      //Menor index Espadas
      else if (indexEspadas < indexOuro && indexEspadas <   indexCopas && indexEspadas < indexPaus && indexEspadas > 0)
      {
          if (indexEspadas == 1)
          {
            fprintf(saida,"index espadas 1");
            valor = checarValor(maoEspadas[0].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoEspadas[0].naipe);
            }
            else{
              sprintf(discardCard, "DISCARD %c%s",valor, maoEspadas[0].naipe);
            }
            fclose(saida);
            return discardCard;
          }
          else
          {
              for (i = 0; i < indexEspadas; i++)
              {
                  distanciaD = maoEspadas[i + 1].numero -   maoEspadas[i].numero;
                  distanciaE = maoEspadas[i].numero -   maoEspadas[i - 1].numero;
                  if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
                  {
                      maiorDistanciaD = distanciaD;
                      indexDistancia = i;
                  }
                  else if (maiorDistanciaD < distanciaD)
                  {
                      indexDistancia = i + 1;
                  }
                  else{
                    indexDistancia = i;
                  }
              }
          }
          fprintf(saida,"valor distante espadas");
          valor = checarValor(maoEspadas[indexDistancia].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoEspadas[indexDistancia].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoEspadas[indexDistancia].naipe);
            }
            fclose(saida);
            return discardCard;
      }
      //Menor index Paus
      else if (indexPaus < indexOuro && indexPaus <   indexEspadas && indexPaus < indexCopas && indexPaus > 0)
      {
          if (indexPaus == 1)
          {
            fprintf(saida,"index paus 1");
            valor = checarValor(maoPaus[0].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoPaus[0].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoPaus[0].naipe);
            }
            fclose(saida);
            return discardCard;
          }
          else
          {
              for (i = 0; i < indexPaus; i++)
              {
                  distanciaD = maoPaus[i + 1].numero -  maoPaus[i].numero;
                  distanciaE = maoPaus[i].numero - maoPaus[i  - 1].numero;
                  if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
                  {
                      maiorDistanciaD = distanciaD;
                      indexDistancia = i;
                  }
                  else if (maiorDistanciaD < distanciaD)
                  {
                      indexDistancia = i + 1;
                  }
                  else{
                    indexDistancia = i;
                  }
              }
          }
          fprintf(saida,"valor distante paus");
          valor = checarValor(maoPaus[indexDistancia].numero);
            if(valor == '1'){
              sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoPaus[indexDistancia].naipe);
            }
            else{
            sprintf(discardCard, "DISCARD %c%s",valor, maoPaus[indexDistancia].naipe);
            }
            fclose(saida);
            return discardCard;
      }
    //
    fprintf(saida, "nada");

    valor = checarValor(maoCopas[0].numero);
    if(valor == '1'){
      sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[0].naipe);
    }
    else{
    sprintf(discardCard, "DISCARD %c%s",valor, maoCopas[0].naipe);
    }

    fclose(saida);
    return discardCard;
}

void retirarDescarte(char* descartado, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
{
  int i;
  int valorDescarte, descarteUnico = 0, aux;

  char valor;
  char lixoBuffer;
  char naipeAtual[5];
  descartado = strtok(descartado, " ");
  descartado =strtok(NULL, " ");

  sscanf(descartado, "%c", &valor);

  if (valor == '1')
    {
        //Recebe o valor (1), um lixoBuffer (0), e o naipeAtual
        sscanf(descartado, "%c %c %s", &valor, &lixoBuffer, naipeAtual);
    }
    else
    {
        //Recebe somente o valor e o naipeAtual
        sscanf(descartado, "%c %s", &valor, naipeAtual);
    }

    if (valor == '1')
    {
       valorDescarte = 10;
    }
    else if (valor == 'A')
    {
       valorDescarte = 1;
    }
    else if (valor == 'J')
    {
       valorDescarte = 11;
    }
    else if (valor == 'Q')
    {
       valorDescarte = 12;
    }
    else if (valor == 'K')
    {
       valorDescarte = 13;
    }
    else
    {
       valorDescarte = valor - '0';
    }

    if ((strcmp(naipeAtual, "♥") == 0))
    {
      for (i = 0; i < indexCopas; i++)
      {
        if(valorDescarte == maoCopas[i].numero && descarteUnico == 0)
        {
          maoCopas[i].numero = 0;
          bubblesortNaipes(maoCopas, indexCopas);
          descarteUnico = 1;
        }
      }
      for (i = 0; i < indexCopas; i++)
      {
        maoCopas[i].numero = maoCopas[i + 1].numero;
      }
    }
    if ((strcmp(naipeAtual, "♦") == 0))
    {
      for (i = 0; i < indexOuro; i++)
      {
        if(valorDescarte == maoOuro[i].numero && descarteUnico == 0)
        {
          maoOuro[i].numero = 0;
          bubblesortNaipes(maoOuro, indexOuro);
          descarteUnico = 1;
        }
      }
      for (i = 0; i < indexOuro; i++)
      {
        maoOuro[i].numero = maoOuro[i + 1].numero;
      }
    }
    if ((strcmp(naipeAtual, "♠") == 0))
    {
      for (i = 0; i < indexEspadas; i++)
      {
        if(valorDescarte == maoEspadas[i].numero && descarteUnico == 0)
        {
          maoEspadas[i].numero = 0;
          bubblesortNaipes(maoEspadas, indexEspadas);
          descarteUnico = 1;
        }
      }
      for (i = 0; i < indexEspadas; i++)
      {
        maoEspadas[i].numero = maoEspadas[i + 1].numero;
      }
    }
    if ((strcmp(naipeAtual, "♣") == 0))
    {
      for (i = 0; i < indexPaus; i++)
      {
        if(valorDescarte == maoPaus[i].numero && descarteUnico == 0)
        {
          maoPaus[i].numero = 0;
          bubblesortNaipes(maoPaus, indexPaus);
          descarteUnico = 1;
        }
      }
      for (i = 0; i < indexPaus; i++)
      {
        maoPaus[i].numero = maoPaus[i + 1].numero;
      }
    }
}