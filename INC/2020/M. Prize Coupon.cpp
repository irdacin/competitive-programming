#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
	int c[n];
	for(auto &i:c) cin >> i;

	bool got[n];
	memset(got,0,sizeof(got));

	int ans=0;
	for(int i=0;i<n;i++){
		// sebelumnya
		if(c[i]>0 && i>0 && !got[i-1]) 
		--c[i], got[i-1]=true, ans++;

		// dirinya
		if(c[i]>0 && !got[i]) 
		--c[i], got[i]=true, ans++;

		// setelahnya
		if(c[i]>0 && i<n-1 && !got[i+1])
		--c[i], got[i+1]=true, ans++;

	}

	cout << ans;
}

int main(){
	ez;
	// int t; cin >> t; while(t--)
	solve();
	return 0;
}