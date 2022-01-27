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

void permutations(vector<int> &ds, int n, int index, int k, int a[], int b[], set<int> &maxi){
    if(ds.size()==k){
        int asum = 0, bsum = 0;
        for(auto x:ds ){
            asum += a[x];
            bsum += b[x];
        }
        maxi.insert(min(asum,bsum));
        return;
    }
    if(index>=n) return;
    
    ds.push_back(index);
    permutations(ds, n, index+1, k, a, b, maxi);
    ds.pop_back();
    permutations(ds, n, index+1, k, a, b, maxi);
}



void solve() {
    int n,k;
    cin>>n>>k;
    int a[n], b[n];
    vector<int> ds;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    set<int> maxi;
    permutations(ds, n, 0, k, a, b, maxi);
    cout<<*maxi.rbegin();
    
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