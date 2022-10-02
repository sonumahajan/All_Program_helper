#include<stdio.h>
#include<conio.h>;
#include<string.h>
struct information{
	char fname[20],lname[20],EmailID[100];
	int rank,phoneNo,ID;
};
int main(){
	int i,n;
	FILE*filePointer;
	char ans='y';
	char dataTOBEWRITTEN[1000]="\t<----Students`Information System---->";
	while(ans!='n'){
	struct information a1;
filePointer=fopen("Project.c","w");
if(filePointer==NULL){
	printf("\n 404 FILE NOT FOUND.");
}
else
{   printf("Enter Total No. Of Student`s Admitted :");
	scanf("%d",&n);
	printf("\n PROCESSING....\nWait a moment!");
	if(strlen(dataTOBEWRITTEN)>0);
	fputs(dataTOBEWRITTEN,filePointer);
	printf("\n CONGRAGULATIONS!\t File Is Now Opened Successfully.");
	for(i=0;i<n;i++){
	printf("\n 1.FIRST NAME:");
    scanf("%s",&a1.fname);
    printf("\n 2.LAST NAME:");
    scanf("%s",&a1.lname);
    printf("\n 3. RANK:");
    scanf("%d",&a1.rank);
    printf("\n 4. PHONE NO.:");
    scanf("%d",&a1.phoneNo);
    printf("\n 5.EMAIL ID.:");
    scanf("%s",&a1.EmailID);
    printf("\n 6.STUDENT ID:");
    scanf("%d",&a1.ID);	
	}
	
	fclose(filePointer);
	printf("\n EXIST OR LOGIN TO CONTINUE.");
}
printf("\n Do You Want To Add More Student-Records?(y/n).");
    ans=getche();
}
return 0;
}

