#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char start;
    char city[27];
    char end;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;

void initialize_queue(struct Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

// void insert_front(char *data, char start, char end) {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     strcpy(temp->city, data);
//     temp->start = start;
//     temp->end = end;
//     temp->next = queue->front;
//     queue->front = temp;
//     if(queue->rear == NULL) {
//         queue->rear = temp;
//     }
// }

struct Node* create_node(char *data, char start, char end) {
    struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
    strcpy(temp->city, data);
    temp->start = start;
    temp->end = end;
    temp->next = NULL;
    return temp;
}

void insert_end(struct Queue *queue, char *data, char start, char end) {
    struct Node* temp = create_node(data, start, end);
    if(queue->rear == NULL) {
        queue->front = temp;
        queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

void remove_start(struct Queue *queue) {
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return;
}


int main() {
    char city[27];
    int counter = 0;
    struct Queue queue;

    initialize_queue(&queue);

    struct Queue *oe = &queue;

    while(scanf("%s", city) != EOF){
        int len = strlen(city);
        char first = tolower(city[0]);
        insert_end(&queue, city, first, city[len - 1]);
        counter++;
    }

    // printf("%d\n", counter);

    for(int i = 0; i < counter ; i++) {
    // printf("\n%s\n", oe->front->next->city);
        if(oe->front->next == NULL) {
            printf("%s\n", oe->front->city);
            return 0;
        }
        if(oe->front->end == oe->front->next->start) {
            printf("%s\n", oe->front->city);
            remove_start(&queue);
            insert_end(
                &queue,
                oe->front->city,
                oe->front->start,
                oe->front->end
            );
            remove_start(&queue);
        }
        else {
            printf("%s\n", oe->front->city);
            remove_start(&queue);
        }
    }

    return 0;
}