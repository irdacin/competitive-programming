#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &x : _v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { int _n=_v.size(); for(int _i=0; _i<_n; _i++) os << _v[_i] << (_i==_n-1 ? "":" "); return os; }
template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& _p) { is >> _p.first >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const vector<pair<T, U>> _v) { for(auto _i : _v) os << _i << endl; return os; }
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
	vvec(initializer_list<initializer_list<T>> _list) { for(const auto& _row : _list) this->push_back(_row); }
	vvec(int _n = 0, int _m = 0, const T& _init_value = T()) : vec<vec<T>>(_n, vec<T>(_m, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvec _v) { for(auto _i : _v) os << _i << endl; return os; }
};
template <typename T> struct vvvec : vec<vvec<T>> {
	vvvec(initializer_list<initializer_list<initializer_list<T>>> _list) { for(const auto& _rows : _list) for(const auto& _row : _rows) this->push_back(_row); }
	vvvec(int _n = 0, int _m = 0, int _k = 0, const T& _init_value = T()) : vec<vvec<T>>(_n, vvec<T>(_m, _k, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvvec _v) { for(auto _i : _v) os << _i << endl; return os; }
};
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 2e9;

void solve(){
	int r, c; cin >> r >> c;
	vvec<char> grid(r, c); cin >> grid;

	vec<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	vvec<bool> vis(r, c, false);
	vvec<int> zone(r, c, 0);

	for(int i = 0, cnt = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(vis[i][j]) continue;
			
			vis[i][j] = true;

			queue<pii> q;
			q.push({i, j});
			char cur = grid[i][j];
			zone[i][j] = ++cnt;

			while(!q.empty()){
				auto [row, col] = q.front(); q.pop();

				for(auto [x, y] : dir){
					x += row, y += col;
					if(x >= 0 && x < r && y >=0 && y < c && !vis[x][y] && grid[x][y] == cur){
						vis[x][y] = true;
						zone[x][y] = cnt;
						q.push({x, y});
					}
				}
			}

		}
	}
	// cout << zone << endl;

	int n; cin >> n;
	while(n--){
		int r1, c1, r2, c2; 
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, c1--, r2--, c2--;

		if(zone[r1][c1] == zone[r2][c2]){
			if(grid[r1][c1] == '0') cout << "binary";
			else cout << "decimal";
		} else cout << "neither";
		cout << endl;
	}
	
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}