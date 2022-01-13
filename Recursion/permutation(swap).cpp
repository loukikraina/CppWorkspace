// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void permutations(int n, vector<vector<int>> &result, vector<int> &arr){
        if(n>=arr.size()-1){
            result.push_back(arr);
            return;
        }
        for(int i=n;i<arr.size();i++){
            swap(arr[n],arr[i]);
            permutations(n+1, result, arr);
            swap(arr[n],arr[i]);            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int> ds;
        vector <vector<int>> result;
        permutations(0, result, nums);
        return result;
    }




int main() {
    cout << "Hello world!\n";
    int n,a;
    cin >> n;
    vector <int> arr;
    vector <vector<int>> output;
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back(a);
    }
    output = permute(arr);
    for(auto i:output)
    {
        cout<<"[ ";
        for(auto x:i) cout<<x<<" ";
        cout<<"]"<<endl;
    }
    
    return 0;
}