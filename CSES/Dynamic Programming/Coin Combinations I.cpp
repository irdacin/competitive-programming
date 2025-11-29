#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)
 
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
	vvec() {}
	vvec(initializer_list<initializer_list<T>> list) {
		for(const auto& row : list) this->push_back(row);
	}
	vvec(int n) : vec<vec<T>>(n) {}
	vvec(int n, int m) : vec<vec<T>>(n, vec<T>(m)) {}
	vvec(int n, int m, const T& init_value) : vec<vec<T>>(n, vec<T>(m, init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
	vvvec() {}
	vvvec(initializer_list<initializer_list<initializer_list<T>>> list) {
		for(const auto& rows : list) for(const auto& row : rows) this->push_back(row);
	}
	vvvec(int n) : vec<vvec<T>>(n) {}
	vvvec(int n, int m) : vec<vvec<T>>(n, vvec<T>(m)) {}
	vvvec(int n, int m, int k) : vec<vvec<T>>(n, vvec<T>(m, k)) {}
	vvvec(int n, int m, int k, const T& init_value) : vec<vvec<T>>(n, vvec<T>(m, k, init_value)) {}
};
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
 
const int MOD = 1e9 + 7;
const int INF = 2e9;

void solve(){
    int n, x; cin >> n >> x;
	vec<int> c(n);
	for(auto &i : c) cin >> i;

	vec<int> dp(x+1, 0);
	dp[0] = 1;

	for(int sum = 0; sum <= x; sum++){
		for(auto i : c){
			if(sum >= i) dp[sum] += dp[sum - i], dp[sum] %= MOD;
		}
	}

	cout << dp[x];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}