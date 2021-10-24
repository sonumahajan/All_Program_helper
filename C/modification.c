#include<stdio.h>
struct student
{
    int rollno;
    int sub1;
    int sub2;
};
int main ()
{
    FILE *ab;
    struct student x;
    int ch;
    printf("Enter your choice:\n 1.Create File \n 2.See List\n 3.Add new record\n ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : ab=fopen("stu.dat","wb");
                 for (int i=0;i<5;i++)
                 {
                     printf("enter roll and then marks in 2 subject:");
                     scanf("%d %d %d",&x.rollno,&x.sub1,&x.sub2);
                     fwrite(&x,sizeof(x),1,ab);
                 }
                 fclose(ab);
                 break;
        case 2 : ab=fopen("stu.dat","rb");
                 while (fread(&x,sizeof(x),1,ab)==1)
                 {
                     printf("%d %d %d\n",x.rollno,x.sub1,x.sub2);
                 }
                 fclose(ab);
                 break; 
        case 3 : ab=fopen("stu.dat","ab");
                 printf("enter roll and then marks in 2 subject:");
                 scanf("%d %d %d",&x.rollno,&x.sub1,&x.sub2);
                 fwrite(&x,sizeof(x),1,ab);
                 fclose(ab);
                 break;         
        default : printf("You choosed wrong");                
    }
return 0;
}
