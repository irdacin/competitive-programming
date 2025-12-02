#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int>one, two, three;
    while(n--){
        int a, k; cin >> a >> k;
        if(a==1) one.push_back(k);
        else if(a==2) two.push_back(k);
        else three.push_back(k);
    }

    int mn=INT_MIN, mx=INT_MAX;
    for(auto &i:one) mn=max(mn, i);
    for(auto &i:two) mx=min(mx, i);

    int cnt=0;
    // cout << mn << ' ' << mx << endl;
    for(auto &i:three) if(mn<=i && i<=mx) cnt++;
    int ans=mx-mn+1-cnt;
    cout << (ans<=0 ? 0:ans);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}