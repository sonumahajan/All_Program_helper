#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sortArray(int arr[], int N)
{
    for (int i = 0; i < N;)
    {
        if (arr[i] == i + 1)
        {
            i++;
        }
        else
        {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }
}

int main()
{
    int arr[] = {8, 12, 2, 6, 1, 7, 11, 5, 3, 10, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: \n");
    printArray(arr, n);

    sortArray(arr, n);

    printf("\n\nSorted Array: \n");
    printArray(arr, n);
    return 0;
}
