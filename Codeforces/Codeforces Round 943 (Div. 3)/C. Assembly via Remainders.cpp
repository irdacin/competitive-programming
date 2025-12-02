#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int x[n-1], mx = 0;
    for(auto &i:x) cin >> i, mx = max(mx, i);

    int a[n];
    a[0] = mx + 1;
    for(int i=1; i<n; i++){
        a[i] = a[i-1] + x[i-1];
    }    
    for(auto i:a) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}