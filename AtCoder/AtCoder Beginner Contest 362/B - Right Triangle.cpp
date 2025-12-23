#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &x : _v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { int _n=_v.size(); for(int _i=0; _i<_n; _i++) os << _v[_i] << (_i==_n-1 ? "":" "); return os; }
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
    int xa, ya, xb, yb, xc, yc; 
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto sisi = [](int x1, int y1, int x2, int y2){
        return abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1);
    };

    int a = sisi(xa, ya, xb, yb);
    int b = sisi(xa, ya, xc, yc);
    int c = sisi(xb, yb, xc, yc);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    // cout << a << b << c; 
    cout << (a + b  == c  ? "Yes" : "No");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}