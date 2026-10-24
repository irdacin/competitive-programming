#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;

	int pos[26];
	memset(pos, -1, sizeof(pos));
	int ans=-1;
	for(int i=0;i<n;i++){
		if(pos[s[i]-'a'] != -1) ans =  max(ans, pos[s[i]-'a']+n-i);
		pos[s[i]-'a'] = i;
	}
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve();
}