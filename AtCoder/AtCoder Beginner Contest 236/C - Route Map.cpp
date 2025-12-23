#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	string s[n], t[m];
	for(auto &str:s) cin >> str;
	for(auto &str:t) cin >> str;

	for(int i=0, j=0;i<n;){
		if(s[i]==t[j]){
			cout << "Yes" << endl;
			i++, j++;
		} else {
			cout << "No" << endl;
			i++;
		}
	}
} 

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}