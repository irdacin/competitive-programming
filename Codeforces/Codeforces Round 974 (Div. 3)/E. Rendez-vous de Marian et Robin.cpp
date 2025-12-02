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
const int INF = 2e18;

void solve(){
    int n, m, h; cin >> n >> m >> h;
    vec<bool> horse(n);
    for(int a; h--;) cin >> a, a--, horse[a] = true;
    vvec<pii> adj(n);
    for(int u, v, w; m--;) cin >> u >> v >> w, u--, v--, adj[u].eb(v, w), adj[v].eb(u, w);

    auto dijkstra = [&](int start){
        priority_queue<iii, vec<iii>, greater<>> pq; // {distance, vertex, useHorse}
        vvec<int> dis(n, 2, INF); // 0 -> ga pake kuda  1 -> pake kuda

        dis[start][0] = 0;
        pq.emplace(0, start, 0);

        while(!pq.empty()){
            auto [dis_u, u, used] = pq.top(); pq.pop();

            if(dis_u > dis[u][used]) continue;

            bool useHorse = used || horse[u];

            for(auto [v, w] : adj[u]){
                if(useHorse) w /= 2;

                if(dis[v][useHorse] > dis[u][used] + w){
                    dis[v][useHorse] = dis[u][used] + w;
                    pq.emplace(dis[v][useHorse], v, useHorse);
                }
            }
        }

        return dis;
    };

    vvec<int> marian = dijkstra(0);
    vvec<int> robin = dijkstra(n - 1);

    // cout << marian << endl;
    // cout << robin << endl;

    int ans = INF;
    for(int i = 0; i < n; i++){
        int distMarian = min(marian[i][0], marian[i][1]);
        int distRobin = min(robin[i][0], robin[i][1]);

        ans = min(ans, max(distMarian, distRobin));
    }

    cout << (ans == INF ? -1 : ans);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
    // solve();
}