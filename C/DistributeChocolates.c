#include <stdio.h>

int main(){
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		long int c,n,s=0,r;
		scanf("%ld %ld\n", &c,&n);
		s=n*(n+1)/2;
		if(s<c)
		{
			printf("%ld\n", ((c-s)%n));
		}
		else
		{
			printf("%ld\n",c);
		}
	}
}
