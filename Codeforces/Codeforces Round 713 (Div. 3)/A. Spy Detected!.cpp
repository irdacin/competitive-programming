#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    map<int,int>mp;
    for(auto &i:a) cin >> i, mp[i]++;

    int dif=0;
    for(auto &[value,cnt]:mp) if(cnt==1) dif=value;
    int ans=1;
    for(auto &i:a) if(i==dif) return void(cout << ans); else ans++;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}