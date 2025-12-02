#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=n-k;i<=n;i++) cout << i << ' ';
    for(int i=n-k-1;i>0;i--) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}