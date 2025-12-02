#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
    vvec() {}
    vvec(initializer_list<initializer_list<T>> list) {
        for(const auto& row : list) this->push_back(row);
    }
    vvec(int _n) : vec<vec<T>>(_n) {}
    vvec(int _n, int _m) : vec<vec<T>>(_n, vec<T>(_m)) {}
    vvec(int _n, int _m, const T& init_value) : vec<vec<T>>(_n, vec<T>(_m, init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
    vvvec() {}
    vvvec(initializer_list<initializer_list<initializer_list<T>>> list) {
        for(const auto& rows : list) for(const auto& row : rows) this->push_back(row);
    }
    vvvec(int _n) : vec<vvec<T>>(_n) {}
    vvvec(int _n, int _m) : vec<vvec<T>>(_n, vvec<T>(_m)) {}
    vvvec(int _n, int _m, int _k) : vec<vvec<T>>(_n, vvec<T>(_m, _k)) {}
    vvvec(int _n, int _m, int _k, const T& init_value) : vec<vvec<T>>(_n, vvec<T>(_m, _k, init_value)) {}
};
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pii pair<int,int>
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 2e9;

void solve(){
    int n; cin >> n;
    vec<pii> v(n);
    for(auto &[a, b] : v) cin >> a;
    for(auto &[a, b] : v) cin >> b;
    int m; cin >> m;
    map<int, int> mp; int d;
    while(m--) cin >> d, mp[d]++;

    bool flag = false;
    for(auto [a, b] : v){
        if(a != b){
            if(mp[b] <= 0) rcout("NO");
            mp[b]--;
        }
        if(d == b) flag = true;
    }

    // for(auto [b, cnt] : mp) cout << b << ' ' << cnt << endl;
    
    cout << (flag ? "YES" : "NO");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}