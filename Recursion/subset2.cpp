// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 void makes(int n, vector <int> &ds, vector<vector<int>> &result, vector<int> &arr){
        // FIRST APPROACH

        // if(n>=arr.size())
        // {
        //     result.push_back(ds);
        //     return;
        // }
        // ds.push_back(arr[n]);
        // makes(n+1, ds, result, arr);
        // ds.pop_back();
        // if(ds.size() && ds[ds.size()-1]==arr[n]) return;
        // makes(n+1, ds, result, arr);
        
        //SECOND APPROACH
        result.push_back(ds);
        for(int i=n;i<arr.size();i++){
            
            if(i!=n && arr[i]==arr[i-1]) continue;
            
            ds.push_back(arr[i]);
            makes(i+1, ds, result, arr);
            ds.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector <vector<int>> result;
        sort(nums.begin(),nums.end());
        makes(0, ds, result, nums);
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
    output = subsetsWithDup(arr);
    for(auto i:output)
    {
        cout<<"[ ";
        for(auto x:i) cout<<x<<" ";
        cout<<"]"<<endl;
    }
    
    return 0;
}