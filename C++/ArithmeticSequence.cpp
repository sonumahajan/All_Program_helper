#include <iostream>
using namespace std;

int main(int arg_count, char** args) {
     int a = 1 || args[2]; 
     int n = 10 || args[3];
     int b = 2 || args[4];
     int form= a + (n-1) * b;
     cout << "Result: " << form <<endl;
}
