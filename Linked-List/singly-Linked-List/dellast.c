#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct node
{
    int data;
    struct node *link;
};

void display(struct node *head)
{
    struct node *temp = head;
    if (temp == NULL)
        printf("List is empty\n");
    else
    {
        printf("The Linked List : ");
        while (temp->link != NULL)
        {
            printf("%d , ", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}

struct node *addfirst(struct node *head, int val)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->link = head;
    head = nw;
    return head;
}

struct node *dellast(struct node *head)
{
    struct node *temp = head, *temp1;
    if (temp == NULL)
        printf("List is empty\n");
    else
    {
        while (temp->link != NULL)
        {
            temp1 = temp;
            temp = temp->link;
        }
        temp1->link = temp->link;
        free(temp);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int val, del;
    char ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter a number : ");
        scanf("%d", &val);
        head = addfirst(head, val);
        printf("Do u want to continue : ");
        ans = getche();
        printf("\n");
    }
    display(head);
    ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter 1 to delete : ");
        scanf("%d", &del);
        if (del == 1)
        {
            head = dellast(head);
            display(head);
        }
        else
        {
            printf("Wrong Input\n");
        }
        printf("Do u want to continue : ");
        ans = getche();
        printf("\n");
    }
    return 0;
}