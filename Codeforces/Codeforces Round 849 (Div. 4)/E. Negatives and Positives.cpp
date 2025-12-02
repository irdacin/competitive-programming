#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    vector<vector<int>>dp(2,vector<int>(n,-1));
    function<int(int,int)>func = [&](int i, int neg) -> int{
        if(i==n-1){
            if(neg) return -1*a[i];
            else return a[i];
        }

        if(dp[neg][i]!=-1) return dp[neg][i];

        if(neg) dp[neg][i] = max(-1*a[i] + func(i+1,0), a[i] + func(i+1,1));
        else dp[neg][i] = max(-1*a[i] + func(i+1,1), a[i] + func(i+1,0));
        return dp[neg][i];
    };

    cout << func(0,0);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}