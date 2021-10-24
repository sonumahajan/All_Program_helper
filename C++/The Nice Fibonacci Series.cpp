#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main() {
    int userMaxNum, num0 = 0, num1 = 1, nextNum = 0;

    cout << "Write the max value you want: "; cin >> userMaxNum;

    cout << "The Fibonacci Series is almost ready in between ";
    sleep_for(500ms);
    cout << "3 ";
    sleep_for(1000ms);
    cout << "2 ";
    sleep_for(1000ms);
    cout << "1\n";
    sleep_for(1000ms);
    cout << "Wait!\n";
    sleep_for(2000ms);
    cout << "Something went wrong!?\n";
    sleep_for(1800ms);
    cout << "Ah nothing.\n";
    sleep_for(500ms);
    cout << "Here is the series\n";

    for (int i = 1; i <= userMaxNum; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << num0 << ", ";
        }
        if(i == 2) {
            cout << num1 << ", ";
        }
        nextNum = num0 + num1;
        num0 = num1;
        num1 = nextNum;

        cout << nextNum << ", ";
    }
    return 0;
}
