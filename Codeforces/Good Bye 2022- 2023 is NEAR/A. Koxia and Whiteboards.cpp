#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    for(auto &i:b){
        int mn=a[0];
        for(auto &j:a) mn=min(mn,j);
        for(auto &j:a) if(mn==j) {j=i;break;}
    }
    
    int ans=0;
    for(auto &i:a) ans+=i;

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}