#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;
    map<char,int> mp;
    for(auto c:s) mp[c]++;

    char dif;
    for(auto &[ch,cnt]:mp) if(cnt==1) dif=ch;
    
    int ans=1;
    for(auto c:s) if(c==dif) exit(ans); else ans++;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}