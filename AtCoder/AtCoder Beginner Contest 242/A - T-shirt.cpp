#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	double a, b, c, x;
	cin >> a >> b >> c >> x;

	if(a>=x) cout << 1.0;
	else if(b<x) cout << 0.0;
	else cout << c/(b-a);
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout << setprecision(7) << fixed;
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}