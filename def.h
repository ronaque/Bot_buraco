/** Tamanho máximo de uma linha da entrada-padrão */
#define MAX_LINE 200

/** Tamanho máximo do identificador do bot */
#define ID_SIZE 20

int indexCopas = 0, indexOuro = 0, indexPaus = 0, indexEspadas = 0, indexLixo = 0;

char getDiscard[MAX_LINE];
char discardCard[MAX_LINE];

typedef struct cartas
{
    int numero;
    char naipe[5];
} Carta;