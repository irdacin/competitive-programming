#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;
    map<char, int>mp;
    for(auto &c:s) mp[c]++;

    int ans=0;
    for(auto &[word, cnt]:mp)
        if(word-'A'<=cnt-1) ans++;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}