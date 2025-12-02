#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    int a[n];
    for(auto &i:a) cin >> i;
    
    auto fact = [](int n){
        if(n<=0) return (int)0;

        int res = n;
        while(n --> 0) res+=n;
        return res;
    };
    
    int ans = 0, cnt = 0;
    for(auto i:a){
        if(q < i){
            cnt-=(k-1);
            ans+=fact(cnt);
            // cout << cnt << endl;
            cnt = 0;
            continue;
        }

        cnt++;

    }

    // cout << cnt << endl;
    cnt-=(k-1);
    ans+=fact(cnt);
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}