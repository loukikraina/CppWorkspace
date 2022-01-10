// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool check(string s, int i){
    int n = s.length();
    if(i>=n/2)
        return true;
    return s[i] != s[n-i-1] ? false:true && check(s,i+1);
    
}


int main() {
    // Write C++ code here
    cout << "Hello world!\n";
    string s;
    cout<<"enter the string: \n";
    getline(cin, s);
    cout<<check(s,0);
    

    return 0;
}