// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void sol(int index, vector<string> &ds, vector<vector<string>> &result, int n,
            vector <int> l, vector <int> ld, vector <int> ud){
        if(index>=n){
            result.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if( l[i] == 0 && ld[index+i] == 0 && ud[n-1 + index - i] == 0 ){
                ds[index][i] = 'Q';
                l[i] = 1;
                ld[index+i] = 1;
                ud[n-1 + index - i] = 1;
                sol(index+1, ds, result, n, l, ld, ud);
                ds[index][i] = '.';
                l[i] = 0;
                ld[index+i] = 0;
                ud[n-1 + index - i] = 0;
            }
        }
    }    
    vector<vector<string>> solveNQueens(int n) {
        vector <string> ds ;
        string s(n, '.');
        for(int i=0;i<n;i++)
                ds.push_back(s);
        vector <int> leftRow(n,0), lowerD(2*n -1, 0), upperD(2*n -1 , 0);
        vector<vector<string>> result;
        sol(0, ds, result, n, leftRow, lowerD, upperD);
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