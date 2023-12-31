#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node *front;
};

void create(struct PriorityQueue* pq) {
    pq->front = NULL;
}

void enqueue(struct PriorityQueue* pq, int x, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->priority = priority;
    newNode->next = NULL;

    if (pq->front == NULL || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    struct Node* temp = pq->front;
    int x = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return x;
}

void display(struct PriorityQueue pq) {
    struct Node* temp = pq.front;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    create(&pq);
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    display(pq);
    printf("%d ", dequeue(&pq));

    return 0;
}
