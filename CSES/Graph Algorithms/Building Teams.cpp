#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &x : _v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { int _n=_v.size(); for(int _i=0; _i<_n; _i++) os << _v[_i] << (_i==_n-1 ? '\n':' '); return os; }
template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& _p) { is >> _p.first >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
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

struct DSU {
    vec<int> parent, sizes;

    DSU(int n) : parent(n), sizes(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u){
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return false;

        if(sizes[u] < sizes[v]) swap(u, v);
        sizes[u] += sizes[v];
        parent[v] = u;
        return true;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    DSU dsu(n);
    vvec<int> adj(n);
    for(int a, b; m--;) cin >> a >> b, a--, b--, dsu.unite(a, b), adj[a].eb(b), adj[b].eb(a);

    map<int, vec<int>> mp;
    for(int i = 0; i < n; i++) mp[dsu.find(i)].eb(i);

    vec<int> ans(n, -1);
    for(auto [u, vc] : mp){
        queue<int> q;
        q.emplace(u);
        ans[u] = 1;

        while(!q.empty()){
            auto u = q.front(); q.pop();

            for(auto v : adj[u]){
                if(ans[u] == ans[v]) rcout("IMPOSSIBLE");
                else if(ans[v] == -1){
                    if(ans[u] == 1) ans[v] = 2;
                    else ans[v] = 1;
                    q.emplace(v);
                }
            }
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