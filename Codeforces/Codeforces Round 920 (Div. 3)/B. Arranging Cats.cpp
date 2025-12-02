#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; string s, f;
    cin >> n >> s >> f;
    vector<pair<int,int>>cat;
    for(int i=0;i<n;i++){
        if(s[i]=='1' && f[i]=='1' || s[i]=='0' && f[i]=='0') continue;
        if(s[i]=='1') cat.push_back(make_pair(1, 0));
        else cat.push_back(make_pair(0, 1));
    }
    int ans=0, cntX=0, cntY=0;
    for(auto [x,y]:cat){
        cntX+=x; cntY+=y;
        if(cntX && cntY) ans++, cntX--, cntY--;
    }
    ans+=cntX+cntY;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}