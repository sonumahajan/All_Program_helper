#include<stdio.h>
#include<windows.h>
void add_contact();
void search_contact();
void delete_contact();
void view_all_contact();

void main(){
system("cls");
system("color F5");
printf("\t\t\t\t\t          PHONEBOOK\n\n\n");
printf("\t1. Add contact\n\n");
printf("\t2. Search contact\n\n");
printf("\t3. Delete contact\n\n");
printf("\t4. View all contact\n\n");
printf("\t5. Exit\n\n");
printf("\n\n\n\n\n\nEnter your selection : ");
int option;
scanf("%d",&option);
switch(option)
{
case 1:
add_contact();
break;
case 2:
search_contact();
break;
case 3:
delete_contact();
break;
case 4:
view_all_contact();
break;
case 5:
exit(0);
default:
main();
}
}

void add_contact()
{
system("color F6");
FILE *fp;
fp=fopen("contact.txt","a+");
system ("cls");
printf("\t\t\t\t\t        ADD CONTACT");
printf("\n\n\n\tName        : ");
char name[20];
scanf("%s",name);
printf("\n\tSurname     : ");
char sur[20];
scanf("%s",sur);
printf("\n\tMobile no.  : ");
char mobile[20];
scanf("%s%*c",mobile);
char op;
printf("\n\tAdd more details [Y/N] : ");
scanf("%c",&op);
if(op==89||op==121)
{
printf("\n\tEmail Id    : ");
char emailid[30];
scanf("%s",emailid);
printf("\n\tBirthdate   : ");
char birthd[15];
scanf("%s",birthd);
printf("\n\tRelation    : ");
char rel[15];
scanf("%s",rel);
fprintf(fp,"%s %s %s %s %s %s\n",name,sur,mobile,emailid,birthd,rel);
fclose(fp);
}
else{
char emailid[30]="-------";
char birthd[15]="-------";
char rel[15]="-------";
fprintf(fp,"%s %s %s %s %s %s\n",name,sur,mobile,emailid,birthd,rel);
fclose(fp);}
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
main();
}

void search_contact()
{
system("color F9");
FILE *fp;
int a=1,i=1;
fp=fopen("contact.txt","r");
system("cls");
printf("\t\t\t\t\t        SEARCH CONTACT");
printf("\n\n\n\tEnter Name : ");
char name[20];
scanf("%s",name);
char name1[20],sur[20],mobile[20],emailid[30],birthd[15],rel[15];
while(fscanf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
if(strcmp(name,name1)==0){
printf("\n\tName        : %s",name1);
printf("\n\tSurname     : %s",sur);
printf("\n\tMobile no.  : %s",mobile);
printf("\n\tEmail ID    : %s",emailid);
printf("\n\tBirthdate   : %s",birthd);
printf("\n\tRelation    : %s",rel);
printf("\n\n");
}
else
a++;
i++;
}
if(a==i)
printf("\n\n\n\tNo such contact found");
fclose(fp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
main();
}

void delete_contact()
{
system("color FA");
int a=0,i=0;
FILE *fp,*fp1;
fp=fopen("contact.txt","r+");
fp1=fopen("temp.txt","w");
system("cls");
printf("\t\t\t\t\t        DELETE CONTACT");
printf("\n\n\n\tEnter Name : ");
char name[20];
scanf("%s",name);
char name1[20],sur[20],mobile[20],emailid[30],birthd[15],rel[15];
while(fscanf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
i++;
if(strcmp(name,name1)==0)
{
continue;
}
fprintf(fp1,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel);
if(strcmp(name,name1)!=0)
a++;
}
fclose(fp);
fclose(fp1);
fp=fopen("contact.txt","w");
fp1=fopen("temp.txt","r");
while(fscanf(fp1,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
    fprintf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel);
}
fclose(fp);
fclose(fp1);
remove("temp.txt");
if(a==i)
printf("\n\n\n\tNo such contact found");
else
printf("\n\n\n\tContact deleted Successfully");
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
main();
}

void view_all_contact()
{
system("color FB");
FILE *fp;
int i=0;
fp=fopen("contact.txt","r");
system("cls");
printf("\t\t\t\t\t        ALL CONTACTS\n");
char name1[20],sur[20],mobile[20],emailid[30],birthd[15],rel[15];
while(fscanf(fp,"%s %s %s %s %s %s\n",name1,sur,mobile,emailid,birthd,rel)!=EOF)
{
printf("\n\n\tName        : %s",name1);
printf("\n\tSurname     : %s",sur);
printf("\n\tMobile no.  : %s",mobile);
printf("\n\tEmail ID    : %s",emailid);
printf("\n\tBirthdate   : %s",birthd);
printf("\n\tRelation    : %s",rel);
i++;
}
printf("\n\n\n\t%d contacts found",i);
fclose(fp);
printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
main();
}
