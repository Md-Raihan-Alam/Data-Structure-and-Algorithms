#include<stdio.h>
#include<stdlib.h>

struct Deque {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Deque *dq, int size) {
    dq->size = size;
    dq->front = dq->rear = -1;
    dq->Q = (int *)malloc(dq->size * sizeof(int));
}

void insertFront(struct Deque *dq, int x) {
    if ((dq->front - 1 + dq->size) % dq->size == dq->rear) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + dq->size) % dq->size;
    }
    dq->Q[dq->front] = x;
}

void insertRear(struct Deque *dq, int x) {
    if ((dq->rear + 1) % dq->size == dq->front) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->size;
    }
    dq->Q[dq->rear] = x;
}

int deleteFront(struct Deque *dq) {
    int x = -1;
    if (dq->front == -1) {
        printf("Deque is empty\n");
    } else {
        x = dq->Q[dq->front];
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;
        } else {
            dq->front = (dq->front + 1) % dq->size;
        }
    }
    return x;
}

int deleteRear(struct Deque *dq) {
    int x = -1;
    if (dq->front == -1) {
        printf("Deque is empty\n");
    } else {
        x = dq->Q[dq->rear];
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;
        } else {
            dq->rear = (dq->rear - 1 + dq->size) % dq->size;
        }
    }
    return x;
}

void display(struct Deque dq) {
    if (dq.front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq.front;
    do {
        printf("%d ", dq.Q[i]);
        i = (i + 1) % dq.size;
    } while (i != (dq.rear + 1) % dq.size);
    printf("\n");
}

int main() {
    struct Deque dq;
    create(&dq, 5);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertRear(&dq, 30);
    display(dq);

    insertFront(&dq, 5);
    display(dq);

    deleteFront(&dq);
    display(dq);

    deleteRear(&dq);
    display(dq);

    return 0;
}
