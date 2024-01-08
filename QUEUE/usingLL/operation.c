#include "stdio.h"
#include "stdlib.h"
#define MAX 10

struct node
{
    int data;
    struct node *link;
};

int front = -1, rear = -1;

struct node *enque(struct node *head, int data)
{
    struct node *nw;
    nw = malloc(sizeof(struct node));
    nw->data = data;
    nw->link = NULL;
    if (head == NULL)
    {
        front++;
        head = nw;
    }

    else
    {
        struct node *temp = head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = nw;
        rear++;
    }

    return head;
}

int dequeue(struct node *head)
{
    struct node *temp;
    temp = head;
    head = head->link;
    int data = temp->data;
    front++;

    free(temp);
    return data;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Queue is Empty\n");
        exit(0);
    }

    printf("Elements within the queue\n");
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    struct node *head = NULL;
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
            head = enque(head, data);
            printf("DATA PUSHED SUCCESSFULLY\n");
            break;

        case 2:
            data = dequeue(head);
            printf("Data dequeued: %d\n", data);
            break;

        case 3:
            display(head);
            break;

        default:
            printf("Wrong choice\n");
            exit(0);
        }
    }
}