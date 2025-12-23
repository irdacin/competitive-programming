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
	pair<int,int>p[n-1];
	for(auto &[s,t]:p) cin >> s >> t;

	for(int i=0;i<n-1;i++){
		auto [s,t] = p[i];

		// while(a[i]>=s) a[i]-=s, a[i+1]+=t; 
		int need = a[i]/s;
		a[i]-=need*s;
		a[i+1]+=need*t;
	}
	cout << a[n-1];
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}