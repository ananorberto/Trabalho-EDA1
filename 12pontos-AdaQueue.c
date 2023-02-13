#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef int Item;
typedef struct No
{
    Item item;
    struct No *next;
    struct no *prev;
} No;

typedef struct Fila
{
    int arr[MAX_N];
    No *front;
    No *back;
    int size;
} Fila;


int init(Fila *f) 
{
  f->front = NULL;
  f->back = NULL;
  f->size = 0;
  return 1;
}

int is_empty(Fila *f) 
{
    return f->front == NULL;
}

// adiciona um elemento do tipo Item no fim da fila
int push_back(Fila *f, int x) 
{
    No *no = malloc(sizeof(No));
    // inicia novo no
    no->next = NULL;
    no->item = x;

    //verifica se esta vazia
    if (f->size == 0)
    {
        f->front=no;
        f->back=no;
        // prev declarado como NULL (primeiro da fila)
        no->prev = NULL;
    }
    else
    {
        // nexto do ultimo da fila aponta para novo no
        f->back->next = no;
        // no anterior aponta para o ultimo
        no->prev = f->back;
        f->back = no;
    }
    f->size++;
    return 1;
}

// adiciona um elemento do tipo Item no inicio da fila
int to_front(Fila *f, Item x) 
{
    No *no = malloc(sizeof(No));

    if (no == NULL) return 0;

    no->item = x;
    no->next = f->front;
    no->prev = NULL; // prev nao tem no anterior


    // se a fila esta vazia atualiza o ponteiro anterior e aponta para um novo no
    if (f->front != NULL) f->front->prev = no;
    else f->back = no; // se não estiver vazia atribui ultimo elemento para novo no

    f->front = no; // primeiro elemento aponta para novo no
    f->size++;

    return 1;
}

// remove o primeiro intem da fila
int pop_front(Fila *f) 
{    
    // se esta vazia retorna 0
    if (f->size == 0)    return 0;

    // armazena o primeiro em no
    No *no = f->front;
    int i = no->item; // armazena o valor do no em 'i'

    f->front = no->next;

    // se o proximo não for nulo o anterior aponta parar NULL
    if (f->front != NULL)    f->front->prev = NULL;

    else    f->back = NULL; 

    f->size--;
    free(no);
    return i;
}

// remove o ultimo item da fila
int pop_back(Fila *f) 
{
    No *x = f->back;

    // verifica se a fila tem tamanho 1
    if(f->size == 1) 
    {
        //se estiver front e back são declarados como NULL
        f->front = NULL;
        f->back = NULL;
    } 
    else 
    {
        // se nao o ultimo vira o anterior e o proximo = NULL
        f->back = f->back->prev;
        f->back->next = NULL;
    }

    f->size--;
    int i = x->item;

    free(x);
    return i;

}


int main() 
{
    int f, n, flag = 0;
    Fila queue;
    char command[1000];

    scanf("%d", &f);
    init(&queue);

    for (int i = 0; i < f; i++) 
    {
        scanf("%s", command);

        if (strcmp(command, "push_back") == 0) 
        {
            scanf("%d", &n);
            flag == 0 ? push_back(&queue, n) : to_front(&queue, n);
        } 
        else if (strcmp(command, "toFront") == 0) 
        {
            scanf("%d", &n);
            flag == 0 ? to_front(&queue, n) : push_back(&queue, n);
        } 

        else if (strcmp(command, "front") == 0) 
        {
            if (is_empty(&queue))
                printf("No job for Ada?\n");   
            
            else if (flag == 0)    printf("%d\n", pop_front(&queue));
            else    printf("%d\n", pop_back(&queue));
        } 

        else if (strcmp(command, "back") == 0) 
        {
            if (is_empty(&queue)) 
                printf("No job for Ada?\n");
            
            else if (flag == 0)  printf("%d\n", pop_back(&queue));
            else printf("%d\n", pop_front(&queue));
        } 

        else if (strcmp(command, "reverse") == 0) 
        {
            flag = flag == 0 ? 1 : 0;
        }
    }

    return 0;
}

/*

15
toFront 93
front
back
reverse
back
reverse
toFront 80
push_back 53
push_back 50
front
front
reverse
push_back 66
reverse
front

*/