#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *link;
};

int top = -1;

struct node *push(struct node *head, int data)
{
    struct node *nw;
    nw = malloc(sizeof(struct node));
    nw->data = data;
    nw->link = head;
    head = nw;
    top++;

    return head;
}

int pop(struct node *head)
{
    struct node *temp;
    temp = head;
    head = head->link;
    int data = temp->data;
    top--;
    return data;
}

void display(struct node *head)
{
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
    int choice, data;
    struct node *head = NULL;

    while (1)
    {
        printf("STACK OPERATION\n");
        printf("1.PUSH OPERATION\n");
        printf("2.POP OPERATION\n");
        printf("3.DISPLAY OPERATION\n");
        printf("4.TOTAL ELEMENT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be pushed: ");
            scanf("%d", &data);
            head = push(head, data);
            printf("DATA PUSHED SUCCESSFULLY\n");
            break;

        case 2:
            data = pop(head);
            printf("Data popped: %d\n", data);
            break;

        case 3:
            printf("Elements within the Stack\n");
            display(head);
            break;

        case 4:
            printf("Total Elements : %d\n", top + 1);
            break;

        default:
            printf("Wrong choice\n");
            exit(0);
        }
    }
}