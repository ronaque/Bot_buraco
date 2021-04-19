//gcc meu_bot.c -o meu_bot -g -w
//node buraco.js meu_bot bot
//node buraco.js -i test_files/teste.txt meu_bot bot

//gcc meu_bot.c -o meu_bot_debug -fsanitize=address,undefined -g
//node buraco.js meu_bot_debug bot

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "def.h"
#include "func.h"
#include "descarte.h"
#include "puxe.h"


// /** Tamanho máximo de uma linha da entrada-padrão */
// #define MAX_LINE 200

// /** Tamanho máximo do identificador do bot */
// #define ID_SIZE 20

// int indexCopas = 0, indexOuro = 0, indexPaus = 0, indexEspadas = 0, indexLixo = 0;

// char getDiscard[MAX_LINE];
// char discardCard[MAX_LINE];

// typedef struct cartas
// {
//     int numero;
//     char naipe[5];
// } Carta;

//  Lê uma linha da entrada padrão e remove o '\n' se necessário.
void readline(char *line)
{
    fgets(line, MAX_LINE, stdin);
    int l = strlen(line) - 1;
    if (line[l] == '\n')
    {
        line[l] = '\0';
    }
}

// void bubblesortNaipes(Carta *mao, int index)
// {
//     Carta aux;

//     for (int i = 0; i < index - 1; i++)
//     {
//         for (int k = i + 1; k < index; k++)
//         {
//             //Ordenação por pontos
//             if (mao[i].numero > mao[k].numero)
//             {
//                 aux = mao[i];
//                 mao[i] = mao[k];
//                 mao[k] = aux;
//             }
//         }
//     }
// }

// void valorCarta(char *carta, Carta *mao)
// {
//     char valor;
//     char lixoBuffer;
//     char naipeAtual[5];

//     sscanf(carta, "%c", &valor);

//     if (valor == '1')
//     {
//         //Recebe o valor (1), um lixoBuffer (0), e o naipeAtual
//         sscanf(carta, "%c %c %s", &valor, &lixoBuffer, naipeAtual);
//     }
//     else
//     {
//         //Recebe somente o valor e o naipeAtual
//         sscanf(carta, "%c %s", &valor, naipeAtual);
//     }

//     //Colocando o valor recebido
//     if (valor == '1')
//     {
//         mao->numero = 10;
//     }
//     else if (valor == 'A')
//     {
//         mao->numero = 1;
//     }
//     else if (valor == 'J')
//     {
//         mao->numero = 11;
//     }
//     else if (valor == 'Q')
//     {
//         mao->numero = 12;
//     }
//     else if (valor == 'K')
//     {
//         mao->numero = 13;
//     }
//     else
//     {
//         mao->numero = valor - '0';
//     }

//     strcpy(mao->naipe, naipeAtual);
// }

// void tratamentoNaipe(Carta *mao, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
// {
//     if ((strcmp(mao->naipe, "♥") == 0))
//     {
//         strcpy(maoCopas[indexCopas].naipe, mao->naipe);
//         maoCopas[indexCopas].numero = mao->numero;
//         indexCopas++;
//     }
//     if ((strcmp(mao->naipe, "♦") == 0))
//     {
//         strcpy(maoOuro[indexOuro].naipe, mao->naipe);
//         maoOuro[indexOuro].numero = mao->numero;
//         indexOuro++;
//     }
//     if ((strcmp(mao->naipe, "♠") == 0))
//     {
//         strcpy(maoEspadas[indexEspadas].naipe, mao->naipe);
//         maoEspadas[indexEspadas].numero = mao->numero;
//         indexEspadas++;
//     }
//     if ((strcmp(mao->naipe, "♣") == 0))
//     {
//         strcpy(maoPaus[indexPaus].naipe, mao->naipe);
//         maoPaus[indexPaus].numero = mao->numero;
//         indexPaus++;
//     }
// }

// void printMaoNaipes(Carta *mao, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus, FILE *saida)
// {
//     int i = 0;
//     //Print Mão Copas
//     fprintf(saida, "Mao copas: [ ");
//     for (i = 0; i < indexCopas; i++)
//     {
//         fprintf(saida, "%d%s ", maoCopas[i].numero, maoCopas[i].naipe);
//     }
//     fprintf(saida, "] index: %d\n", indexCopas);

