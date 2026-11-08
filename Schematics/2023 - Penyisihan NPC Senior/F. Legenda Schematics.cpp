#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	
	string ans = "";
	int mxValue = LLONG_MIN;
	while(n--){
		string s; cin >> s;
		int m; cin >> m;
		vector<int> a(m);
		for(auto &i:a) cin >> i;

		vector<vector<int>> dp(m, vector<int>(2, -1));
		auto func = [&](auto func, int i, int take) -> int{
			if(i==m){
				if(take) return 0;
				else return LLONG_MIN;
			}

			int &res = dp[i][take];
			if(res!=-1) return res;

			res = 0;
			if(take) res = max(res, func(func, i+1, 1) + a[i]);
			else res = max({res, func(func, i+1, 0), func(func, i+1, 1) + a[i]});
			return res;
		};

		int res = func(func, 0, 0);

		// cout << res << endl;
		if(res > mxValue) mxValue = res, ans = s;
	}

	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}