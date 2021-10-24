
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
#include<stdio.h>
 
int ary[10][10],completed[10],n,cost=0;
 
void takeInput()
{
int i,j;
 
printf("Enter the number of villages: ");
scanf("%d",&n);
 
printf("\nEnter the Cost Matrix\n");
 
for(i=0;i < n;i++)
{
printf("\nEnter Elements of Row: %d\n",i+1);
 
for( j=0;j < n;j++)
scanf("%d",&ary[i][j]);
 
completed[i]=0;
}
 
printf("\n\nThe cost list is:");
 
for( i=0;i < n;i++)
{
printf("\n");
 
for(j=0;j < n;j++)
printf("\t%d",ary[i][j]);
}
}
 
void mincost(int city)
{
int i,ncity;
 
completed[city]=1;
 
printf("%d--->",city+1);
ncity=least(city);
 
if(ncity==999)
{
ncity=0;
printf("%d",ncity+1);
cost+=ary[city][ncity];
 
return;
}
 
mincost(ncity);
}
 
int least(int c)
{
int i,nc=999;
int min=999,kmin;
 
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i]+ary[i][c] < min)
{
min=ary[i][0]+ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
if(min!=999)
cost+=kmin;
 
return nc;
}
 
int main()
{
takeInput();
 
printf("\n\nThe Path is:\n");
mincost(0); //passing 0 because starting vertex
 
printf("\n\nMinimum cost is %d\n ",cost);
 
return 0;
}
