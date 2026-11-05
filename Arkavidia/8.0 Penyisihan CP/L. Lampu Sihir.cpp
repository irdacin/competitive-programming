#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	int w[n];
	for(auto &i:w) cin >> i;

	int ans = LLONG_MAX;
	for(auto i:w){
		int x = k;

		int sihir = 0;
		while(x > i){
			x/=2;
			sihir++;
		}

		int need = i-x;
		sihir+=need;
		// cout << sihir << endl;

		ans = min(ans, sihir);
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