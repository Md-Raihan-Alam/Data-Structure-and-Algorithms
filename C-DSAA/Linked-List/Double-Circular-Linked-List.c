#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n) {
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = first; // Make it circular
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        first->prev = t; // Update the previous of the first node
        last = t;
    }
}

void Display(struct Node *p) {
    struct Node *temp = p;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
            } while (temp != p); // Loop until we reach the first node again
    printf("\n");
}

int Length(struct Node *p) {
    int len = 0;
    struct Node *temp = p;
    do {
        len++;
        temp = temp->next;
    } while (temp != p);
    return len;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    if (index < 1 || index > Length(p)) {
        return;
    }
    if (index == 1) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p->prev;
        t->next = p;
        p->prev->next = t;
        p->prev = t;
        if (p == first) {
            first = t; // Update first if inserting at the beginning
        }
        return;
    }
    for (i = 1; i < index; i++)
        p = p->next;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = p->prev;
    t->next = p;
    p->prev->next = t;
    p->prev = t;
}

int Delete(struct Node *p, int index) {
    int x = -1, i;
    if (index < 1 || index > Length(p)) {
        printf("Invalid\n");
        return x;
    }
    if (index == 1) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        if (p == first) {
            first = p->next; // Update first if deleting the first node
        }
        x = p->data;
        free(p);
        return x;
    }
    for (i = 1; i < index; i++)
        p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    x = p->data;
    free(p);
    return x;
}

void Reverse(struct Node *p) {
    struct Node *temp, *current = p;
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    } while (current != p);
}

int main() {
    int A[5] = {10, 12, 15, 42, 29};
    
    Create(A, 5);

    printf("\nLength is :%d\n", Length(first));
    
    Display(first);

    Insert(first, 2, 25);
    
    Display(first);

    Insert(first, 6, 14);
    
    Display(first);

    Delete(first, 1);
    
    Display(first);

Delete(first, 6);
   Display(first);

   Delete(first, 2);
   Display(first);

   Reverse(first);
   Display(first);

   return 0;

}