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
    int n, k; cin >> n >> k;
    vec<int> a(n); cin >> a;

    vec<array<int, 30>> pref(n + 1);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1];
        for(int bit = 0; bit < 30; bit++){
            if(a[i - 1] & (1 << bit)){
                pref[i][bit]++;
            }
        }
    }

    auto calc = [&](int l, int r){
        int res = 0;
        for(int bit = 0; bit < 30; bit++){
            if(pref[r][bit] - pref[l - 1][bit] == r - l + 1){
                res |= (1 << bit);
            }
        }

        return res;
    };

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        // cout << "i ==> " << i << endl;

        int start = i;
        for(int left = i, right = n; left <= right;){
            int mid = (left + right) / 2;

            if(calc(i, mid) > k) start = mid, left = mid + 1;
            else right = mid - 1;
        }

        cout << "start = " << start << endl;

        int end = i - 1;
        for(int left = start, right = n; left <= right;){
            int mid = (left + right) / 2;

            if(calc(i, mid) >= k) end = mid, left = mid + 1;
            else right = mid - 1;
        }

        cout << "end = " << end << endl << endl;

        ans += max(0, end - start + 1);
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