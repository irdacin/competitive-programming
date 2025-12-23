#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	
	vector<vector<int>> dp(2, vector<int>(n+1, -1));
	function<int(int, int)> func = [&](int level, int red) -> int{
		if(level==1) return red==1 ? 0:1;

		int &res = dp[red][level];
		if(res!=-1) return res;
		
		if(red==1) res = func(level-1, 1) + func(level, 0)*x;
		else res = func(level-1, 1) + func(level-1, 0)*y; 

		return res;
	};

	cout << func(n, 1);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}