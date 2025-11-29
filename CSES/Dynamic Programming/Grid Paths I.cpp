#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T = int> struct vec : vector<T> { using vector<T>::vector; };
template <typename T = int> struct vvec : vec<vec<T>> {
	vvec() {}
	vvec(initializer_list<initializer_list<T>> list) {
		for(const auto& row : list) this->push_back(row);
	}
	vvec(int n) : vec<vec<T>>(n) {}
	vvec(int n, int m) : vec<vec<T>>(n, vec<T>(m)) {}
	vvec(int n, int m, const T& init_value) : vec<vec<T>>(n, vec<T>(m, init_value)) {}
};
template <typename T = int> struct vvvec : vec<vvec<T>> {
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
	int n; cin >> n;
	vvec<char> grid(n, n);
	for(auto &row : grid) for(auto &c : row) cin >> c;
	if(grid[0][0] == '*') rcout(0);

	vec<pii> dir = {{1, 0}, {0, 1}};
	vvec<bool> vis(n, n, false);
	vis[0][0] = true;

	vvec<int> dp(n, n, -1);
	auto dfs = [&](auto dfs, int row, int col) {
		if(row == n - 1 && col == n - 1) return 1LL;

		int& res = dp[row][col];
		if(res != -1) return res;

		res = 0;
		for(auto [r, c] : dir) {
			r += row, c += col;
			if(r >= 0 && r < n && c >= 0 && c < n && !vis[r][c] && grid[r][c] != '*') {
				vis[r][c] = true;
				res += dfs(dfs, r, c);
				res %= MOD;
				vis[r][c] = false;
			}
		}
		return res;
	};
	
	cout << dfs(dfs, 0, 0);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}