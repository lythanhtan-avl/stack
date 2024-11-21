#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1000  
typedef int ElementType; 

typedef struct {
    ElementType elements[MaxSize];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, ElementType value) {
    if (s->top < MaxSize - 1) {
        s->elements[++(s->top)] = value;
    }
}

ElementType pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->elements[(s->top)--];
    }
    return -1;  // Return -1 for an empty stack
}

int Fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;

    Stack s;
    init(&s);
    
    push(&s, n);

    int result = 0;

    while (!isEmpty(&s)) {
        int current = pop(&s);

        if (current == 1 || current == 2) {
            result += 1;
        } else {
            // Push current-1 and current-2 onto the stack
            push(&s, current - 1);
            push(&s, current - 2);
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = Fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, result);

    return 0;
}