//     //Print Mão Ouro
//     fprintf(saida, "Mao ouro: [ ");
//     for (i = 0; i < indexOuro; i++)
//     {
//         fprintf(saida, "%d%s ", maoOuro[i].numero, maoOuro[i].naipe);
//     }
//     fprintf(saida, "] index: %d\n", indexOuro);

//     //Print Mão Espadas
//     fprintf(saida, "Mao espadas: [ ");
//     for (i = 0; i < indexEspadas; i++)
//     {
//         fprintf(saida, "%d%s ", maoEspadas[i].numero, maoEspadas[i].naipe);
//     }
//     fprintf(saida, "] index: %d\n", indexEspadas);

//     //Print Mão Paus
//     fprintf(saida, "Mao Paus: [ ");
//     for (i = 0; i < indexPaus; i++)
//     {
//         fprintf(saida, "%d%s ", maoPaus[i].numero, maoPaus[i].naipe);
//     }
//     fprintf(saida, "] index: %d\n", indexPaus);
// }

// char checarValor(int valor)
// {
//     if (valor == 1)
//     {
//       return 'A';
//     }
//     else if(valor == 10)
//     {
//       return '1';
//     }
//     else if(valor == 11)
//     {
//       return 'J';
//     }
//     else if(valor == 12)
//     {
//       return 'Q';
//     }
//     else if (valor == 13)
//     {
//       return 'K';
//     }
//     else{
//       return valor + '0';
//     }
// }

// char *descartar(Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
// {
//     int i;
//     int distanciaD, distanciaE, maiorDistanciaD, indexDistancia;

//     char valor;

  

//     //Procurar por cartas iguais
//       //Cartas iguais copas
//       for (i = 0; i < indexCopas; i++)
//       {
//           if (maoCopas[i].numero == maoCopas[i + 1].numero)
//           {
            
//             valor = checarValor(maoCopas[i].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[i].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoCopas[i].naipe);
//             }
           
//             return discardCard;
//           }
//       }
//       //Cartas iguais Ouro
//       for (i = 0; i < indexOuro; i++)
//       {
//           if (maoOuro[i].numero == maoOuro[i + 1].numero)
//           {
            
//             valor = checarValor(maoOuro[i].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoOuro[i].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoOuro[i].naipe);
//             }
           
//             return discardCard;
//           }
//       }
//       //Cartas iguais Espadas
//       for (i = 0; i < indexEspadas; i++)
//       {
//           if (maoEspadas[i].numero == maoEspadas[i + 1] .numero)
//           {
            
//             valor = checarValor(maoEspadas[i].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoEspadas[i].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoEspadas[i].naipe);
//             }
           
//             return discardCard;
//           }
//       }
//       //Cartas iguais Paus
//       for (i = 0; i < indexPaus; i++)
//       {
//           if (maoPaus[i].numero == maoPaus[i + 1].numero)
//           {
            
//             valor = checarValor(maoPaus[i].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoPaus[i].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoPaus[i].naipe);
//             }
           
//             return discardCard;
//           }
//       }
//     //

//     //Se não houver cartas iguais, retire carta do menor index
//       //Menor index Copas
//       if (indexCopas < indexOuro && indexCopas <  indexEspadas && indexCopas < indexPaus && indexCopas > 0)
//       {
//           if (indexCopas == 1)
//           {
            
//             valor = checarValor(maoCopas[0].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[0].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoCopas[0].naipe);
//             }
           
//             return discardCard;
//           }
//           else
//           {
//               for (i = 0; i < indexCopas; i++)
//               {
//                   distanciaD = maoCopas[i + 1].numero -   maoCopas[i].numero;
//                   distanciaE = maoCopas[i].numero - maoCopas  [i - 1].numero;
//                   if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
//                   {
//                       maiorDistanciaD = distanciaD;
//                       indexDistancia = i;
//                   }
//                   else if (maiorDistanciaD < distanciaD)
//                   {
//                       indexDistancia = i + 1;
//                   }
//                   else{
//                     indexDistancia = i;
//                   }
//               }
//           }
          
//           valor = checarValor(maoCopas[indexDistancia].numero);
//           if(valor == '1'){
//             sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[indexDistancia].naipe);
//           }
//           else{
//           sprintf(discardCard, "DISCARD %c%s",valor,maoCopas[indexDistancia].naipe);
//           }
//           // 
         
