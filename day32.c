#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        return;  // Stack Overflow (ignored as per problem)
    }
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        return;  // Stack Underflow (ignored as per problem)
    }
    top--;
}

// Display stack from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Number of pops
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining elements
    display();

    return 0;
}