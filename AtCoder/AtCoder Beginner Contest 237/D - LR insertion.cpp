#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	deque<int> a = {n};
	for(int i=n-1, cur=0; i>=0; i--){
		if(s[i]=='L'){
			// cur--;
			// if(cur<0) cur=0;
			// a.insert(a.begin()+cur, i+1);
			a.push_back(i);
		}
		else{
			// cur++;
			// if(cur>n) cur=n;
			// a.insert(a.begin()+cur, i+1);
			a.push_front(i);
		}
		// for(auto &i:a) cout << i << ' ';
		// cout << endl;
	}

	for(auto &i:a) cout << i << ' ';
}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}