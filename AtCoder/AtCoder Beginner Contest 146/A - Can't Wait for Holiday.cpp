#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;
    string week[7] = {"SAT","FRI","THU","WED","TUE","MON","SUN"};
    for(int i=0;i<7;i++) if(week[i]==s) exit(i+1);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}