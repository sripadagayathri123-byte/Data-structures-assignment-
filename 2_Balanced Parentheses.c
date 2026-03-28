#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    int i, flag = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1) {
                flag = 0;
                break;
            }
            char ch = pop();
            if((exp[i] == ')' && ch != '(') ||
               (exp[i] == '}' && ch != '{') ||
               (exp[i] == ']' && ch != '[')) {
                flag = 0;
                break;
            }
        }
    }

    if(top != -1) flag = 0;

    if(flag)
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}
