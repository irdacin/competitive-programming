#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
	const string word="codeforces";
	string s; cin>>s;
	int ans=0;
	for(int i=0;i<10;i++) ans+=s[i]!=word[i];
	cout << ans << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}