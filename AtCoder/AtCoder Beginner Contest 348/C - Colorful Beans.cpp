#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    pair<int,int> beans[n];
    for(auto &[a,c]:beans) cin >> a >> c;

    map<int,int> mp;
    for(auto [a,c]:beans){
        if(mp.find(c)!=mp.end()){
            mp[c] = min(mp[c], a);
        } else mp[c] = a;
    }

    int ans = INT_MIN;
    for(auto [c,a]:mp) ans = max(ans, a);
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}