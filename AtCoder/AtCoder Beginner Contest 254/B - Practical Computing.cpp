#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;

    int dp[n][n];
    memset(dp, -1,sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<n; i++){
        dp[i][0] = 1, dp[i][i] = 1;
        for(int j=1;j<i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(dp[i][j]!=-1) cout << dp[i][j] << ' ';
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}