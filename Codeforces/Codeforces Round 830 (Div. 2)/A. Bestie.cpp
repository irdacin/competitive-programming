#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    // auto gcd = [](auto gcd, int a, int b){
    //     if(b==0) return a;
    //     return gcd(gcd, b, a%b);
    // };

    int arr_gcd[n];
    for(int i=1;i<=n;i++) arr_gcd[i-1] = gcd(a[i-1], i);

    
    vector<vector<int>> dp(n, vector<int>(2, -1));
    function<int(int, int, int)> func = [&](int i, int result, int change) -> int{
        if(i==n){
            // int res = a[0];
            // for(int i=1; i<n;i++) res = gcd(res, a[i]);
            if(result==1) return 0;
            else return INT_MAX;
        }

        int &res = dp[i][change];
        if(res!=-1) return res;

        res = func(i+1, gcd(result, a[i]), 0);
        res = min(res, func(i+1, gcd(result, arr_gcd[i]), 1)+n-i);
        return res;
    };

    cout << func(0, a[0], 0);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}