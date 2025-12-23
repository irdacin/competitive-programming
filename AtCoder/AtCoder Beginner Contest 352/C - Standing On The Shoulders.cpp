#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    pair<int,int> giants[n];
    for(auto &[a,b]:giants) cin >> a >> b;
    
    int sum = 0;
    for(auto [a,b]:giants) sum+=a;
    int ans = 0;
    for(auto [a,b]:giants) ans=max(ans, sum-a+b);
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}