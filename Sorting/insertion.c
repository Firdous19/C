#include "stdio.h"
#define MAX 10

void InsertionSort(int arr[])
{
    int key, i;

    for (int j = 1; j < MAX; j++)
    {
        i = j - 1;
        key = arr[j];
        // 6 20 5 7 8
        // 0  1 2 3 4
        while (arr[i] > key && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void display(int *arr)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int arr[MAX];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Insertion Sort\n");
    display(arr);

    InsertionSort(arr);

    printf("After Insertion Sort\n");
    display(arr);

    return 0;
}