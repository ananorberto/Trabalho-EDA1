#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

struct Node* top;

void stack(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->number = data;
    temp->next = top; 
    top = temp;
    return;
}

void unstack() {
    if(top == NULL) {
        return;
    }
    else {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    int num_entries = 0;

    for( ; ; ) {
        scanf("%d", &num_entries);

        if(num_entries == 0) {
            return 0;
        }

        int counter = 1;
        int controler = 0;

        int *array = malloc(sizeof(int) * num_entries);

        for(int i = 0; i < num_entries; i++) {
            scanf("%d", &array[i]);
        }

        for(int i = 0; i < num_entries; i++) {
            while(top != NULL && top->number == counter) {
                counter++;
                unstack();
            }

            if(top != NULL && top->number < array[i]) {
                controler = 1;
                break;
            }

            if(array[i] == counter) {
                counter++;
            }

            else {
                stack(array[i]);
            }
        }

        if(controler == 0) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }

        top = NULL;
    }
       
    return 0;
}