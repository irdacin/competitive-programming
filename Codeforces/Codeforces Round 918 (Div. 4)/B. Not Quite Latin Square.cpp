#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    char s[3][3];
    map<char,int> mp;
    for(auto &c:s) for(auto &a:c) cin >> a, mp[a]++;
    for(auto &[value,cnt]:mp) if(cnt==2) return void(cout<<value);
}   

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}