// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 void permutations(vector <int> &ds, vector<vector<int>> &result, vector<int> &arr,
                     map <int,int> &mapper){
        if(ds.size()==arr.size())
            result.push_back(ds);
        for(int i=0;i<arr.size();i++){
            if(mapper[i]!=0) continue;
            ds.push_back(arr[i]);
            mapper[i]=1;
            permutations(ds, result, arr, mapper);
            ds.pop_back();
            mapper[i]=0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector <vector<int>> result;
        map <int,int> mapper;
        for(auto num:nums) mapper[num] = 0;
        permutations(ds, result, nums, mapper);
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