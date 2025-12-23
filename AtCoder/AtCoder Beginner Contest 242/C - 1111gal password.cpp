#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	const int MOD = 998244353;
	int n; cin >> n;

	vector<vector<int>> dp(10, vector<int>(n+1, -1));
	function<int(int, int)> func = [&](int n, int cur) -> int{
		if(n==1) return 1;

		int &res = dp[cur][n];
		if(res!=-1) return res;

		if(cur==1) res = func(n-1, cur) % MOD+ func(n-1, cur+1)% MOD;
		else if(cur==9) res = func(n-1, cur-1) % MOD+ func(n-1, cur)% MOD;
		else res = func(n-1, cur-1) % MOD+ func(n-1, cur)% MOD + func(n-1, cur+1)% MOD;
		return res % MOD;
	};	

	int ans=0;
	for(int i=1; i<=9; i++) ans+= func(n, i), ans%=MOD;
	cout << ans;
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}