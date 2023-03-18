#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

// define the stack data structure
struct stack {
    int items[MAX_SIZE];
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
void push(struct stack *s, int item) {
    if (is_full(s)) {
        printf("Error: stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

// function to pop an item from the stack
int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

// function to peek at the top item on the stack
int peek(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

// function to evaluate a postfix expression
int evaluate_postfix(char* exp) {
    struct stack s;
    init_stack(&s);
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }
    return pop(&s);
}

// main function to test the postfix expression evaluation
int main() {
    char exp[] = "23*54*+9-";
    printf("Postfix expression: %s\n", exp);
    int result = evaluate_postfix(exp);
    printf("Result: %d\n", result);
    return 0;
}
