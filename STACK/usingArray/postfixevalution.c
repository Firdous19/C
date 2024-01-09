#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#define MAX 20

int stack[MAX];
int top = -1;

void push(int data)
{
    stack[++top] = data;
}

int pop()
{
    int data = stack[top];
    top--;
    return data;
}

int postfixEvaluation(char postfix[])
{
    int i = 0, sum = 0;

    while (postfix[i] != '\0')
    {
        char alp = postfix[i];

        if (isalnum(alp))
        {
            push(alp - '0');
        }
        else
        {
            int num2 = pop();
            int num1 = pop();
            switch (alp)
            {
            case '+':
                sum = num1 + num2;
                break;

            case '-':
                sum = num1 - num2;
                break;

            case '*':
                sum = num1 * num2;
                break;

            case '/':
                sum = num1 / num2;
                break;
            }

            push(sum);
        }
        i++;
    }

    int postfixeva = pop();
    return postfixeva;
}

int main()
{
    char postfix[MAX];
    printf("Enter the postfix Expression: ");
    gets(postfix);

    int postfixEvaluatedData = postfixEvaluation(postfix);

    printf("Postfix Evaluated data: %d", postfixEvaluatedData);

    return 0;
}