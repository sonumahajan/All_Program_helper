#include <iostream>
using namespace std;

int main()
{
    int  element, ind, flag = 0;
    int num;
    cout<<"Enter number of element: ";
    cin>>num;
    int arr[num];
    cout << "\nEnter the elements \n";  //Entering elements of array
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search in array ";  //Element to be searched
    cin >> element;

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == element)  //if element found
        {
            ind = i; //store the index of that element
            break;
        }
        else
            int flag = 1;   //not found
    }

    if (flag == 1)
    {
        cout << "\nElemnt not found in your array";
    }

    else
        cout << "\nElement found at index " << ind << " position " << ind + 1;
}
