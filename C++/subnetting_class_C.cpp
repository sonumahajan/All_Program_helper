#include<iostream>
#include<math.h>
using namespace std;
int main(){

int oktet1, oktet2, oktet3, oktet4, perfik, totalIp, kali, net, netwk, brodcast, b1, b2 ;

cout<<" ============================================== \n";
cout<<" PROGRAM PERHITUNGAN SUBNETTING KELAS  C \n";
cout<<" ============================================== \n";
cout<<endl;
cout<<" \t \t  Created By Joko Ardiyanto @ Universitas Boyolali \n ";
cout<<endl;

cout<<" Masukan nilai oket 1 : ";cin>>oktet1;
cout<<" Masukan nilai oket 2 : ";cin>>oktet2;
cout<<" Masukan nilai oket 3 : ";cin>>oktet3;
cout<<" Masukan nilai oket 4 : ";cin>>oktet4;
cout<<" Masukan perfik / ";cin>>perfik;
cout<<endl;

totalIp = 32 - perfik;
kali = pow(2, totalIp);
net = oktet4 / kali;
netwk = net * kali;
brodcast = netwk + kali - 1;
b1 = netwk + 1;
b2 = brodcast - 1;

cout<<" Ip Address "<<oktet1<<"."<<oktet2<<"."<<oktet3<<"."<<oktet4<<"/"<<perfik<<endl;
cout<<" Total IP   = "<<kali<<endl;
cout<<" Ip Network = "<<oktet1<<"."<<oktet2<<"."<<oktet3<<"."<<netwk<<endl;
cout<<" Broadcast  = "<<oktet1<<"."<<oktet2<<"."<<oktet3<<"."<<brodcast<<endl;
cout<<" Range Ip   = "<<oktet1<<"."<<oktet2<<"."<<oktet3<<"."<<b1<<" S/D "<<oktet1<<"."<<oktet2<<"."<<oktet3<<"."<<b2<<endl;
cout<<endl;

cout<<"================================*******=========================\n";
cout<<" \t  \t \t      By joko-ardi 2021 ! \n";
cout<<"================================*******=========================\n";

return 0;

}
