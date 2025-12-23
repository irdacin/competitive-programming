#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int k, n; cin >> k >> n;
	int a[n];
	for(auto &i:a) cin >> i;
	
	vector<int> dist;
	for(int i=0;i<n-1;i++) dist.push_back(a[i+1]-a[i]);
	dist.push_back(k-a[n-1] + a[0]);
	sort(dist.begin(), dist.end());

	int ans = 0;
	for(auto d:dist) ans+=d;
	cout << ans-dist.back();
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}