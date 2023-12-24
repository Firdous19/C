#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

// Declaring structure for the doubly linked list
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// function for displaying linked list
void display(struct node *head)
{
    struct node *temp = head;
    if (temp == NULL)
        printf("List is empty\n");
    else
    {
        printf("The linked list : ");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
                printf(",");
            else
                printf("\n");
        }
    }
}

// Creating a list using insert first function
struct node *addfirst(struct node *head, int val)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->prev = NULL;
    nw->data = val;
    nw->next = NULL;
    if (head == NULL)
        head = nw;
    else
    {
        nw->next = head;
        head->prev = nw;
        head = nw;
    }
    return head;
}

struct node *insany(struct node *head, int val, int pos)
{
    struct node *nw, *temp;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->prev = NULL;
    nw->data = val;
    nw->next = NULL;
    if (pos == 1)
    {
        nw->next = head;
        head->prev = nw;
        head = nw;
    }
    else
    {
        temp = head;
        while (pos != 2)
        {
            temp = temp->next;
            pos--;
            if (temp == NULL)
                break;
        }
        if (temp == NULL)
            printf("Invalid position\n");
        else if (temp->next == NULL)
        {
            temp->next = nw;
            nw->prev = temp;
        }
        else
        {
            nw->next = temp->next;
            nw->prev = temp;
            temp->next = temp->next->prev = nw;
        }
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    char ans = 'y';
    int val, pos;
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
        printf("Enter a number : ");
        scanf("%d", &val);
        printf("Enter a postion : ");
        scanf("%d", &pos);
        head = insany(head, val, pos);
        display(head);
        printf("Do u want to continue : ");
        ans = getche();
        printf("\n");
    }
}