//           return discardCard;
//       }
//       //Menor index Ouro
//       else if (indexOuro < indexCopas && indexOuro <  indexEspadas && indexOuro < indexPaus && indexOuro > 0)
//       {
//           if (indexOuro == 1)
//           {
            
//             valor = checarValor(maoOuro[0].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoOuro[0].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoOuro[0].naipe);
//             }
           
//             return discardCard;
//           }
//           else
//           {
//               for (i = 0; i < indexOuro; i++)
//               {
//                   distanciaD = maoOuro[i + 1].numero -  maoOuro[i].numero;
//                   distanciaE = maoOuro[i].numero - maoOuro[i  - 1].numero;
//                   if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
//                   {
//                       maiorDistanciaD = distanciaD;
//                       indexDistancia = i;
//                   }
//                   else if (maiorDistanciaD < distanciaD)
//                   {
//                       indexDistancia = i + 1;
//                   }
//                   else{
//                     indexDistancia = i;
//                   }
//               }
//           }
          
//           valor = checarValor(maoOuro[indexDistancia].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoOuro[indexDistancia].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoOuro[indexDistancia].naipe);
//             }
           
//             return discardCard;
//       }
//       //Menor index Espadas
//       else if (indexEspadas < indexOuro && indexEspadas <   indexCopas && indexEspadas < indexPaus && indexEspadas > 0)
//       {
//           if (indexEspadas == 1)
//           {
            
//             valor = checarValor(maoEspadas[0].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoEspadas[0].naipe);
//             }
//             else{
//               sprintf(discardCard, "DISCARD %c%s",valor, maoEspadas[0].naipe);
//             }
           
//             return discardCard;
//           }
//           else
//           {
//               for (i = 0; i < indexEspadas; i++)
//               {
//                   distanciaD = maoEspadas[i + 1].numero -   maoEspadas[i].numero;
//                   distanciaE = maoEspadas[i].numero -   maoEspadas[i - 1].numero;
//                   if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
//                   {
//                       maiorDistanciaD = distanciaD;
//                       indexDistancia = i;
//                   }
//                   else if (maiorDistanciaD < distanciaD)
//                   {
//                       indexDistancia = i + 1;
//                   }
//                   else{
//                     indexDistancia = i;
//                   }
//               }
//           }
          
//           valor = checarValor(maoEspadas[indexDistancia].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoEspadas[indexDistancia].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoEspadas[indexDistancia].naipe);
//             }
           
//             return discardCard;
//       }
//       //Menor index Paus
//       else if (indexPaus < indexOuro && indexPaus <   indexEspadas && indexPaus < indexCopas && indexPaus > 0)
//       {
//           if (indexPaus == 1)
//           {
            
//             valor = checarValor(maoPaus[0].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoPaus[0].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoPaus[0].naipe);
//             }
           
//             return discardCard;
//           }
//           else
//           {
//               for (i = 0; i < indexPaus; i++)
//               {
//                   distanciaD = maoPaus[i + 1].numero -  maoPaus[i].numero;
//                   distanciaE = maoPaus[i].numero - maoPaus[i  - 1].numero;
//                   if (maiorDistanciaD < distanciaD &&   distanciaE > 1)
//                   {
//                       maiorDistanciaD = distanciaD;
//                       indexDistancia = i;
//                   }
//                   else if (maiorDistanciaD < distanciaD)
//                   {
//                       indexDistancia = i + 1;
//                   }
//                   else{
//                     indexDistancia = i;
//                   }
//               }
//           }
          
//           valor = checarValor(maoPaus[indexDistancia].numero);
//             if(valor == '1'){
//               sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoPaus[indexDistancia].naipe);
//             }
//             else{
//             sprintf(discardCard, "DISCARD %c%s",valor, maoPaus[indexDistancia].naipe);
//             }
           
//             return discardCard;
//       }
//     //
    

//     valor = checarValor(maoCopas[0].numero);
//     if(valor == '1'){
//       sprintf(discardCard, "DISCARD %c%c%s",valor, '0', maoCopas[0].naipe);
//     }
//     else{
//     sprintf(discardCard, "DISCARD %c%s",valor, maoCopas[0].naipe);
//     }

   
//     return discardCard;
// }

