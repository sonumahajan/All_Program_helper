#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
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
    while (i > 0)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }

        i--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}
