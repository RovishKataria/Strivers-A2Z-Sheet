// https://www.naukri.com/code360/problems/even-or-odd_7463066
// https://www.geeksforgeeks.org/problems/odd-or-even3618/1
// https://www.youtube.com/watch?v=nttpF8kwgd4

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n & 1) {
        cout << "Odd";
    } else {
        cout << "Even";
    }

    return 0;
	
}
