// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void power_set(int n, vector<int> &a, int arr[], int N){
    if(n>=N)
    {
        cout<<"{ ";
        for(auto i:a) cout<<i<<" ";
        cout<<"}"<<endl;
        return;
    }
    a.push_back(arr[n]);
    power_set(n+1,a,arr,N);
    a.pop_back();
    power_set(n+1,a,arr,N);
}


int main() {
    cout << "Hello world!\n";
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    vector <int> ds;
    power_set(0, ds , arr, n);
    return 0;
}