#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char string[100];
    struct Node* next;
} Node;

struct Node* top;

void inserir(char *data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->string, data);
    temp->next = top; 
    top = temp;
}

void remover() {
    if(top == NULL) {
        printf("NULL\n");
    }
    else {
        struct Node* temp = top;
        printf("%s\n", top->string);
        top = top->next;
        free(temp);
    }
}

int main() {
    char first_word[10];

    while(scanf("%s", first_word) != EOF) {
        char string[100];
        scanf("%[^\n]", string);

        for(int i = 0; i < strlen(string) + 1; i++) {
            if(i == 0) {
                continue;
            }
            int aux = i - 1;
            string[aux] = string[i];
        }
    
        if(strcmp(first_word, "inserir") == 0) {
            inserir(string);
        }
        else {
            remover();
        }
    }
}