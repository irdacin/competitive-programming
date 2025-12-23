#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int five=0, seven=0;
	for(int i=0;i<3;i++){
		int a; cin >> a;
		if(a==5) five++;
		else if(a==7) seven++;
	}
	cout << (five==2 && seven==1 ? "YES":"NO");
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}