// char *puxar(Carta *lixo, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
// {
//     int i;

//     if ((strcmp(lixo->naipe, "♥") == 0))
//     {
//         for (i = 0; i < indexCopas; i++)
//         {
//             //Valor de lixo está entre 2 valores
//             if (lixo->numero == maoCopas[i].numero + 1 && lixo->numero == maoCopas[i + 1].numero - 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoCopas[i].numero, maoCopas[i].naipe, maoCopas[i + 1].numero, maoCopas[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está depois dos 2 valores
//             else if (lixo->numero == maoCopas[i].numero + 2 && lixo->numero == maoCopas[i + 1].numero + 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoCopas[i].numero, maoCopas[i].naipe, maoCopas[i + 1].numero, maoCopas[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está antes dos 2 valores
//             else if (lixo->numero == maoCopas[i].numero - 1 && lixo->numero == maoCopas[i + 1].numero - 2)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoCopas[i].numero, maoCopas[i].naipe, maoCopas[i + 1].numero, maoCopas[i + 1].naipe);
//                 return getDiscard;
//             }
//         }
//     }
//     if ((strcmp(lixo->naipe, "♦") == 0))
//     {
//         for (i = 0; i < indexOuro; i++)
//         {
//             //Valor de lixo está entre 2 valores
//             if (lixo->numero == maoOuro[i].numero + 1 && lixo->numero == maoOuro[i + 1].numero - 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoOuro[i].numero, maoOuro[i].naipe, maoOuro[i + 1].numero, maoOuro[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está depois dos 2 valores
//             else if (lixo->numero == maoOuro[i].numero + 2 && lixo->numero == maoOuro[i + 1].numero + 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoOuro[i].numero, maoOuro[i].naipe, maoOuro[i + 1].numero, maoOuro[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está antes dos 2 valores
//             else if (lixo->numero == maoOuro[i].numero - 1 && lixo->numero == maoOuro[i + 1].numero - 2)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoOuro[i].numero, maoOuro[i].naipe, maoOuro[i + 1].numero, maoOuro[i + 1].naipe);
//                 return getDiscard;
//             }
//         }
//     }
//     if ((strcmp(lixo->naipe, "♠") == 0))
//     {
//         for (i = 0; i < indexEspadas; i++)
//         {
//             //Valor de lixo está entre 2 valores
//             if (lixo->numero == maoEspadas[i].numero + 1 && lixo->numero == maoEspadas[i + 1].numero - 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoEspadas[i].numero, maoEspadas[i].naipe, maoEspadas[i + 1].numero, maoEspadas[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está depois dos 2 valores
//             else if (lixo->numero == maoEspadas[i].numero + 2 && lixo->numero == maoEspadas[i + 1].numero + 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoEspadas[i].numero, maoEspadas[i].naipe, maoEspadas[i + 1].numero, maoEspadas[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está antes dos 2 valores
//             else if (lixo->numero == maoEspadas[i].numero - 1 && lixo->numero == maoEspadas[i + 1].numero - 2)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoEspadas[i].numero, maoEspadas[i].naipe, maoEspadas[i + 1].numero, maoEspadas[i + 1].naipe);
//                 return getDiscard;
//             }
//         }
//     }
//     if ((strcmp(lixo->naipe, "♣") == 0))
//     {
//         for (i = 0; i < indexPaus; i++)
//         {
//             //Valor de lixo está entre 2 valores
//             if (lixo->numero == maoPaus[i].numero + 1 && lixo->numero == maoPaus[i + 1].numero - 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoPaus[i].numero, maoPaus[i].naipe, maoPaus[i + 1].numero, maoPaus[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está depois dos 2 valores
//             else if (lixo->numero == maoPaus[i].numero + 2 && lixo->numero == maoPaus[i + 1].numero + 1)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoPaus[i].numero, maoPaus[i].naipe, maoPaus[i + 1].numero, maoPaus[i + 1].naipe);
//                 return getDiscard;
//             }
//             //Valor de lixo está antes dos 2 valores
//             else if (lixo->numero == maoPaus[i].numero - 1 && lixo->numero == maoPaus[i + 1].numero - 2)
//             {
//                 sprintf(getDiscard, "GET_DISCARD [ %d%s %d%s ]", maoPaus[i].numero, maoPaus[i].naipe, maoPaus[i + 1].numero, maoPaus[i + 1].naipe);
//                 return getDiscard;
//             }
//         }
//     }

