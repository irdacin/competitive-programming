#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& _p) { is >> _p.first >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &_i : _v) is >> _i; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { for(auto &_i : _v) os << _i << " \n"[&_i == &_v.back()]; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const vector<pair<T, U>> _v) { for(auto _i : _v) os << _i << endl; return os; }
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
	vvec(initializer_list<initializer_list<T>> _list) { for(const auto& _row : _list) this->emplace_back(_row); }
	vvec(int _n = 0, int _m = 0, const T& _init_value = T()) : vec<vec<T>>(_n, vec<T>(_m, _init_value)) {}
	friend ostream& operator<<(ostream &os, const vvec _v) { for(auto _i : _v) os << _i; return os; }
};
template <typename T> struct vvvec : vec<vvec<T>> {
	vvvec(initializer_list<initializer_list<initializer_list<T>>> _list) { for(const auto& _rows : _list) for(const auto& _row : _rows) this->emplace_back(_row); }
	vvvec(int _n = 0, int _m = 0, int _k = 0, const T& _init_value = T()) : vec<vvec<T>>(_n, vvec<T>(_m, _k, _init_value)) {}
	friend ostream& operator<<(ostream &os, const vvvec _v) { for(auto _i : _v) os << _i << endl; return os; }
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

void solve(){
	int n, m, k, l; cin >> n >> m >> k >> l;
    
    // vvvec<vec<int>> dp(n + 1, m + 1, max(k, l) + 1, vec<int>(2, -1)); // 0 drum  1 trumpet
	// vector dp(n + 1, vector(m + 1, vector(max(k, l) + 1, vector<int>(2))));

	vvvec<int> dpDrum(n + 1, m + 1, k + 1), dpTrumpet(n + 1, m + 1, l + 1);	

	for(int i = 0; i <= k; i++) dpDrum[0][0][i] = 1;
	for(int i = 0; i <= l; i++) dpTrumpet[0][0][i] = 1;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int cnt = k; cnt >= 0; cnt--){
				if(i > 0 && cnt < k) (dpDrum[i][j][cnt] += dpDrum[i - 1][j][cnt + 1]) %= MOD;	
				if(j > 0) (dpDrum[i][j][cnt] += dpTrumpet[i][j - 1][1]) %= MOD;
			}

			for(int cnt = l; cnt >= 0; cnt--){
				if(j > 0 && cnt < l) (dpTrumpet[i][j][cnt] += dpTrumpet[i][j - 1][cnt + 1]) %= MOD;
				if(i > 0) (dpTrumpet[i][j][cnt] += dpDrum[i - 1][j][1]) %= MOD;
			}
		}
	}

	assert(dpDrum[n][m][0] == dpTrumpet[n][m][0]);
	
	cout << dpDrum[n][m][0];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; for(int tc = 1; tc <= t; tc++)
    cout << "Case #" << tc << ": ",
    solve(), cout << endl;
}

// vector issue
// ooo berarti vector ga boleh ampe 4 dimensi