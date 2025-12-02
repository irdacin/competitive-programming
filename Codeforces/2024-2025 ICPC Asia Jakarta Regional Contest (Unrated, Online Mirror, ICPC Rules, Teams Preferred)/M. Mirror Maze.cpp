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
    int r, c; cin >> r >> c;
    vvec<char> grid(r, c); cin >> grid;

    int mirror = 0;
    for(auto s : grid) for(auto c : s) mirror += c == '/' || c == '\\';

    vec<string> ans;

    vec<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vec<string> arah = {"N", "W", "S", "E"};
    const int BAWAH = 0;
    const int KANAN = 1;
    const int ATAS = 2;
    const int KIRI = 3;

    for(int i = 0; i < 4; i++){
        for(int id = 0; id < (i == BAWAH || i == ATAS ? c : r); id++){
            int row = i == BAWAH ? 0 : i == ATAS ? r - 1 : id;
            int col = i == KANAN ? 0 : i == KIRI ? c - 1 : id;

            int cnt = 0;
            
            for(int cur = i; row >= 0 && row < r && col >= 0 && col < c;){
                if(grid[row][col] == '/'){
                    if(cur == BAWAH) cur = KIRI;
                    else if(cur == ATAS) cur = KANAN;
                    else if(cur == KANAN) cur = ATAS;
                    else cur = BAWAH;
                    cnt++;
                } else if(grid[row][col] == '\\'){
                    if(cur == BAWAH) cur = KANAN;
                    else if(cur == ATAS) cur = KIRI;
                    else if(cur == KANAN) cur = BAWAH;
                    else cur = ATAS;
                    cnt++;
                }

                auto [x, y] = dir[cur];
                row += x, col += y;
            }

            if(cnt >= mirror) ans.eb(arah[i] + to_string(id + 1));
        }
    }

    cout << len(ans) << endl << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    // solve(), cout << endl;
    solve();
}