#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    string sisi[5] = {"AE", "DE","CD", "BC", "AB"};
    string diagonal[5] = {"AD","AC","BE","BD","CE"};

    string s, t;
    cin>> s>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    bool side = false;
    for(auto &i:sisi) if(s==i) side=true;

    string ans="No";
    if(side){
        for(auto &i:sisi) if(t==i) ans="Yes";
    }
    else{
        for(auto &i:diagonal) if(t==i) ans="Yes";
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}