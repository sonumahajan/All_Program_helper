/*Given an array of n integers. Find the unique elements in the array and print them.
Unique elements are the elements which occur only once  in the array,


Input Description:-
- First line of input consists of t, the number of test cases.
- Next t lines each consists of:
n: the length of the array
arr[i]: an array of n integers


Input variables:
int t: No. of test cases
int n: Length of the array
int arr[]: Array of n integers
   
Output Description:-
int: Unique numbers for each array in each line
In case of no unique elements, print 0


Constraints:-
1<=t<=10
1<=n<=40
1<=value of each array element<=40

Input:-
2
6
1 2 2 3 4 4
4
2 3 4 2


Sample Output:
1 3
3 4 */
#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);

    while (t--){

        int len;
        scanf("%d", &len);
        int arr[len];
        for (int i = 0; i < len; i++){
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < len; i++){
            int count = 0;
            for(int j = 0; j < len; j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            
            if(count == 1){
                printf("%d ",arr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}