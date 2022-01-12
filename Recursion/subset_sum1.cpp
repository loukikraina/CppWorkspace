// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 vector<int> subsetSums(vector<int> arr, int N)
    {
        int power = pow(2,N);
        int sum = 0;
        vector <int> result;
        for(int i=0;i<power;i++){
            sum=0;
            for(int j=0;j<N;j++) if(i & (1<<j)) sum += arr[j];
            result.push_back(sum);
        }
        sort(result.begin(),result.end());
        return result;
    }
    
// OR RECURSIVE METHOD

    // void ssum(int n, vector <int> &ds, int sum, vector <int> &arr, int N){
    //     if(n>=N){
    //         ds.push_back(sum);
    //         return;  
    //     } 
    //     ssum(n+1, ds, sum+arr[n], arr, N);
    //     ssum(n+1, ds, sum, arr, N);
    // }


    // vector<int> subsetSums(vector<int> arr, int N)
    // {
    //     vector <int> result {};
    //     ssum(0, result, 0, arr, N);
    //     sort(result.begin(), result.end());
    //     return result;
        
    // }




int main() {
    cout << "Hello world!\n";
    int n,a;
    cin >> n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back(a);
    }
    arr = subsetSums(arr, n);
    sort(arr.begin(),arr.end());
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    
    return 0;
}