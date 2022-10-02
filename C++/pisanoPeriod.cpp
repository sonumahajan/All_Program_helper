#include <bits/stdc++.h>
using namespace std;
#define int long long int

/**
 *
 * https://www.geeksforgeeks.org/fibonacci-number-modulo-m-and-pisano-period/
 *
 *
 * n is order of 10 ^ 14
 * and mod is of order 2 <= mod <= 1000
 *
 * get period for fibonacci number
*/
int pisanoPeriod(int n, int mod) {
    int period = 0;
    int f1 = 0, f2 = 1;

    for (int i = 0; i <= mod * mod; i++) {
        int temp = (f1 + f2) % mod;
        f1 = f2;
        f2 = temp;

        if (f1 == 0 and f2 == 1)
            period = i + 1;
    }

    return period;
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    int period = pisanoPeriod(n, m);
    n %= period;

    int f1 = 0, f2 = 1;

    for (int i = 0; i < n; i++) {
        int temp = (f1 + f2) % m;
        f1 = f2;
        f2 = temp;
    }

    cout << f1 << endl;

    return 0;
}


