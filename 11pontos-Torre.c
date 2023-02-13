#include <stdio.h>

#define MAX_L 1000
#define MAX_C 1000

// função que percorre a matriz e conta os pontos '.'
int count_dots(char matriz[][MAX_C], int linha, int col)
{
    int count = 0;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < col; j++)
            if (matriz[i][j] == '.')
                count++;
    }
    return count;
}

// função que adiciona os pontos na matriz
void add_dots(char matriz[][MAX_C], int linha, int col, int *dots)
{
    int k = 0;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // verifica se tem um 't' na matriz
            if (matriz[i][j] == 't')
            {
                // quanto tiver 't' na matriz verifica ao redor 
                for (int x = i - dots[k]; x <= i + dots[k]; x++)
                {
                    for (int y = j - dots[k]; y <= j + dots[k]; y++)

                    // verifica os limites da matriz e se tem '#' ao redor
                        if (x >= 0 && x < linha && y >= 0 && y < col && matriz[x][y] == '#')
                        // altera '#' por '.'
                            matriz[x][y] = '.';
                }
                k++;
            }
        }
    }
}

int main(void)
{
    int linha, col, count_t = 0;
    int dots[MAX_L * MAX_C], count[MAX_L * MAX_C];
    char matriz[MAX_L][MAX_C];

    scanf("%d%d", &linha, &col);

    // lê a matriz e verifica se tem 't'
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf(" %c", &matriz[i][j]);
            if (matriz[i][j] == 't')
                count_t++;
        }
    }

    // lê quantos pontos tera cada 't'
    for (int i = 0; i < count_t; i++)
        scanf("%d", &dots[i]);

    // adiciona os '.' na matriz
    add_dots(matriz, linha, col, dots);

    // printa a quantidade de '.'
    printf("%d\n", count_dots(matriz, linha, col));

    // imprime a matriz
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%c", matriz[i][j]);
        printf("\n");
    }

    return 0;
}

/*

5 10
##########
##t####t##
##########
##t#######
##########
1
2
1

____________________________________

10 10
#####t####
#####t####
#####t####
#####t####
#####t####
#####t####
#####t####
#####t####
#####t####
#####t####
1
2
3
3
2
1
1
4
3
1


*/