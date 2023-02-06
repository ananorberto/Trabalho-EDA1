#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int start;
    int clue;
    int next;
    struct Node* pointer;
} Node;

struct Node* head;

void print_list(struct Node* head) {
    if(head == NULL) {
        return;
    }
    print_list(head->pointer);
    printf("%d\n", head->clue);
}

void inserir(int data, int start, int next) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->clue = data; 
    new_node->start = start;
    new_node->next = next;

    if(head == NULL) {
        head = new_node;
        return;
    }

    new_node->pointer = head;
    head = new_node;
    return;
}

int main() {
    int number_lines = 0;
    int start, clue, next;

    scanf("%d", &number_lines);

    struct Node* array = (struct Node*)malloc(sizeof(struct Node) * number_lines);


    for(int i = 0; i < number_lines; i++) {
        scanf("%d %d %d", &start, &clue, &next);
        array[i].start = start;
        array[i].clue = clue;
        array[i].next = next;
    }

    int head_list = 0;

    for(int i = 0; i < number_lines; i++) {
        int head = 1;
        for(int j = 0; j < number_lines; j++) {
            if(array[i].start == array[j].next) {
                head = 0;
            }
        }
        if(head == 1) {
            inserir(
                array[i].clue,
                array[i].start,
                array[i].next
            );
            head_list = i;
            break;
        }
    }
    
    for(int j = 0; j < number_lines; j++) {
        for(int i = 0; i < number_lines; i++) {
            if(array[head_list].next == array[i].start) {
                inserir(
                    array[i].clue,
                    array[i].start,
                    array[i].next
                );
                head_list = i;
            }
        }
    }

    print_list(head);
    return 0;
}
