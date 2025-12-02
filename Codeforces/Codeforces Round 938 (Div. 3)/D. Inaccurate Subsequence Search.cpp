#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    map<int,int> mp;
    int a[n], b[m];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i, mp[i]++;

    int cnt = 0, ans = 0;
    int i = 0;
    for(; i<m-1; i++){
        if(mp[a[i]] > 0) cnt++;
        mp[a[i]]--;
    }
    
    // cout << cnt << endl;

    for(; i<n; i++){
        
        if(mp[a[i]] > 0) cnt++;
        mp[a[i]]--;
        
        if(cnt>=k) ans++;

        mp[a[i-m+1]]++;
        if(mp[a[i-m+1]] > 0) cnt--;

        // cout << cnt << endl;
    }

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}