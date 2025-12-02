#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, k; 
    cin >> n >> k;
    int a[n]; map<int,int>mp;
    for(auto &i:a) cin >> i, mp[i]++;

    int odd=0;
    for(auto [type,cnt]:mp) odd+=cnt%2;
    cout << n - odd/2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}