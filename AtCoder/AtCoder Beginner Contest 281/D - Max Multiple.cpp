#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, k, d;
	cin >> n >> k >> d;
	int a[n];
	for(auto &i:a) cin >> i;
	
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(d+1,-1)));
	function<int(int,int,int)> func = [&](int i, int cnt, int m) -> int{
		if(cnt==k){
			if(m==0) return 0;
			else return LLONG_MIN;
		}

		if(i==n) return LLONG_MIN;
		
		int &res = dp[i][cnt][m];
		if(res!=-1) return res;

		res = func(i+1,cnt,m);
		int cur = (m + a[i]%d) % d;
		res = max(res, func(i+1, cnt+1, cur)+a[i]);
		return res;
	};
	
	int ans = func(0,0,0);
	if(ans>=0) cout << ans;
	else cout << -1;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}