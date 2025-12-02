#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int i=0, j=n-1;
    for(;i<n && a[i]!=1;i++);
    for(;j>=0 && a[j]!=1;j--);
    // cout << i << ' ' << j;

    int ans=0;
    for(;i<=j;i++) if(a[i]==0) ans++;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}