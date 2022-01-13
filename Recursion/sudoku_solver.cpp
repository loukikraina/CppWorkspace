// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(char z, vector<vector<char>>& board, int row, int col){
        for(int i=0;i<board.size();i++){
            if(board[row][i]==z) return false;
            if(board[i][col]==z) return false;
            if(board[3* (row/3) + i/3][3* (col/3) + i%3]==z) return false;
        }
        return true;
    }
    
bool solve(vector<vector<char>>& board, int &n){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(board[i][j]=='.'){
                    for(char z = '1';z<='9';z++)
                    {
                        if(check(z, board, i, j)){
                            board[i][j] = z;
                            if(solve(board, n)) return true;
                            else board[i][j]='.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n);
    }

  

int main() {
    cout << "Hello world!\n";
    vector <vector<char>> output;
    char c;
    for(int i=0;i<9;i++){
        vector <char> a;
        for(int j=0;j<9;j++){
            cin>>c;
            a.push_back(c);
        }
        output.push_back(a);
    }
    solveSudoku(output);
    for(auto i:output)
    {
        cout<<"[ ";
        for(auto x:i) cout<<x<<" ";
        cout<<"]"<<endl;
    }
    
    return 0;
}