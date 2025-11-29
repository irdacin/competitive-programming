#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	int a[n-1];
	for(auto &i:a) cin >> i;
	sort(a,a+n-1);
	for(int i=0;i<n-1;i++) if(i+1!=a[i]) exit(i+1);
	cout << n;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}