#include<bits/stdc++.h>
using namespace std;


bool checkPalindrome(string s){
        int st = 0; int e = s.length()-1;
        while(st<=e){
            if(s[st++]!=s[e--]) return false;
        }
        return true;
    }
    void solve(int pointer, vector<string> &ds, string s, vector<vector<string>> &result){
        if(pointer>=s.length()){
            result.push_back(ds);
            return;
        }
        for(int i=0;i<s.length()-pointer;i++){
            string subs = s.substr(pointer, i+1);
            if(checkPalindrome(subs)){
                ds.push_back(subs);
                solve(pointer+i+1, ds, s, result);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> result;
        solve(0, ds, s, result);
        return result;
    }
    
int main(){
    string s;
    cin>>s;
    vector<vector<string>> result;
    result = partition(s);
    cout<<"[";
    for(auto i:result ){
        cout<<" [ ";
        for(auto x:i) cout<<"'"<<x<<"' ";
        cout<<"]";
    }
    cout<<" ]";
    return 0;
}