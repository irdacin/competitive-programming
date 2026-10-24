#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;
const ll MOD = 1e9+7;

ll power(int k){
	if(k==0) return 1;
	ll res = power(k/2);
	return k%2 ? (2*res*res) % MOD : (res*res) %MOD;
}

ll hasil = 0;
void solve(){
	int n; char op;
	cin >> op >> n;
	op=='+' ? hasil+= power(n) : hasil-= power(n);
	hasil%=MOD;
	cout << (hasil==0 ? "YES" : "NO") << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}