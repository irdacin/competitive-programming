#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	int a[n];
	for(auto &i:a) cin >> i;

	double ans = 0;
	bool first = false;
	for(int count=0; count<=50;count++){
		for(int i=n-1; i>=0; i--){
			if(!first) first = true, ans+=a[i];
			else  ans = 1/ans, ans+=a[i];
		}
	}
	cout << setprecision(6) << fixed;
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve(), cout << endl;
}