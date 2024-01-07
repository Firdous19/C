#include "stdio.h"
#include "stdlib.h"
#define MAX 10

int STACK[MAX], top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(0);
    }

    STACK[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }

    int data = STACK[top];
    top--;
    return data;
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", STACK[i]);
    }
    printf("\n");
}

int highestElement()
{
    int highest = 0;
    for (int i = top; i >= 0; i--)
    {
        if (STACK[i] > highest)
        {
            highest = STACK[i];
        }
    }

    return highest;
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("STACK OPERATION\n");
        printf("1.PUSH OPERATION\n");
        printf("2.POP OPERATION\n");
        printf("3.DISPLAY OPERATION\n");
        printf("4.HIGHEST ELEMENT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be pushed: ");
            scanf("%d", &data);
            push(data);
            printf("DATA PUSHED SUCCESSFULLY\n");
            break;

        case 2:
            data = pop();
            printf("Data popped: %d\n", data);
            break;

        case 3:
            printf("Elements within the Stack\n");
            display();
            break;

        case 4:
            data = highestElement();
            printf("Highest Elements of the array: %d\n", data);
            break;

        default:
            printf("Wrong choice\n");
            exit(0);
        }
    }
}