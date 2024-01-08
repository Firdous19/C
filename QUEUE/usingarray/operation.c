#include "stdio.h"
#include "stdlib.h"
#define MAX 10

int QUEUE[MAX];
int front = -1, rear = -1;

void enque(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        exit(0);
    }

    if (front == -1)
    {
        front++;
    }

    QUEUE[++rear] = data;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }

    int data = QUEUE[front];
    front++;

    return data;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int highestElement()
{
    int highest = 0;
    for (int i = front; i <= rear; i++)
    {
        if (QUEUE[i] > highest)
        {
            highest = QUEUE[i];
        }
    }

    return highest;
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("QUEUE OPERATION\n");
        printf("1.ENQUE OPERATION\n");
        printf("2.DEQUEUE OPERATION\n");
        printf("3.DISPLAY OPERATION\n");
        printf("4.HIGHEST ELEMENT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enque(data);
            printf("DATA PUSHED SUCCESSFULLY\n");
            break;

        case 2:
            data = dequeue();
            printf("Data dequeued: %d\n", data);
            break;

        case 3:
            printf("Elements within the queue\n");
            display();
            break;

        case 4:
            data = highestElement();
            printf("Highest Elements of the queue: %d\n", data);
            break;

        default:
            printf("Wrong choice\n");
            exit(0);
        }
    }
}