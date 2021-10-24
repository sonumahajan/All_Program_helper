#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sort(int A[], int i)
{

    for (int j = 0; j < i; j++)
    {
        if (A[j] > A[j + 1])
            swap(&A[j], &A[j + 1]);
    }

    if (i == 0)
        return;
    sort(A, i - 1);
}
int main()
{
    int i, n = 0;
    printf("Number of elements: ");
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    i--;
    sort(A, i);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}
