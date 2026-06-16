#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int k; cin >> k;
    map<char, int> mp;
    while(k--){
        char ch; int cost;
        cin >> ch >> cost;
        mp[ch] = cost;
    }

    cin >> k;
    double ans=0;
    cin.ignore();
    while(k--){
        string s;
        getline(cin, s);

        for(auto c:s){
            if(mp.find(c) != mp.end()) ans+=mp[c];
        }

    }

    cout << setprecision(2) << fixed;
    cout << ans/100;
    cout << "$";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}