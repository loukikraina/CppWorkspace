#include <bits/stdc++.h>

using namespace std;


#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void recurse(int index, int size, int &result, int a[], int rsum, int csum, int n){
    if(index>=n){
        if(csum>=rsum){
            result = min(result, size);
        }
        return;
    }
    recurse(index+1, size+1, result, a, rsum, csum + a[index], n);
    recurse(index+1, size, result, a, rsum, csum, n);

}


int solve() {
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int result = n+1;
    recurse(0, 0, result, a, x, 0, n);
    return result<(n+1)? result:-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout<<solve()<<endl;;
    }
    return 0;
}