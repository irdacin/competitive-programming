#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
	int n; cin>> n;
	int skill_one=INT_MAX, skill_two=INT_MAX, skill_double=INT_MAX;
	ll ans=INT_MAX;
	while(n--){
		int m; string s; 
		cin >> m >> s;
		if(s=="10") skill_one=min(skill_one, m);
		else if(s=="01") skill_two=min(skill_two, m);
		else if(s=="11") skill_double=min(skill_double, m);
		ans = min(ans, min((ll)skill_one+skill_two, (ll) skill_double));
	}
	(ans>=INT_MAX) ? cout << -1 : cout << ans;
	cout << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}