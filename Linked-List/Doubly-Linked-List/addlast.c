#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *temp = head;
    if (temp == NULL)
        printf("List is empty");
    else
    {
        printf("The required list is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

struct node *addlast(struct node *head, int val)
{
    struct node *nw, *temp;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->prev = NULL;
    nw->data = val;
    nw->next = NULL;
    if (head == NULL)
        head = nw;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nw;
        nw->prev = temp;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    char ans = 'y';
    int val;
    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter a no : ");
        scanf("%d", &val);
        head = addlast(head, val);
        printf("Do you want to continue : ");
        ans = getche();
        printf("\n");
    }
    display(head);
    return 0;
}