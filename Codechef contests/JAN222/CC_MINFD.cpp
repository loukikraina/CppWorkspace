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


int recurse(int a[], int n, int rsum){
    int pointer = n-1, csum = a[n-1], count = 1;
    for(int i=n-2;i>=0;i--)
    {
        if(csum==rsum) break;
        if(csum>rsum){
            int temp = csum;
            if(csum-a[pointer]>csum-a[i+1] && csum-a[i+1]+a[i]>=rsum ) csum = csum-a[i+1]+a[i];
            else if (csum-a[pointer]+a[i]>=rsum) csum -= a[pointer--];
            
            if(temp!=csum) count--;
        }
        if(csum<rsum){
        csum += a[i];
        count++;
        }
    }
    if(csum>=rsum)
        return count;
    return -1;
}


int solve() {
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    return recurse(a, n, x);
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