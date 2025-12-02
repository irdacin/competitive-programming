#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n-1];
    for(auto &i:a) cin >> i;
    int ans=0;
    for(auto &i:a) ans+=i;
    cout << ans*-1 << endl;
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}