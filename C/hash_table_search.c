#include<stdio.h>
#define size 30
struct hash
{
    int index,key;

};
int hash(int key)
{
    return key%10;
}
int option()
{
    int n;
    printf("\n i)Add key");
    printf("\n ii)Find key");
    printf("\n iii)Remove key");
    printf("\n iv)Exit");
    printf("\n Enter choice");
    scanf("%d",&n);
    return n;


}
void main()
{
    struct hash table[size];
    int choice,key,i,ind;
    for(i=0;i<size;i++)
    {
        table[i].key=0;
    }
    do
    {
        choice=option();
        if(choice==1)
        {
            printf("\n Enter key");
            scanf("%d",&key);
            ind=hash(key);
            if(table[ind].key==0)
            {

                table[ind].index=ind;
                table[ind].key=key;
            }
            else
                printf("\n collision");
        }
        else if(choice==2)
        {
           printf("\n Enter key to find");
           scanf("%d",&key);
           ind=hash(key);
           if(table[ind].key==key)
            printf("\n search successful");
           else
            printf("\n search unsuccessful");

        }
        else if(choice==3)
        {

            printf("\n Enter key to remove");
            scanf("%d",&key);
            if(table[ind].key==key)
            {
            ind=hash(key);
            table[ind].key=0;
            }
            else
                printf("\n No such element");
        }
    }while(choice!=4);
}

