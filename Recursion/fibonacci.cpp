// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int fibonaaci(int n){
    if(n<=1){
        return n;
    }
    return fibonaaci(n-1)+fibonaaci(n-2);
}


int main() {
    // Write C++ code here
    cout << "Hello world!\n";
    int n;
    cin >> n;
    cout<<fibonaaci(n);
    

    return 0;
}