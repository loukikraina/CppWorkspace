// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void power_set(int n, int sum, vector <int> &a, int arr[], int N, int req_sum){
    if(n>=N){
        if(sum==req_sum){
        for(auto i:a ) cout<<i<<" "; 
        cout<<endl;
        }
        return;
    }
    a.push_back(arr[n]);
    power_set(n+1, sum+arr[n], a,arr,N, req_sum);
    a.pop_back();
    power_set(n+1, sum, a,arr,N, req_sum);
}


int main() {
    cout << "Hello world!\n";
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    vector <int> ds;
    power_set(0, 0, ds , arr, n, 0);
    return 0;
}