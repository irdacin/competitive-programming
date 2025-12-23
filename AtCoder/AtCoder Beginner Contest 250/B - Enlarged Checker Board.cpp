#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, a, b;
	cin >> n >> a >> b;

	bool dot = true;
	for(int i=0;i<n;i++){
		for(int j=0;j<a;j++){
			for(int k=0;k<n;k++){
				for(int l=0;l<b;l++){
					cout << (dot ? '.':'#');
				}
				dot^=1;
			}
			cout << endl;
			if(n&1) dot^=1;
		}
		dot^=1;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}