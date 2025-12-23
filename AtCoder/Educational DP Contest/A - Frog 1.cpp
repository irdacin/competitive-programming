#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int h[n];
    for(auto &i:h) cin >> i;

    vector<int>dp(n,-1);
    function<int(int)> func = [&](int i) -> int{
        // if(i>=n) return 0;
        if(i==n-2) return abs(h[i+1]-h[i]);
        if(i==n-3) return min(func(i+1) + abs(h[i+1]+h[i]), abs(h[i+2]-h[i]));

        int &res = dp[i];
        if(res!=-1) return res;

        int stone1 = func(i+1) + abs(h[i+1]-h[i]);
        int stone2 = func(i+2) + abs(h[i+2]-h[i]);
        return res = min(stone1, stone2);
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