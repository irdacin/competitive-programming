#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &x : _v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { int _n=_v.size(); for(int _i=0; _i<_n; _i++) os << _v[_i] << (_i==_n-1 ? '\n':' '); return os; }
template <typename T, typename U> istream& operator>>(istream& is, const pair<T, U> _p) { is >> _p.first >> ' ' >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const vector<pair<T, U>> _v) { for(auto _i : _v) os << _i << endl; return os; }
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
	vvec(initializer_list<initializer_list<T>> _list) { for(const auto& _row : _list) this->emplace_back(_row); }
	vvec(int _n = 0, int _m = 0, const T& _init_value = T()) : vec<vec<T>>(_n, vec<T>(_m, _init_value)) {}
	friend ostream& operator<<(ostream &os, const vvec _v) { for(auto _i : _v) os << _i << endl; return os; }
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
	vec<pii> num;

	bool possible = true;
	for(int a, i = 0; i <= 9; i++){
		cin >> a;
		if(i == 0 || i == 1 || i == 8 || i == 6 || i == 9)
			if(a > 0) num.eb(i, a);

		else if(a > 0) possible = false;
	}
	if(!possible || num.empty()) rcout(-1);

	sort(all(num), [](auto a, auto b){
		vec<int> arr = {0, 1, 8, 6, 9};
		int i = 0, j = 0;
		for(; arr[i] != a.fi; i++);
		for(; arr[j] != b.fi; j++);	
		return i > j;
	});
	// cout << num;

	/*
	1
	0 0 0 0 0 0 3 0 0 5

	999666 
	*/

	deque<int> awal, akhir;
	int mid = -1;
	for(int prev = 0; auto [i, cnt] : num){
		if(i == 9 || i == 6){
			if(i == 9){
				prev = cnt;
			}
			else{
				cnt = min(cnt, prev);
				while(cnt--) awal.push_back(9), akhir.push_front(6);
			}

			continue;
		}

		if(cnt & 1) mid = max(mid, i), cnt--;
		while(cnt--) if(cnt & 1) awal.push_back(i); else akhir.push_front(i);
	}

	if(awal.front() == 0) rcout(-1);

	for(auto i : awal) cout << i;
	if(mid != -1) cout << mid;
	for(auto i : akhir) cout << i;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve(), cout << endl;
}