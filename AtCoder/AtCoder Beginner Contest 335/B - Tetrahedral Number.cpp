#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    for(int k=0;k<=n;k++)
    if(i+j+k<=n)
    cout << i << ' ' << j << ' ' << k << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}