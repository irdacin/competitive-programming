#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, w; cin >> n >> w;
	pair<int, int> items[n];
	int sumValue = 0;
	for(auto &[weight,value]:items) cin >> weight >> value, sumValue+=value;

	vector<vector<int>> dp(n, vector<int>(sumValue+1, -1));
	function<int(int, int)> func = [&](int i, int v) -> int{
		if(i==n) return v==0 ? 0:INT_MAX;

		int &res = dp[i][v];
		if(res!=-1) return res;

		auto [weight,value] = items[i];
		res = func(i+1, v);
		if(v >= value) res = min(res, func(i+1, v-value)+weight);
		return res;
	};

	int ans = 0;
	for(int value=1; value<=sumValue; value++){
		if(func(0,value) <= w) ans = value;
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