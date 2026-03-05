#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char exp[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    printf("Postfix Expression: ");

    for(int i = 0; i < strlen(exp); i++) {
        if(isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        else if(exp[i] == '(') {
            push(exp[i]);
        }
        else if(exp[i] == ')') {
            while((stack[top]) != '(')
                printf("%c", pop());
            pop();
        }
        else {
            while(priority(stack[top]) >= priority(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}