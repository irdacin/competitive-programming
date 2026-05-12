#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
	os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
	for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
	for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, const char* sp = " ") { prin(A, sp); }

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

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

void solve() {
	vec<pii> rect(3);
	for(auto &[h, w] : rect) cin >> h >> w;

	vec<bool> used(3);
	vec<pii> cur;
	auto func = [&](auto func) {
		if(len(cur) == 3) {
			auto [h1, w1] = cur[0];	
			auto [h2, w2] = cur[1];	
			auto [h3, w3] = cur[2];
			
			if(h1 == h2 && h2 == h3) {
				if(w1 == w2 && w2 == w3) return true;
				return h1 == w1 + w2 + w3;
			}
			if(h1 == h2) return w1 + w2 == h3 && h1 + w3 == h3;
			if(h2 == h3) return w2 + w3 == h1 && h2 + w1 == h1;
			if(h1 == h3) return w1 + w3 == h2 && h3 + w2 == h2;
			
			return false;
		}

		bool res = false;
		for(int i = 0; i < 3; i++) {
			if(used[i]) continue; 
			used[i] = true;

			for(int c = 0; c < 2; c++) {
				cur.eb(rect[i]);
				res |= func(func);
				cur.pop_back();
				swap(rect[i].fi, rect[i].se);
			}

			used[i] = false;
		}

		return res;
	};

	print(func(func) ? "YES" : "NO");
}

signed main() {
	fastio;
	// #undef endl

	// precompute();
	// cout << fixed << setprecision(6);
	// int t; cin >> t; while(t--)
	solve();
}