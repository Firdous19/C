#include "stdio.h"
#define MAX 10

void display(int *arr)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Function to swap two elements using pointer
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[])
{

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[MAX];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Bubble sort\n");
    display(arr);

    bubbleSort(arr);

    printf("After Bubble Sort\n");
    display(arr);

    return 0;
}