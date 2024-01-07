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

void selectionSort(int arr[])
{
    // To store the index of the minimum element of the array
    int min;

    for (int i = 0; i < MAX; i++)
    {
        int min = i;
        for (int j = i + 1; j < MAX; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
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

    printf("Before Selection sort\n");
    display(arr);

    selectionSort(arr);

    printf("After Selection Sort\n");
    display(arr);

    return 0;
}