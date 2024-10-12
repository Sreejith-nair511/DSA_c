#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element to the stack
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->data[++s->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = s->data[s->top--];
        printf("%d popped from stack\n", value);
        return value;
    }
}

// Function to display the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    
    pop(&s);
    display(&s);
    
    return 0;
}
/*initializes the stack.

Pushes elements onto the stack.

Displays the elements in the stack.

Pops elements from the stack and displays the stack after popping.*/
