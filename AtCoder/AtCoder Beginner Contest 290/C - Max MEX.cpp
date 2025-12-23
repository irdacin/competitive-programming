#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, k, a; cin >> n >> k;
	set<int> st;
	while(n--) cin >> a, st.insert(a);
	
	for(int i=0;i<k;i++) if(st.find(i)==st.end()) exit(i);
	cout << k;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}