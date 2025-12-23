#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
	int a[n], b[n], c[n];
	for(int i=0;i<n; i++) cin >> a[i] >> b[i] >> c[i];

	vector<vector<int>> dp(3, vector<int>(n, -1));
	function<int(int, int)> func = [&](int i, int cur) -> int{
		if(i==n) return 0;

		int &res = dp[cur][i];
		if(res!=-1) return res;
		
		if(cur==0) res = max(func(i+1, 1), func(i+1, 2)) + a[i];
		else if(cur==1) res = max(func(i+1, 0), func(i+1, 2)) + b[i];
		else res = max(func(i+1, 0), func(i+1, 1)) + c[i];

		return res;
	};

	cout << max(func(0,0), max(func(0,1), func(0,2)));
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}