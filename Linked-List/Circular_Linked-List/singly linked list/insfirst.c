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
        printf("List is Empty");
    else
    {
        struct node *ptr = tail->next;
        printf(" The required list : ");
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr!= tail->next);
    }
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
    int val;
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
    return 0;
}