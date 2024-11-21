#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100 
typedef int ElementType; 

typedef struct {
    ElementType elements[MaxSize];
    int top;
} Stack;

void makeNull(Stack *S) {
    S->top = -1;
}

int isEmpty(Stack *S) {
    return S->top == -1;
}

int isFull(Stack *S) {
    return S->top == MaxSize - 1;
}

void insertLast(ElementType x, Stack *S) {
    if (!isFull(S)) {
        S->elements[++(S->top)] = x;
    } else {
        printf("Stack is full.%d\n", x);
    }
}

ElementType deleteLast(Stack *S) {
    if (!isEmpty(S)) {
        return S->elements[(S->top)--];
    } else {
        printf("Stack is empty.\n");
        return -1; 
    }
}

void insertFirst(ElementType x, Stack *S) {
    if (isFull(S)) {
        printf("Stack is full.\n");
        return;
    }

    for (int i = S->top + 1; i > 0; i--) {
        S->elements[i] = S->elements[i - 1];
    }

    S->elements[0] = x;
    S->top++;
}

ElementType deleteFirst(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty.\n");
        return -1;
    }

    ElementType bottomElement = S->elements[0];

    for (int i = 0; i < S->top; i++) {
        S->elements[i] = S->elements[i + 1];
    }

    S->top--;
    return bottomElement;
}

void convertToBinary(int n) {
    Stack S;
    makeNull(&S);

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        insertLast(n % 2, &S); 
        n = n / 2;
    }

    while (!isEmpty(&S)) {
        printf("%d", deleteLast(&S)); 
    }
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    printf("Binary representation of %d is: ", n);
    convertToBinary(n);
    printf("\n");

    Stack testStack;
    makeNull(&testStack);

    insertLast(1, &testStack); 
    insertLast(2, &testStack);  
    insertFirst(0, &testStack); 
    insertLast(3, &testStack);  

    printf("After inserting 0, 1, 2, and 3, stack looks like: ");
    while (!isEmpty(&testStack)) {
        printf("%d ", deleteLast(&testStack));  
    }
    printf("\n");

    return 0;
}

