#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[2*n];
    for(auto &i:a) cin >> i;
    sort(a, a+2*n);

    int ans=0;
    for(int i=0;i<2*n;i+=2) ans+=min(a[i], a[i+1]);
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}