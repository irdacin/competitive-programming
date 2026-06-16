#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	string s1, s2;
	while(getline(cin, s1)){
		getline(cin, s2);
		int n = len(s1), m = len(s2);

		vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
		function<int(int, int)> func = [&](int n, int m) -> int{
			if(n==0 || m==0) return 0;

			int &res = dp[n][m];
			if(res!=-1) return res;

			if(s1[n-1]==s2[m-1]) return res = func(n-1, m-1) + 1;
			else res = max(func(n, m-1), func(n-1, m));
			return res;
		};

		cout << func(n, m) << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve();
}