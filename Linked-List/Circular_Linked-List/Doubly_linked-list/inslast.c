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
        printf("The Required Linked List is : ");
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

struct node *inslast(struct node *tail, int val)
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
        tail->next = nw;
        nw->prev = tail;
        nw->next->prev = nw;
        tail = nw;
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
        tail = inslast(tail, val);
        printf("Continue : Y or N ? ");
        ans = getche();
        printf("\n");
    }

    display(tail);
    return 0;
}