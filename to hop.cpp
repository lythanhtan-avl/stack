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
        printf("Stack is full.\n");
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

int binomialCoefficient(int k, int n) {
    Stack S;
    makeNull(&S);

    insertLast(k, &S);
    insertLast(n, &S);

    int result = 0;
    
    while (!isEmpty(&S)) {
        n = deleteLast(&S);
        k = deleteLast(&S);
        
        if (k == 0 || k == n) {
            result = 1;
        } else if (k == 1) {
            result = n;
        } else {
            insertLast(k - 1, &S);  
            insertLast(n - 1, &S);  
            
            insertLast(k, &S);      
            insertLast(n - 1, &S); 
            result += deleteLast(&S);
        }
    }

    return result;
}

int main() {
    int k, n;
    printf("Enter values of k and n (for C(k, n)): ");
    scanf("%d %d", &k, &n);

    printf("C(%d, %d) = %d\n", k, n, binomialCoefficient(k, n));

    return 0;
}

