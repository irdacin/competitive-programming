#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int b[n];
    for(auto &i:b) cin >> i;

    int res=1;
    for(auto &i:b) res*=i;
    if(2023%res!=0) return void(cout << "NO");

    cout << "YES" << endl << 2023/res << ' ';
    while(k-->1) cout << 1 << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}