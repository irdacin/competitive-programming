#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string t; cin >> t;
    int n; cin >> n;

    vector<vector<string>> vec(n);
    for(auto &v:vec){
        int a; cin >> a;
        string s;
        while(a--) cin >> s, v.push_back(s);
    }

	vector<vector<int>> dp(n, vector<int>(len(t)+1, -1));
    auto func = [&](auto func, int i, int s) -> int{
        if(i==n){
            if(s==len(t)) return 0;
            else return INT_MAX;
        }

        int &res = dp[i][s];
		if(res!=-1) return res;

		res = func(func, i+1, s);
        for(auto str:vec[i]){
			if(len(str) + s > len(t)) continue;
			if(t.substr(s, len(str)) == str) res = min(res, func(func, i+1, s+len(str))+1);
		}
		
        return res;
    };

    int ans = func(func, 0, 0);
    if(ans==INT_MAX) cout << -1;
    else cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}