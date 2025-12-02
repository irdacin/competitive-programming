#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

const int MXN = 2e5+1;
int dp[MXN];
int lastComputed;

void solve(){
    int n; cin >> n;

    auto sumDigit = [](int n){
        int res=0;
        while(n>0) res+=n%10, n/=10;
        return res;
    };

    if(dp[n]!=0) exit(dp[n]);
    // cout << lastComputed << ' ';

    int res = dp[lastComputed];
    for(int i=lastComputed+1;i<=n;i++){
        res+=sumDigit(i);
        dp[i] = res;
        lastComputed = i;
    }

    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    int t; cin >> t; while(t--)
    solve(), cout << endl;
}