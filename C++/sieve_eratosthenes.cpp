#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define ll long long int
using namespace std;

const int N = 100000;
int isPrime[N];
void sieve_eratosthenes(int n){
    for (int i = 2; i <= n; i++){
        if(isPrime[i]==0){
            for (int j = i*i; j <= n; j+=i){
                isPrime[j] = 1;
            } 
        }
    }
    for (int i = 2; i <=n; i++){
       if(isPrime[i]==0){
           cout << i << " ";
       }
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--){
        int n;
        cin>>n;
        sieve_eratosthenes(n);
    }
    return 0;
}