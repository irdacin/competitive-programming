#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    string s;
    cin >> s;

    map<char,int>mp;
    int cnt=0;
    for(auto &c:s){
        mp[c]++;
        if(mp[c]==2){
            cnt++;
            mp.clear();
        }
    }
    cout << (int)s.length()-cnt*2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}