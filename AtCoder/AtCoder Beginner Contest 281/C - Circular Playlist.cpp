#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, t; cin >> n >> t;
	int a[n];
	for(auto &i:a) cin >> i;

	int sum = 0;
	for(auto &i:a) sum+=i;
	sum = t%sum;
	
	int song=1;
	for(auto i:a){
		if(sum-i>0) sum-=i, song++;
		else break;
	}
	cout << song << ' ' << sum;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}