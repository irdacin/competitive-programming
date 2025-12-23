#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	string s; cin >> s;
	if(len(s)!=8) exit("No");

	auto upper = [](char a){
		return a>='A' && a<='Z';
	};

	if(!upper(s[0])) exit("No");
	if(!upper(s[7])) exit("No");
	if(s[1]=='0') exit("No");
	
	for(int i=1;i<7;i++) if(s[i]<'0' || s[i]>'9') exit("No");
	cout << "Yes";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}