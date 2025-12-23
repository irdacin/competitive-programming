#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, t;
    cin >> n >> t;

    vector<int> s(n, 0);
    map<int,int> mp;
    mp[0] = n;

    int ans = 1;
    while(t--){
        int a, b; cin >> a >> b;

        int &value = s[a-1];
        mp[value]--;
        if(mp[value]==0) ans--;
        
        value += b;
        mp[value]++;
        if(mp[value]==1) ans++;

        cout << ans << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}