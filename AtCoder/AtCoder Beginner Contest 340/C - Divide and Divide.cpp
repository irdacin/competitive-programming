#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    
    map<int,int>dp;
    function<int(int)> func = [&](int n) -> int{
        if(n==1) return 0;

        int &res = dp[n];
        if(res!=0) return res;

        res = func(n/2) + func((n+1)/2) + n;
        return res;
    };

    cout << func(n);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}