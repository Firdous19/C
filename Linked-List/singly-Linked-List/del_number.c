#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct node
{
    int data;
    struct node *link;
};

void display(struct node *head)
{
    struct node *ptr = head;
    if (ptr == NULL)
        printf("Empty Linked List\n");
    else
    {
        while (ptr->link != NULL)
        {
            printf("%d , ", ptr->data);
            ptr = ptr->link;
        }
        printf("%d\n", ptr->data);
    }
}

struct node *addfirst(struct node *head, int val)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->link = head;
    head = nw;
    return head;
}

struct node *delete(struct node *head, int val)
{
    struct node *ptr = head, *ptr1;
    while (ptr->link != NULL)
    {
        if (ptr == head && ptr->data == val)
        {
            ptr1 = ptr;
            ptr = ptr->link;
            head = ptr;
            free(ptr1);
        }
        else
        {
            ptr1 = ptr->link;
            if (ptr1->data == val)
            {
                ptr->link = ptr1->link;
                free(ptr1);
            }
            else
                ptr = ptr->link;
        }
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int val, del;
    char ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter a number : ");
        scanf("%d", &val);
        head = addfirst(head, val);
        printf("Do u want to continue : ");
        ans = getche();
        printf("\n");
    }
    printf("THe linked list : ");
    display(head);
    printf("Enter a no to delete : ");
    scanf("%d", &del);
    printf("List after deletion : ");
    head = delete (head, del);
    display(head);
    return 0;
}