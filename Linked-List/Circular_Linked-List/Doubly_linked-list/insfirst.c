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
        printf("\n");
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

int main()
{
    struct node *tail = NULL;
    int val;
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
    return 0;
}