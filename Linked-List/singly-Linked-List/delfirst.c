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

struct node *delfirst(struct node *head)
{
    struct node *temp;
    if (temp == NULL)
        printf("List is empty\n");
    else
    {
        temp = head;
        head = head->link;
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
        printf("\nEnter a number : ");
        scanf("%d", &val);
        head = addfirst(head, val);
        printf("Do u want to continue : ");
        ans = getche();
    }
    display(head);
    ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        printf("\nEnter 1 to delete : ");
        scanf("%d", &del);
        if (del == 1)
        {
            head = delfirst(head);
            display(head);
        }
        else
        {
            printf("Wrong Input\n");
        }
        printf("Do u want to continue : ");
        ans = getche();
    }
    return 0;
}