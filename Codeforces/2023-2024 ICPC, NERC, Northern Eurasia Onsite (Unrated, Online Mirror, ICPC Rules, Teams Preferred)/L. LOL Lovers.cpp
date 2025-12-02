#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n; cin>> n;
	string s; cin>> s;
	int k = -1;
	for(int i=1;i<n;i++){
		int lLeft=0, oLeft=0;
		for(int a=0;a<i;a++){
			if(s[a]=='L') lLeft++;
			else oLeft++;
		}

		int lRight=0, oRight=0;
		for(int a=i;a<n;a++){
			if(s[a]=='L') lRight++;
			else oRight++;
		}

		if(lLeft == lRight || oLeft==oRight) continue;
		// cout << lLeft << ' ' << lRight << endl;
		// cout << oLeft << ' ' << oRight << endl;
		k = i;
	}
	cout << k << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve();
}