#include<stdio.h>
int main(){
	int  i=1,basic,empno;
	char name,dept, location ;  
	while(i<=5){
		printf("ENTER NAME:\n");
		scanf("%s",&name);
		printf("ENTER EMP NO:\n");
		scanf("%d",&empno);
		printf("ENTER DEPARTMENT:\n");
		scanf("%s",&dept);
		printf("ENTER LOCATION:\n");
		scanf("%s",&location);
		printf("ENTER BASIC:\n");
		scanf("%d",&basic);
		if(basic>50000){
			printf("GRADE A\n");
		}
		else if(40000<basic && basic<50000){
				printf("GRADE B\n");
		}
		else
		{
				printf("GRADE C\n");
		}
		i++;
	}
	return 0;
}
