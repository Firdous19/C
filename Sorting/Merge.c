#include "stdio.h"
#define MAX 10

// Merging
void merge(int arr[], int l, int mid, int u)
{
    // finding the lengths of left and right arrays
    int leftLength = mid + 1 - l;
    int rightLength = u - mid;

    // declaring left and rigth arrays
    int leftarr[leftLength], rightarr[rightLength];

    // creating the arrays
    for (int i = 0; i < leftLength; i++)
    {
        leftarr[i] = arr[l + i];
    }

    for (int i = 0; i < rightLength; i++)
    {
        rightarr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < leftLength && j < rightLength)
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < leftLength)
    {
        arr[k++] = leftarr[i++];
    }

    while (j < rightLength)
    {
        arr[k++] = rightarr[i++];
    }
}

// Dividing
void mergeSort(int arr[], int l, int u)
{
    if (l < u)
    {
        int mid = (l + u) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, u);
        merge(arr, l, mid, u);
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

    printf("Before Merge Sort\n");
    display(arr);

    mergeSort(arr, 0, MAX - 1);

    printf("After Merge Sort\n");
    display(arr);

    return 0;
}
