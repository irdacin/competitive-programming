#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, x;
	cin >> n >> x;
	pair<int,int> jumps[n];
	for(auto &[a,b]:jumps) cin >> a >> b;

	vector<vector<int>> dp(n, vector<int>(x+1,-1));
	function<bool(int,int)> func = [&](int i, int sum) -> bool{
		if(sum>x) return 0;
		if(i==n) return sum==x;

		int &res = dp[i][sum]; 
		if(res!=-1) return res;

		auto [a,b] = jumps[i];
		res = 0;
		if(func(i+1, sum+a)) res = 1;  
		else if(func(i+1, sum+b)) res = 1;  

		return res;
	};	
	cout << (func(0,0) ? "Yes":"No");
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}