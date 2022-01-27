#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void permutations(vector<int> &ds, vector<vector<int>> &permute, int n, int index, int k){
    if(ds.size()==k){
        permute.push_back(ds);
        return;
    }
    if(index>=n) return;
    
    ds.push_back(index);
    permutations(ds, permute, n, index+1, k);
    ds.pop_back();
    permutations(ds, permute, n, index+1, k);
}



void solve() {
    int n,k;
    cin>>n>>k;
    int a[n], b[n];
    vector<vector<int>> permute;
    vector<int> ds;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    permutations(ds, permute, n, 0, k);
    int maxi = INT_MIN;
    int asum ,bsum;
    
    for(auto combi:permute){
        asum = 0;
        bsum = 0;
        for(auto x:combi ){
            asum += a[x];
            bsum += b[x];
        }
        maxi = max(maxi, min(asum,bsum));
    }
    
    
    cout<<maxi;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout<<endl;
    }
}