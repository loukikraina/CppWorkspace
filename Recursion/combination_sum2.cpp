// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void T_sum(int n, int sum, vector <int> &a, vector <int> &arr, int N, int tsum, vector <vector<int>> &b){
        if(sum==tsum){
            for(auto x: b) if(x.size() == a.size() && x==a) return;
            b.push_back(a);
            return;
        }
    if(n>=N) return;
    if(sum>tsum) return;
    
    a.push_back(arr[n]);
    T_sum(n+1, sum+arr[n], a,arr,N, tsum, b);
    a.pop_back();
    if(a.size()>0 && a.back()==arr[n]) return;
    T_sum(n+1, sum, a,arr,N, tsum, b);
}


int main() {
    cout << "Hello world!\n";
    int n,a;
    cin >> n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back(a);
    }
    int tsum;
    cin>>tsum;
    vector <int> ds;
    vector <vector<int>> fv;
    sort(arr.begin(),arr.end());
    T_sum(0, 0, ds , arr, n, tsum, fv);
    for(auto i:fv)
    {
        for(auto x:i ) cout<<x<<" ";
        cout<<endl;
    }
    
    return 0;
}