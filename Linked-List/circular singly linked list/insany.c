#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct node
{
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
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
        printf("\n");
    }
}

struct node *insany(struct node *tail, int val, int pos)
{
    struct node *nw, *ptr = tail->next;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->next = nw;
    if (pos == 1)
    {
        nw->next = ptr;
        tail->next = nw;
    }
    else
    {
        ptr = tail->next;
        while (pos != 2)
        {
            ptr = ptr->next;
            pos--;
            if (ptr == tail->next)
                break;
        }
        if (ptr == tail->next)
            printf("Invalid position");
        else if (ptr == tail)
        {
            nw->next = ptr->next;
            ptr->next = nw;
            tail = nw;
        }
        else
        {
            nw->next = ptr->next;
            ptr->next = nw;
        }
    }
    return tail;
}

struct node *add_first(struct node *tail, int val)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->next = nw;
    if (tail == NULL)
    {
        tail = nw;
    }
    else
    {
        nw->next = tail->next;
        tail->next = nw;
    }
    return tail;
}

int main()
{
    struct node *tail = NULL;
    int val, del = 1, pos;
    char ans = 'y';
    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter a number : ");
        scanf("%d", &val);
        tail = add_first(tail, val);
        printf("Continue : Y or N ? ");
        ans = getche();
        printf("\n");
    }

    display(tail);
    ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        printf("\nEnter 1 to insert : ");
        scanf("%d", &del);
        if (del == 1)
        {
            printf("Enter a no : ");
            scanf("%d", &val);
            printf("Enter a position : ");
            scanf("%d", &pos);
            tail = insany(tail, val, pos);
            display(tail);
        }
        else
        {
            printf("Wrong Input\n");
        }
        printf("Continue : Y or N ? ");
        ans = getche();
    }
    return 0;
}