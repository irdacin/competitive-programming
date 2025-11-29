#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    const int MOD = 1e9+7;

    int n; cin >> n;

    vector<int> dp(n, -1);
    function<int(int)> func = [&](int cnt) -> int{
        if(cnt==n) return 1;

        int &res = dp[cnt];
        if(res!=-1) return res;

        res = 0;
        for(int i=1;i<=6;i++){
            if(i+cnt<=n) res+=func(i+cnt) % MOD;
        }

        return res % MOD;
    };

    cout << func(0);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}