//     strcpy(getDiscard, "GET_STOCK");
//     return getDiscard;
// }

// void retirarDescarte(char* descartado, Carta *maoCopas, Carta *maoOuro, Carta *maoEspadas, Carta *maoPaus)
// {
//   int i;
//   int valorDescarte, descarteUnico = 0, aux;

//   char valor;
//   char lixoBuffer;
//   char naipeAtual[5];
//   descartado = strtok(descartado, " ");
//   descartado =strtok(NULL, " ");

//   sscanf(descartado, "%c", &valor);

//   if (valor == '1')
//     {
//         //Recebe o valor (1), um lixoBuffer (0), e o naipeAtual
//         sscanf(descartado, "%c %c %s", &valor, &lixoBuffer, naipeAtual);
//     }
//     else
//     {
//         //Recebe somente o valor e o naipeAtual
//         sscanf(descartado, "%c %s", &valor, naipeAtual);
//     }

//     if (valor == '1')
//     {
//        valorDescarte = 10;
//     }
//     else if (valor == 'A')
//     {
//        valorDescarte = 1;
//     }
//     else if (valor == 'J')
//     {
//        valorDescarte = 11;
//     }
//     else if (valor == 'Q')
//     {
//        valorDescarte = 12;
//     }
//     else if (valor == 'K')
//     {
//        valorDescarte = 13;
//     }
//     else
//     {
//        valorDescarte = valor - '0';
//     }

//     if ((strcmp(naipeAtual, "♥") == 0))
//     {
//       for (i = 0; i < indexCopas; i++)
//       {
//         if(valorDescarte == maoCopas[i].numero && descarteUnico == 0)
//         {
//           maoCopas[i].numero = 0;
//           bubblesortNaipes(maoCopas, indexCopas);
//           descarteUnico = 1;
//         }
//       }
//       for (i = 0; i < indexCopas; i++)
//       {
//         maoCopas[i].numero = maoCopas[i + 1].numero;
//       }
//     }
//     if ((strcmp(naipeAtual, "♦") == 0))
//     {
//       for (i = 0; i < indexOuro; i++)
//       {
//         if(valorDescarte == maoOuro[i].numero && descarteUnico == 0)
//         {
//           maoOuro[i].numero = 0;
//           bubblesortNaipes(maoOuro, indexOuro);
//           descarteUnico = 1;
//         }
//       }
//       for (i = 0; i < indexOuro; i++)
//       {
//         maoOuro[i].numero = maoOuro[i + 1].numero;
//       }
//     }
//     if ((strcmp(naipeAtual, "♠") == 0))
//     {
//       for (i = 0; i < indexEspadas; i++)
//       {
//         if(valorDescarte == maoEspadas[i].numero && descarteUnico == 0)
//         {
//           maoEspadas[i].numero = 0;
//           bubblesortNaipes(maoEspadas, indexEspadas);
//           descarteUnico = 1;
//         }
//       }
//       for (i = 0; i < indexEspadas; i++)
//       {
//         maoEspadas[i].numero = maoEspadas[i + 1].numero;
//       }
//     }
//     if ((strcmp(naipeAtual, "♣") == 0))
//     {
//       for (i = 0; i < indexPaus; i++)
//       {
//         if(valorDescarte == maoPaus[i].numero && descarteUnico == 0)
//         {
//           maoPaus[i].numero = 0;
//           bubblesortNaipes(maoPaus, indexPaus);
//           descarteUnico = 1;
//         }
//       }
//       for (i = 0; i < indexPaus; i++)
//       {
//         maoPaus[i].numero = maoPaus[i + 1].numero;
//       }
//     }
// }

