#include <bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cout << #x << " => " << x << endl
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

void print() { cout << endl; }
template <typename T, typename... U> inline void print(T &&A, U &&...B) {
    cout << A; if (sizeof...(U)) cout << ' '; print(B...);
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) {
    os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
    for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) {
    for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
    using vec<vec<T>>::vec;
    vvec(int N = 0, int M = 0, const T& _init_value = T())
        : vec<vec<T>>(N, vec<T>(M, _init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
    using vec<vvec<T>>::vec;
    vvvec(int N = 0, int M = 0, int K = 0, const T& _init_value = T())
        : vec<vvec<T>>(N, vvec<T>(M, K, _init_value)) {}
};

#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 2e9;
const int MAXN = 2e5;

void solve(){
	int h, w; cin >> h >> w;
	vvec<char> grid(h, w); cin >> grid;

	vec<pii> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

	int ans = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(grid[i][j] == '#'){
				queue<pii> q;
				q.emplace(i, j);

				while(!q.empty()){
					auto [row, col] = q.front(); q.pop();
					for(auto [x, y] : dir){
						x += row, y += col;
						if(x >= 0 && x < h && y >= 0 && y < w && grid[x][y] == '#'){
							grid[x][y] = '.';
							q.emplace(x, y);
						}
					}
				}

				ans++;
			}
		}
	}

	print(ans);
}

signed main(){
	#ifndef fastio
	#define fastio
	#endif

	fastio;
	// precompute();

	// int t; cin >> t; while(t--)
	solve();
}