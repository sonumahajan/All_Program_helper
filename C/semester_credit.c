/*Given that your semester results are out amd you have received the credits of each subject. Frame a program to input your credit of each subject in a line in form of a string separated by commas. 

Input Format: 
String: Various integers separated by commas.

Output Format:
All the integers printed line by line

Constraints: 
The length of str is less than 8*10^5

Sample Input: 3,4,5,2

Sample Output:    
3
4
5
2 */
#include <stdio.h>
#include <string.h>
int main()
{
    char h[1000000];
    gets(h);
    for(int i=0;i<strlen(h);i++)
    {   
        if(h[i]!=',')
        printf("%c",h[i]);
        else
        printf("\n");
    }
}