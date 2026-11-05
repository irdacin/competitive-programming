#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int l, r; 
	cin >> l >> r;

	// int ans=l;
	// // tle pasti hehe
	// for(int i=l+1;i<=r;i++) ans^=i;

	
	// int ans=0;
	// for(int i=1;i<=20;i++) ans^=i,
	// cout << ans << ' ';
	// 1 3 0 4 1 7 0 8 1 11 0 12 1 15 0 16 1 19 0 20
	// ada urutannya teryata
	/*
	1 3 0 4 
	1 7 0 8 
	1 11 0 12 
	1 15 0 16 
	1 19 0 20
	*/

	auto XOR = [](int n){
		if(n%4==1) return (int) 1;
		else if(n%4==2) return n+1;
		else if(n%4==3) return (int) 0;
		else return n;
	};

	int ans = XOR(l-1)^XOR(r); 
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve();
}