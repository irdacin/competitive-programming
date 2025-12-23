#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    map<char,int>mp;
    char c;
    for(int i=0;i<3;i++) cin >> c, mp[c]++;
    for(auto [ch,cnt]:mp) if(cnt==1) exit(ch);
    cout << -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}