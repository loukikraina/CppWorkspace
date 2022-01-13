// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool check(int col,int row, vector <string> &ds, int n){
        int dc = col;
        int dr = row;
        while(dc>=0 && dr>=0) if(ds[dc--][dr--]=='Q') return false;  
        dc= col; dr = row;
        while(dc>=0) if(ds[dc--][dr]=='Q') return false;
        while(col>=0 && row<n) if(ds[col--][row++]=='Q') return false;
        return true;
    }
    
    void sol(int index, vector<string> &ds, vector<vector<string>> &result, int n){
        if(index>=n){
            result.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(check(index,i, ds, n)){
                ds[index][i] = 'Q';
                sol(index+1, ds, result, n);
                ds[index][i] = '.';
            }
        }
    }    
    vector<vector<string>> solveNQueens(int n) {
        vector <string> ds ;
        string s(n, '.');
        for(int i=0;i<n;i++)
                ds.push_back(s);
        vector<vector<string>> result;
        sol(0, ds, result, n);
        return result;
    }




int main() {
    cout << "Hello world!\n";
    int n;
    cin >> n;
    vector <vector<string>> output;
    output = solveNQueens(n);
    for(auto i:output)
    {
        cout<<"[ ";
        for(auto x:i) cout<<x<<" ";
        cout<<"]"<<endl;
    }
    
    return 0;
}