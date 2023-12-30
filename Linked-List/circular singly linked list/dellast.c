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

struct node *dellast(struct node *tail)
{
    struct node *ptr;
    if (tail == NULL)
        printf("Empty Linked List\n");
    else
    {
        ptr = tail->next;
        if (ptr != tail)
        {
            while (ptr->next != tail)
                ptr = ptr->next;
            ptr->next = tail->next;
            free(tail);
            tail = ptr;
        }
        else
        {
            free(tail);
            tail = NULL;
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
    int val, del = 1;
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
        printf("\nEnter 1 to delete : ");
        scanf("%d", &del);
        if (del == 1)
        {
            tail = dellast(tail);
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
