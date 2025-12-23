#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	string s; cin >> s;
	
	int n = len(s);

	auto palindrom = [](string s){
		int n = len(s);
		for(int i=0;i*2<n;i++) if(s[i]!=s[n-i-1]) return false;
		return true;
	};

	if(palindrom(s)) exit("Yes");

	int i=0, j=n-1;
	for(;i<n && s[i]=='a'; i++);
	for(;j>=0 && s[j]=='a'; j--);

	if(i > n-j-1) exit("No");
	for(;i<j;i++,j--) if(s[i]!=s[j]) exit("No");

	cout << "Yes";
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}