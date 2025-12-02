#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

map<tuple<int,int,int>,int> mp;

void solve(){
    int a, b, l;
    cin >> a >> b >> l;
    tuple<int,int,int> tp = {a,b,l};
    if(mp.find(tp)!=mp.end()) exit(mp[tp]);

    vector<int> factors;
    for(int i=1; i*i<=l; i++){
        if(l%i==0){
            factors.push_back(i);
            if(i!=l/i) factors.push_back(l/i);
        }
    }

    function<int(int,int)> power = [&](int a, int k) -> int{
        if(k==0) return 1;
        int res = power(a, k/2);
        return k&1 ? res*res*a:res*res;
    };


    int ans=0;
    for(auto k:factors){
        map<pair<int,int>,bool> dp;
        function<bool(int, int)> func = [&](int x, int y) -> bool{
            int res = k*power(a,x)*power(b,y);
            if(res==l) return true;
            if(res>l) return false;

            if(dp.find({x,y})!=dp.end()) return dp[{x,y}];

            int ret = 0;
            if(func(x+1, y)) ret = 1;
            else if(func(x,y+1)) ret = 1;
            else if(func(x+1, y+1)) ret = 1;

            return dp[{x,y}] = ret;
        };

        if(func(0,0)) ans++;
    }

    mp[{a,b,l}] = ans;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}