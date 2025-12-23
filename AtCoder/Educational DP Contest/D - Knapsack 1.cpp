#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, w; cin >> n >> w;
	pair<int,int> items[n];
	for(auto &[weight,value]:items) cin >> weight >> value;

	// // greedy approach
	// sort(items, items+n, [](auto a, auto b){
	// 	return a.second > b.second;
	// });
	
	// int ans = 0;
	// for(auto [weight, value]:items){
	// 	if(w < weight) continue;
	// 	w-=weight;
	// 	ans+= value;
	// }
	// cout << ans;

	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	function<int(int,int)> func = [&](int i, int w) -> int{
		if(i==n || w==0) return 0;

		int &res = dp[i][w];
		if(res != -1) return res;
		
		auto [weight, value] = items[i];
		if(w < weight) res = func(i+1, w);
		else res = max(func(i+1, w), func(i+1, w-weight) + value);
		return res;
	};

	cout << func(0, w);
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}