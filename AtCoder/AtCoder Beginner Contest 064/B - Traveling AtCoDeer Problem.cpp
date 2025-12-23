#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;
    sort(a,a+n);
    int ans=0, cur=a[0];
    for(auto &i:a) ans+=abs(cur-i), cur=i;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}