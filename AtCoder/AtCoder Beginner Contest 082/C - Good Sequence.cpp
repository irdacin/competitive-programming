#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){    
    int n, a; cin >> n;
    map<int,int>mp;
    while(n--) cin >> a, mp[a]++;

    int ans=0;
    for(auto &[value,cnt]:mp){
        if(value==cnt) continue;
        else if(value<cnt) ans+=cnt-value;
        else ans+=cnt;
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