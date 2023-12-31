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
    struct node *ptr = tail->next;
    if (tail == NULL)
        printf("List is Empty\n");
    else
    {
        printf("\nThe linked list : ");
        do
        {
            printf("%d", ptr->data);
            ptr = ptr->next;
            if (ptr != tail->next)
                printf(",");
            else
                printf("\n");
        } while (ptr != tail->next);
    }
}

struct node *inslast(struct node *tail, int val)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->next = nw;
    if (tail == NULL)
        tail = nw;
    else
    {
        nw->next = tail->next;
        tail->next = nw;
        tail = nw;
    }
    return tail;
}

int main()
{
    struct node *tail = NULL;
    char ans = 'y';
    int val;

    while (ans == 'y' || ans == 'Y')
    {
        printf("\nEnter a no : ");
        scanf("%d", &val);
        tail = inslast(tail, val);
        printf("Do you want to continue : ");
        ans = getche();
    }

    display(tail);
    return 0;
}