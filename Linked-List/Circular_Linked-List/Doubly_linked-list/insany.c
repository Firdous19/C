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
    if (tail == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct node *ptr = tail->next;
        printf("The required list : ");
        do
        {
            printf("%d", ptr->data);
            if (ptr != tail)
                printf(" <---> ");
            else
                printf("\n");
            ptr = ptr->next;
        } while (ptr != tail->next);
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

struct node *insany(struct node *tail, int val, int pos)
{
    struct node *nw, *temp;
    int flag = 0;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->prev = nw;
    nw->data = val;
    nw->next = nw;
    if (tail == NULL)
        tail = nw;
    else
    {
        temp = tail->next;
        while (pos > 2)
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
            printf("Invalid position\n");
        else if (pos == 1)
        {
            nw->next = tail->next;
            nw->next->prev = nw;
            tail->next = nw;
            nw->prev = tail;
        }
        else
        {
            nw->prev = temp;
            nw->next = temp->next;
            temp->next = nw;
            nw->next->prev = nw;
            if (temp == tail)
                tail = nw;
        }
    }
    return tail;
}

int main()
{
    struct node *tail = NULL;
    int val, choice, pos;
    char ans = 'y';
    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter a number : ");
        scanf("%d", &val);
        tail = insfirst(tail, val);
        printf("Continue : Y or N ? ");
        ans = getche();
        printf("\n");
    }

    display(tail);
    ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        printf("\nEnter 1 to insert : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter a number : ");
            scanf("%d", &val);
            printf("Enter a position : ");
            scanf("%d", &pos);
            tail = insany(tail, val, pos);
            display(tail);
        }
        printf("Do you want to continue : ");
        ans = getche();
    }
    return 0;
}