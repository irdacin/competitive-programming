#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>>a(n);
    for(auto &[x,y]:a) x=n--, y=0;

    int x = 1, y=0;
    while(q--){
        int t; cin>>t;
        if(t==1){
            char c; cin >> c;
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='R') x++;
            else x--;
            a.push_back({x,y});
        } else {
            int p; cin >> p;
            auto [x,y] = a[a.size()-p];
            cout << x << ' ' << y << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}