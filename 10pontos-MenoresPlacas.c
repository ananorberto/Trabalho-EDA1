#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int left, int counter) {
    int smaller = 0;

    for(int i = 1; i < counter; i++) {
        if(array[smaller] > array[i]) {
            smaller = i;
        }
    }

    int auxx = array[0];
    array[0] = array[smaller];
    array[smaller]= auxx;

    for(int i = 2; i < counter; i++) {
        int j = i;
        int number = array[j];

        while(number < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = number;
    }
}


void print_list(int *array, int number) {
    for (int i = 0; i < number; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[200];
    int select;
    int number;
    int counter = 0;

    while (scanf("%d %d", &select, &number) != EOF) {
        if (select == 1)  {
            array[counter] = number;
            
            if(counter > 0) {
                insertion_sort(array, 0, counter + 1);
            }

            counter++;
            if(counter > 100) {
                counter = 100;
            }
        }
        else {
            print_list(array, number);
        }
    }
    return 0;
}