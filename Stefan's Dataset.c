//Stefan's Experiment dataset using Vf & If
#include<stdio.h>
#include<math.h>
int main(){
	float v,i,r,p,t,result,absolute;
	printf("\n Enter Value of Vf =");
	scanf("\t%f",&v);
	printf("\n Enter Value of If =");
	scanf("\t%f",&i);
	r=v/i;
	p=v*i;
	t=144.57+ 187.316*(r/0.6);
	result=log10(p);
	absolute=log10(t);
	printf("\n Rt= %f",r);
	printf("\n P =  %f",p);
	printf("\n (Rt/0.6) is= %f",r/0.6);
	printf("\n T is = %f",t);
	printf("\n Log(p) = %f",result);
	printf("\n Log(t) = %f",absolute);
	return 0;
}

