#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k;
	cin >> n >> k;
	int h[n];
	for(auto &i:h) cin >> i;

	vector<int> dp(n, -1);
	function<int(int, int)> func = [&](int i, int j) -> int{
		if(i>=n-k) return dp[i] = abs(h[n-1]-h[i]);

		int &res = dp[i];
		if(res!=-1) return res;

		res = INT_MAX;
		for(int next=i+1; next<=min(i+k, n-1); next++){
			res = min(res, func(next, i) + abs(h[next]-h[i]));
		}

		return res;
	};

	cout << func(0,0);
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}