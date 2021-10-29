#include<iostream>
using namespace std;
 int st1[5],st2[10];
int r=-1,r1=-1,u=0;
void insert_element()
{
    if(r==4)
    {
        cout<<"Stack overflow!!"<<endl;
    }
    else
    {
        int ele;
        cout<<"Enter the element : "<<endl;
        cin>>ele;
        st1[r+1]=ele;
        r++;
        cout<<"Element inserted"<<endl;
    }
}
void remove_element()
{
    if(r==-1)
    {
        cout<<"Stack underflow!!"<<endl;
    }
    else
    {
        cout<<"Element "<<st1[r]<<" removed successfully!!"<<endl;
        st2[r1+1]=st1[r];
        r--;
        r1++;
    }
}
bool st2empty()
{
    if(r1==-1)
    {
        return true;
    }
    else
        return false;
}
void undo()
{
    if(st2empty() and r!=-1)
    {
        st2[r1+1]=st1[r];
        r--;
        r1++;
        cout<<"Undo operation successfull!!"<<endl;
    }
    else if(st2empty() and r==-1)
    {
        cout<<"Stack underflow!1"<<endl;
    }
    else
    {
        st1[r+1]=st2[r1];
        r1--;
        r++;
        cout<<"Undo operation successfull!!"<<endl;

    }
    u=1;
}
void display()
{
    if(r==-1)
        cout<<"Stack is empty!"<<endl;
    else
    {
        for(int i=0;i<=r;i++)
        {
            cout<<st1[i]<<"  "<<endl;
        }
    }
}
void redo(){
    if(u==0)
    {
      cout<<"Invalid operation.Perform undo first!!"<<endl;
    }
    else
    {

    }
}
int main()
{
    int i;
    do{
            printf("\n****************MENU**********************\n");
            printf("\n1-INSERT elements in Stack:\n");
            printf("2- REmOVE elements in Stack:\n");
            printf("3-DISPLAY elements in Stack:\n");
            printf("4-Undo elements in Stack:\n");
            printf("5-Redo elements in Stack:(if undo operation takes place then only redo takes place)\n");
            printf("6-EXIT\n");
            printf("Provide your choice :");
            cin>>i;
            switch(i)
            {
            case 1:
                insert_element();
                break;
            case 2:
                remove_element();
                break;
            case 3:
                display();
                break;
            case 4:
                undo();
                break;
            case 5:
                redo();
                break;
            case 6:
                exit(0);
            }
}while(true);

}
