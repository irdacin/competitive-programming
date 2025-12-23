#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> cnt(n, 0);
	n*=4;
	while(n --> 1){
		int a; cin >> a;
		cnt[a-1]++;
	}
	
	int ans=1;
	for(auto i:cnt) if(i==3) exit(ans); else ans++;
} 

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}