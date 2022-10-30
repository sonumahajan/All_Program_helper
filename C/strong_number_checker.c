#include<stdio.h>
 #include<conio.h> 
int main()
  {   int i, p, num, lastDigit, sum;  
     long fact;    
   printf("Enter any number to check Strong number: ");    
    scanf("%d", &num);    
	 p = num;   
	    sum = 0; 
	    while(num > 0)
		     {         lastDigit = num % 10;    
		     fact = 1;      
			    for(i=1; i<=lastDigit; i++)  
				       {             fact = fact * i;         }         
					   
					          sum = sum + fact;         num = num / 10;     }   
							     if(sum == p)     {      
								    printf("%d is STRONG NUMBER", p);     }    
   else     {     
       printf("%d is NOT STRONG NUMBER", p);  
	      }
}
