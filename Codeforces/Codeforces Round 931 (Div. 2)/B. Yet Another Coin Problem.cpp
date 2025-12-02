#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;


    int ans = 0;
    for(auto i:{15,10,6,3,1}){
        if(n>=i){
            ans+=n/i-1;

            n%=i;
            n+=i;

            vector<int> dp(n+1, -1);
            function<int(int)> func = [&](int n) -> int{
                if(n==0) return 0;

                int &res = dp[n];
                if(res!=-1) return res;

                res = INT_MAX;
                for(auto i:{15,10,6,3,1}) if(n>=i) res=min(res, func(n-i)+1);
                return res;
            };
            
            ans+=func(n);

            cout << ans;
            return;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}