#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEGRITO '*'
#define ITALICO '/'
#define SUBLINHADO '_'

typedef struct Pilha
{
    char marcador;
    struct Pilha *proxima;
} Pilha;

Pilha *pilha = NULL;

void push(char marcador)
{
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    novaPilha->marcador = marcador;
    novaPilha->proxima = pilha;
    pilha = novaPilha;
}

char pop()
{
    Pilha *temp = pilha;
    pilha = pilha->proxima;
    free(temp);
}

char top()
{
    return pilha->marcador;
}

int estaVazia()
{
    return pilha == NULL;
}

void marcar(char marcador)
{
    if (!estaVazia() && top() == marcador)
    {
        pop();
    }
    else
    {
        push(marcador);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n + 1; i++) 
    {
        char texto[1000001];
        fgets(texto, 1000001, stdin);
        int len = strlen(texto);

        for (int j = 0; j < len -1; j++) 
        {
            switch (texto[j]) {
                case SUBLINHADO:
                    marcar(SUBLINHADO);
                    break;
                case NEGRITO:
                    marcar(NEGRITO);
                    break;
                case ITALICO:
                    marcar(ITALICO);
                    break;
            }
        }
        
    }
    if (estaVazia()) {
        printf("C\n");
        return 0;
    }
            
    else {
        printf("E\n");
        return 0;
    }
}
