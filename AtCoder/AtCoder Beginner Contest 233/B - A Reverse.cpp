#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int l, r; string s;
	cin >> l >> r >> s;

	for(int i=0;i<len(s);i++){
		if(i==l-1){
			for(int j=r-1;j>=l-1;j--) cout << s[j];
			i=r-1;
		} else cout << s[i];
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}