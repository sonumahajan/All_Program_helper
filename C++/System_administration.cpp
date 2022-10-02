#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int **a,**status,iid=4354,admin1=1154;int size[4]={0,0,0,0};
void deletelab();
void initlab(){
	int n1,c;
	a=new int*[4];
	status=new int*[4];
	for(int i=0;i<4;i++){
		cout<<"Enter the number of systems in the lab:";
		cin>>n1;
		size[i]=n1;
		a[i]=new int[n1];
		status[i]=new int[n1];
		cout<<"Lab "<<i+1<<" initialised"<<endl;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<6;j++){
			a[i][j]=0;
		}
	}
}
void user_entry(){
	int id,station,lab;
	id=iid;
	iid++;
	go1:
	cout<<"Enter the lab number and station number:";
	cin>>lab>>station;
	if(status[lab-1][station-1]==1){
		cout<<"The station is already taken "<<endl;
		goto go1;
	}
	else{
		a[lab-1][station-1]=id;status[lab-1][station-1]=1;
	}
	cout<<"Your lab id is "<<id<<endl<<"Please exit with your id while leaving lab"<<endl;
}
void admin_entry(){
	int hi=1;
	cout<<"\t\t\t\t\t ------------Welcome To C++ LAB---------------"<<endl;
	do{
	go:
	int a;
	cout<<"Enter your admin id:";
	cin>>a;
	if(a==admin1){
		cout<<"Welcome Admin....!"<<endl;
		initlab();
		break;
	}
	else{
		cout<<"You entered wrong id"<<endl<<"Please enter the original id"<<endl;
		hi++;
		if(hi==4){
		cout<<"Sorry you have entered the id wrong for 3 times";
		exit(0);
		}
		goto go;
	}
	}while(hi<3);
	
}
void admin(){
	int t1;
	cout<<endl<<"Currently the systems which are in use are:"<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<size[i];j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Enter 1 to continue 0 to shutdown";
	cin>>t1;
	if(t1==0){
		deletelab();
	}
}
void deletelab(){
	delete [] a;
	delete a;
	delete [] status;
	delete status;
	cout<<"Lab shutdown"<<endl;
	exit(0);
}

int main(){
	int t,c;
	admin_entry();
	
	do{
	cout<<"Enter 1 for user "<<endl<<" 2 for admin "<<endl;
	cin>>c;
	if(c==1){
		user_entry();
	}
	else{
		int hi1=1;
		do{
	go3:
	int a11;
	cout<<"Enter your admin id:";
	cin>>a11;
	if(a11==admin1){
		admin();break;
	}
	else{
		cout<<"You entered wrong id"<<endl<<"Please enter the original id"<<endl;
		hi1++;
		if(hi1==4){
		cout<<"Sorry you have entered the id wrong for 3 times";
		exit(0);
		}
		goto go3;
	}
	}while(hi1<3);
	}
	
	cout<<"Enter 1 to continue and 0 to discontinue:";
	cin>>t;
	if(t==0){
		admin();
	}
	
	}while(t!=0);
}