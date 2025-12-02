#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int h1[n], h2[n];
    for(auto &i:h1) cin >> i;
    for(auto &i:h2) cin >> i;

    vector<vector<int>>dp(2,vector<int>(n,-1));
    function<int(int,int)>func = [&](int cnt, int row) -> int{
        if(cnt>=n) return 0;

        if(dp[row][cnt]!=-1) return dp[row][cnt];
        if(row==0) return dp[row][cnt] = max(func(cnt+1,1), max(func(cnt+2,0), func(cnt+2,1))) + h1[cnt];
        else return dp[row][cnt] = max(func(cnt+1,0), max(func(cnt+2,1), func(cnt+2,0))) + h2[cnt];
    };

    cout << max(func(0,0), func(0,1));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}