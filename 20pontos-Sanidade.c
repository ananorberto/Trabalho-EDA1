#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    long long unsigned int elem;
    long long unsigned int previous;
    long long unsigned int next;
} Node;

#define key(x) (x.elem)
#define less(a, b) (key(a) < key(b))

#define swap(a, b)  \
    {               \
        Node t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

int partition(Node *v, int size)
{
    int l = -1, r = size - 1;
    Node pivot = v[r];

    while (1)
    {
        while (less(v[++l], pivot))
            ;
        while (less(pivot, v[--r]) && r > l)
            ;

        if (l >= r)
            break;
        swap(v[l], v[r]);
    }
    swap(v[l], v[size - 1]);
    return l;
}

void quickSort(Node *v,int size)
{
    if (size < 2)
        return;

    cmpswap(v[(size - 1) / 2], v[size - 1]);
    cmpswap(v[0], v[(size - 1) / 2]);
    cmpswap(v[size - 1], v[(size - 1) / 2]);

    int m = partition(v, size);
    quickSort(v, m);
    quickSort(v + m + 1, size - m - 1);
}

int insane(struct Node *array, struct Node start, struct Node end, int length)
{
    if (start.next == end.elem)
    {
        if (end.previous == start.elem)
            return 1;
    }

    int answer = -1;
    int counter = 0;
    int aux = length;

    while (counter <= aux)
    {
        int middle = (counter + aux) / 2;

        if (array[middle].elem < start.next)
        {
            counter = middle + 1;
        }
        else if (array[middle].elem == start.next)
        {
            answer = middle;
            break;
        }
        else
        {
            aux = middle - 1;
        }
    }

    if (array[answer].previous != start.elem || answer == -1)
    {
        return 0;
    }

    return insane(array, array[answer], end, length);
}

struct Node array[1000000];

int main()
{
    long long unsigned int elem, previous, next;
    int counter = 0;

    while (scanf("%llx %llx %llx", &array[counter].elem, &array[counter].previous, &array[counter].next) != EOF)
    {
        counter++;
    }

    struct Node start = array[0];
    struct Node end = array[1];

    quickSort(array,counter);

    if (insane(array, start, end, counter - 1))
    {
        printf("sana\n");
        return 0;
    }

    printf("insana\n");

    return 0;
}

/*
a 0 b
f e 0
e d f
b a c
c b d
d c e


facada dead babaca
dead 0 facada
babaca facada 0
*/