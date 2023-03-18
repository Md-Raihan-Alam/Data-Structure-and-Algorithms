#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// define the stack data structure
struct stack {
    char items[MAX_SIZE];
    int top;
};

// function to initialize the stack
void init_stack(struct stack *s) {
    s->top = -1;
}

// function to check if the stack is full
int is_full(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

// function to check if the stack is empty
int is_empty(struct stack *s) {
    return s->top == -1;
}

// function to push an item onto the stack
void push(struct stack *s, char item) {
    if (is_full(s)) {
        printf("Error: stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

// function to pop an item from the stack
char pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        return '\0';
    } else {
        char item = s->items[s->top];
        s->top--;
        return item;
    }
}

// function to peek at the top item on the stack
char peek(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        return '\0';
    } else {
        return s->items[s->top];
    }
}

// function to check if a postfix expression containing only characters is valid or not
int is_valid_postfix(char* exp) {
    struct stack s;
    init_stack(&s);
    for (int i = 0; exp[i]; i++) {
        if (isalpha(exp[i])) {
            push(&s, exp[i]);
        } else {
            if (is_empty(&s)) {
                printf("Invalid expression: too few operands\n");
                return 0;
            }
            char operand2 = pop(&s);
            if (is_empty(&s)) {
                printf("Invalid expression: too few operands\n");
                return 0;
            }
            char operand1 = pop(&s);
            push(&s, ' ');
        }
    }
    if (s.top == 0 && s.items[s.top] == ' ') {
        printf("Valid expression\n");
        return 1;
    } else {
        printf("Invalid expression: too few operators\n");
        return 0;
    }
}

// main function to test the validity of a postfix expression containing only characters
int main() {
    char exp[] = "AB*C+";
    printf("Postfix expression: %s\n", exp);
    is_valid_postfix(exp);
    return 0;
}
