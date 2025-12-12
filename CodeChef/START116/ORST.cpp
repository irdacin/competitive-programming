#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(auto &i:a) cin >> i;
    int mx=0;
    for(auto &i:b) cin >> i, mx=max(i,mx);
    
    sort(a+(n-mx),a+n);
    for(auto &i:a) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}