int main()
{
    char line[MAX_LINE]; // dados temporários
    char myId[ID_SIZE];  // identificador do bot

    FILE *saida = fopen("saida", "w");

    //Stdin, stdout e stderr não terão buffers, assim, nada é "guardado temporariamente"
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    setbuf(saida, NULL);
    //

    int i;

    char valor;
    char lixoBuffer;
    char naipeAtual[5];
    char loop[MAX_LINE];
    char *cartas;
    char *descarte;

    Carta *mao;
    Carta *maoCopas;
    Carta *maoOuro;
    Carta *maoPaus;
    Carta *maoEspadas;

    Carta *lixo;

    mao = malloc(sizeof(Carta) * 11);
    maoCopas = malloc(sizeof(Carta) * (indexCopas + 1));
    maoOuro = malloc(sizeof(Carta) * (indexOuro + 1));
    maoEspadas = malloc(sizeof(Carta) * (indexEspadas + 1));
    maoPaus = malloc(sizeof(Carta) * (indexPaus + 1));

    lixo = malloc(sizeof(Carta) * (indexLixo + 1));

    // DADOS DO INÍCIO DA PARTIDA

    //Leituras iniciais: Identificadores de todos bots | Identificador do bot
    // lê os identificadores dos jogadores (descartavel)
    readline(line);
    fprintf(saida, "Indentificadores de todos bots: %s\n", line);
    // lê o identificador do bot (seu id)
    readline(line);
    fprintf(saida, "Identificador do meu bot: %s ", line);
    //Armazena o id do bot que foi lido anteriormente
    strncpy(myId, line, ID_SIZE);
    fprintf(saida, "myID: %s\n", myId);

    //

    //Guardar as cartas iniciais
    readline(line);
    fprintf(saida, "Cartas iniciais: %s\n", line);

    //Leitura das cartas separadamente e armazenamento
    cartas = strtok(line, " ");
    cartas = strtok(NULL, " ");

    //Recebendo os números da mão inicial | Separação da mão em naipes
    for (i = 0; i < 11; i++)
    {

        //Colocando o valor da carta
        valorCarta(cartas, &mao[i]);

        //Separação da mão em naipes
        maoCopas = realloc(maoCopas, sizeof(Carta) * (indexCopas + 1));
        maoOuro = realloc(maoOuro, sizeof(Carta) * (indexOuro + 1));
        maoEspadas = realloc(maoEspadas, sizeof(Carta) * (indexEspadas + 1));
        maoPaus = realloc(maoPaus, sizeof(Carta) * (indexPaus + 1));

        tratamentoNaipe(&mao[i], maoCopas, maoOuro, maoEspadas, maoPaus);

        //Printa a carta atual
        fprintf(saida, "Carta[%d]: %d%s\n", i, mao[i].numero, mao[i].naipe);

        cartas = strtok(NULL, " ");
    }

    //Ordenação das mãos iniciais de cada naipe
    bubblesortNaipes(maoCopas, indexCopas);
    bubblesortNaipes(maoOuro, indexOuro);
    bubblesortNaipes(maoEspadas, indexEspadas);
    bubblesortNaipes(maoPaus, indexPaus);
    //


    //Print da mao dividida em naipes
    printMaoNaipes(&mao[i], maoCopas, maoOuro, maoEspadas, maoPaus, saida);
    //

    //Lê a carta inicial da pilha de descarte.
    readline(line);

    fprintf(saida, "\n");
    fprintf(saida, "\n");

    //Definição da carta inicial do lixo
    fprintf(saida, "lixo: %s\n", line);

    //Definição do lixo
    valorCarta(line, &lixo[indexLixo]);
    //

    //Print carta do lixo
    fprintf(saida, "Carta do lixo: %d%s\n", lixo[indexLixo].numero, lixo[indexLixo].naipe);
    indexLixo++;

    fprintf(saida, "\n");
    fprintf(saida, "\n");

    //Libera a mão inicial
    free(mao);

    //Loop infinito gerenciado pelo juiz
    while (1)
    { // DADOS DURANTE A PARTIDA
        do
        { // lê e descarta os dados até chegar sua vez

            // sai do laço quando for enviado seu id
            readline(line);

            // exemplo de saída para debugar
            //fprintf(saida, "Loop: %s\n", line);

            //Verificar se o adversario deu o comando discard para atualizar o lixo
            sscanf(line, "%s", loop);
            //fprintf(saida,"variavel loop: %s\n", loop);
            if (strcmp(loop, "DISCARD") == 0)
            {
                descarte = strtok(line, " ");
                descarte = strtok(NULL, " ");
                fprintf(saida, "Descarte: %s\n", descarte);

                lixo = realloc(lixo, sizeof(Carta) * (indexLixo + 1));
                valorCarta(descarte, &lixo[indexLixo]);

                fprintf(saida, "Topo do lixo: %d%s\n", lixo[indexLixo].numero, lixo[indexLixo].naipe);
                indexLixo++;
            }

            //Verificar se o adversario deu o comando GET_DISCARD, neste caso é necessario zerar o lixo
            if (strcmp(line, "GET_DISCARD") == 0)
            {
                free(lixo);
                indexLixo = 0;
            }
        } while (strcmp(line, myId)); // sai do laço quando for a sua vez!

        for (i = 0; i < indexLixo; i++)
        {
            fprintf(saida, "%d%s ", lixo[i].numero, lixo[i].naipe);
        }
        fprintf(saida, "index lixo: %d\n", indexLixo);

        //Envia a ação para puxar uma carta

        //Tratamento de qual puxe quer fazer
        char *acaoPuxar = puxar(&lixo[indexLixo - 1], maoCopas, maoOuro, maoEspadas, maoPaus);

        //Enviar qual puxe vai fazer
        fprintf(saida, "%s\n", acaoPuxar);
        printf("%s\n", acaoPuxar);

        //Puxar do deque de compra
        //Recebe a carta do deque de compra
        readline(line);
        fprintf(saida, "Carta do deque de compra: %s\n", line);

        //Recebimento da carta para a mão geral
        mao = malloc(sizeof(Carta) * 1);
        valorCarta(line, &mao[0]);
        fprintf(saida, "Carta recebida: %d%s\n", mao[0].numero, mao[0].naipe);

        //Separação da carta recebida para o naipe  correspondente
        maoCopas = realloc(maoCopas, sizeof(Carta) * (indexCopas + 1));
        maoOuro = realloc(maoOuro, sizeof(Carta) * (indexOuro + 1));
        maoEspadas = realloc(maoEspadas, sizeof(Carta) * (indexEspadas + 1));
        maoPaus = realloc(maoPaus, sizeof(Carta) * (indexPaus + 1));

        tratamentoNaipe(&mao[0], maoCopas, maoOuro, maoEspadas, maoPaus);

        //Ordenação das mãos de cada naipe
        bubblesortNaipes(maoCopas, indexCopas);
        bubblesortNaipes(maoOuro, indexOuro);
        bubblesortNaipes(maoEspadas, indexEspadas);
        bubblesortNaipes(maoPaus, indexPaus);
        //

        //Print das mãos
        printMaoNaipes(&mao[i], maoCopas, maoOuro, maoEspadas, maoPaus, saida);

        fprintf(saida, "\n");
        fprintf(saida, "\n");
        //

        //Descarta a carta que puxou
        char *acaoDescarte = descartar(maoCopas, maoOuro, maoEspadas, maoPaus);
        fprintf(saida, "Carta descartada: %s\n", acaoDescarte);
        printf("%s\n", acaoDescarte);

        // retirarDescarte(acaoDescarte, maoCopas, maoOuro, maoEspadas, maoPaus);
        // sscanf(acaoDescarte, "%c", &valor);

        // if (valor == '1')
        // {
        //     //Recebe o valor (1), um lixoBuffer (0), e o    naipeAtual
        //     sscanf(acaoDescarte, "%c %c %s", &valor, &    lixoBuffer, naipeAtual);
        // }
        // else
        // {
        //     //Recebe somente o valor e o naipeAtual
        //     sscanf(acaoDescarte, "%c %s", &valor, naipeAtual);
        // }
        // if ((strcmp(naipeAtual, "♥") == 0))
        // {
        //   indexCopas--;
        //   maoCopas = realloc(maoCopas, sizeof(Carta) * indexCopas);
        // }
        // if ((strcmp(naipeAtual, "♦") == 0))
        // {
        //   indexOuro--;
        //   maoOuro = realloc(maoOuro, sizeof(Carta) * indexOuro);
        // }
        // if ((strcmp(naipeAtual, "♠") == 0))
        // {
        //   indexEspadas--;
        //   maoEspadas = realloc(maoEspadas, sizeof(Carta) * indexEspadas);
        // }
        // if ((strcmp(naipeAtual, "♣") == 0))
        // {
        //   indexPaus--;
        //   maoPaus = realloc(maoPaus, sizeof(Carta) * indexPaus);
        // }

    }
    return 0;
}