#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void display(struct node *tail)
{
    struct node *temp;
    if (tail == NULL)
        printf("Linked List is Empty\n");
    else
    {
        temp = tail->next;
        do
        {
            printf("%d", temp->data);
            if (temp != tail)
                printf(" <--> ");
            else
                printf("\n");
            temp = temp->next;
        } while (temp != tail->next);
    }
}

struct node *insfirst(struct node *tail, int val)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->prev = nw;
    nw->data = val;
    nw->next = nw;
    if (tail == NULL)
        tail = nw;
    else
    {
        nw->next = tail->next;
        nw->next->prev = nw;
        tail->next = nw;
        nw->prev = tail;
    }
    return tail;
}

struct node *delany(struct node *tail, int pos)
{
    struct node *temp;
    int flag = 0;
    if (tail == NULL)
        printf("List is Empty\n");
    else
    {
        temp = tail->next;
        while (pos > 1)
        {
            temp = temp->next;
            pos--;
            if (temp == tail->next)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            printf("Invalid Position\n");
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == tail)
                tail = tail->prev;
            free(temp);
        }
    }
    return tail;
}

int main()
{
    struct node *tail = NULL;
    char ans = 'y';
    int choice, val, pos;

    while (ans == 'Y' || ans == 'y')
    {
        printf("Enter a number : ");
        scanf("%d", &val);
        tail = insfirst(tail, val);
        printf("Do u want to continue : ");
        ans = getche();
        printf("\n");
    }
    display(tail);
    ans = 'y';

    while (ans == 'Y' || ans == 'y')
    {
        printf("Enter 1 to delete : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the position : ");
            scanf("%d", &pos);
            tail = delany(tail, pos);
            display(tail);
        }
        printf("Do you want to continue : ");
        ans = getche();
        printf("\n");
    }
    return 0;
}