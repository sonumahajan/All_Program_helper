// radix sort


#include <iostream>


using namespace std;


void radix_sort(int *arr, int n)
{
    int i, j, k, m, exp, max = 0;
    int *b = new int[n];
    int *c = new int[n];

    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    m = max;
    while (m > 0)
    {
        m /= 10;
        exp++;
    }

    for (i = 0; i < exp; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[j] = 0;
        }

        for (j = 0; j < n; j++)
        {
            k = arr[j] % (int)pow(10, i + 1) / (int)pow(10, i);
            b[k]++;
        }

        for (j = 1; j < 10; j++)
        {
            b[j] += b[j - 1];
        }

        for (j = n - 1; j >= 0; j--)
        {
            k = arr[j] % (int)pow(10, i + 1) / (int)pow(10, i);
            c[b[k] - 1] = arr[j];
            b[k]--;
        }

        for (j = 0; j < n; j++)
        {
            arr[j] = c[j];
        }
    }

    delete[] b;
    delete[] c;
}


int main()
{
    int n, i;
    int *arr = new int[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radix_sort(arr, n);

    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
