#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    string s; cin >> s;
    map<char,int>mp;
    for(auto &c:s) mp[c]++;

    int mx=0;
    for(auto &[value,cnt]:mp) if(cnt>=mx) mx=cnt;
    char ans='z';
    for(auto &[value,cnt]:mp) if(mx==cnt) ans=min(ans,value);
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}