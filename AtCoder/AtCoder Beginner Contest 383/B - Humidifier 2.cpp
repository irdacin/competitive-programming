#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    int h, w, d; cin >> h >> w >> d;
    vvec<char> grid(h, w); cin >> grid;

    vec<pii> cells;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '.') cells.eb(i, j);
        }
    }

    int ans = 0;

    for(auto &i : cells){
        for(auto &j : cells){
            if(&i == &j) continue;

            auto [row1, col1] = i;
            auto [row2, col2] = j;

            set<pii> humidified;
            for(int x = max(0LL, row1 - d); x <= min(h - 1, row1 + d); x++){
                for(int y = max(0LL, col1 - d); y <= min(w - 1, col1 + d); y++){
                    if(abs(row1 - x) + abs(col1 - y) > d) continue;
                    if(grid[x][y] != '.') continue;

                    humidified.emplace(x, y);
                }
            }

            for(int x = max(0LL, row2 - d); x <= min(h - 1, row2 + d); x++){
                for(int y = max(0LL, col2 - d); y <= min(w - 1, col2 + d); y++){
                    if(abs(row2 - x) + abs(col2 - y) > d) continue;
                    if(grid[x][y] != '.') continue;

                    humidified.emplace(x, y);
                }
            }

            ans = max(ans, len(humidified));
        }
    }

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
    // solve();
}