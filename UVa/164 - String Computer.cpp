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

void solve(string s, string t){
    int n = len(s), m = len(t);

    /*
    auto func = [&](auto func, int i, int j){
        if(i == 0) return j;
        if(j == 0) return i;

        int res;

        // jika string sama, bisa langsung copy
        // jika tidak sama, cek copy (change), delete atau insert dan butuh 1 operasi disini

        res = func(func, i - 1, j - 1);
        if(s[i - 1] != t[j - 1])
            res = min({res, func(func, i - 1, j), func(func, i, j - 1)}) + 1;

        return res;
    };
    */
    // cout << func(func, n, m) << endl;

    vvec<int> dp(n + 1, m + 1, INF);
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j - 1];
            if(s[i - 1] != t[j - 1]){
                dp[i][j] = min({dp[i][j], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    // cout << dp[n][m] << endl;
    // cout << dp;

    auto twoDigit = [&](int i){
        string res = to_string(i);
        if(i < 10) res = "0" + res;
        return res;
    };

    for(int i = n, j = m; i > 0 || j > 0;){
        if(i == 0){
            cout << "I" << t[j - 1] << twoDigit(i + 1);
            j--;
        } 
        else if(j == 0){
            cout << "D" << s[i - 1] << twoDigit(i);
            i--;
        }
        else if(dp[i][j] == dp[i - 1][j - 1] + 1){
            cout << "C" << t[j - 1] << twoDigit(i);
            i--, j--;
        }
        else if(dp[i][j] == dp[i - 1][j] + 1){
            cout << "D" << s[i - 1] << twoDigit(i);
            i--;
        }
        else if(dp[i][j] == dp[i][j - 1] + 1){
            cout << "I" << t[j - 1] << twoDigit(i + 1);
            j--;
        } 
        else i--, j--;
    }

    cout << "E";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(string s, t; cin >> s >> t && s != "#";)
    solve(s, t), cout << endl;
    // solve();
}