#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	pair<char,char>str[n]; 
	for(auto &[s,t]:str) cin >> s;
	for(auto &[s,t]:str) cin >> t;
	for(auto &[s,t]:str) cout << s << t;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}