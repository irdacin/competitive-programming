#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// int gcd(int a, int b){
// 	return (b==0 ? a: gcd(b, a%b));
// }

// int lcm(int a, int b){
// 	return a/ gcd(a,b) * b;
// }

int cases = 1;
void solve(){
	int x, y;
	cin >> x >> y;
	
	int fpb = gcd(x,y);
	int kpk = lcm(x,y);

	cout << "Case #" << cases++ << ": ";
	if(fpb==1) cout << -1;
	else{
		bool ada=false;
		for(int i=2;i*i<=fpb;i++)
			if(fpb%i==0){
				fpb/=i;
				ada=true;
				break;
			}
		
		ada ? cout << fpb : cout << 1;
	}

	cout << ' ' << kpk*2;
	cout << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve();
}