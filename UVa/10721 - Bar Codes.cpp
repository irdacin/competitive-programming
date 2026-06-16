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

void solve(int n, int k, int m){
    /*
    vvvec<int> dp(n + 1, k + 1, m + 1, -1);    
    function<int(int, int, int)> func = [&](int n, int k, int bar){
        if(n == 0 && k == 0) return 1LL;
        if(n == 0 || k == 0) return 0LL;

        int &res = dp[n][k][bar];
        if(res != -1) return res;

        res = 0;
        
        // jika barnya masih bisa diisi, bisa diisi dgn 2 cara
        // - pake unit yang sama dari sebelumnya
        // - pake unit yang beda dari sebelumnya

        // tapi kalo uda ga bisa diisi berarti harus ambil unit yang beda dari sebelumnya

        if(bar < m) res += func(n - 1, k, bar + 1);
        res += func(n - 1, k - 1, 1);

        return res;
    };

    cout << func(n, k, 1);
    
    */

    vvvec<int> dp(n + 1, k + 1, m + 1, 0);
    for(int i = 0; i <= m; i++) dp[0][0][i] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int bar = m; bar >= 1; bar--){
                dp[i][j][bar] += dp[i - 1][j - 1][1];
                if(bar < m) dp[i][j][bar] += dp[i - 1][j][bar + 1];
            }
        }
    }

    cout << dp[n][k][1];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(int n, k, m; cin >> n >> k >> m;)
    solve(n, k, m), cout << endl;
}