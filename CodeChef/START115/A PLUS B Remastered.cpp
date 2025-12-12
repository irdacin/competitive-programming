#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n], b[n];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    sort(a, a+n);
    sort(b, b+n, greater<int>());

    int c=a[0]+b[0];
    for(int i=1;i<n;i++) if(a[i]+b[i]!=c) return void(cout << -1);

    for(auto i:a) cout << i << ' ';
    cout << endl;
    for(auto i:b) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}