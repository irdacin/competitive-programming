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

    map<int,int> mp;
    int cnt = 1, ans = n;
    for(auto i:a){
        if(mp.find(i)!=mp.end()){
            ans = min(ans, cnt-mp[i]);
        }
        mp[i] = cnt;
        cnt++;
    }

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}