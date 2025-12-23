#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define exit(x) return void(cout << x)

template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vec<T>>;
template <typename T> using vvvec = vector<vvec<T>>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e9;

struct DSU {
    vec<int> parent, sizes;

    DSU(int n) : parent(n), sizes(n, 1) {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u){
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;
        
        if(sizes[u] < sizes[v]) swap(u, v);

        parent[v] = u;
        sizes[u] += sizes[v]; 
        return true;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    
    DSU dsu(n);

    vvec<pair<int,int>> graph(m);
    for(auto &g:graph){
        int k, c; cin >> k >> c;
        for(int a; k--;) cin >> a, g.pb({c, --a});
    }

    sort(all(graph));
    int cnt = 0, weight = 0;
    for(auto g:graph){
        auto [k, u] = g[0];
        for(auto [k, v]:g){
            if(u == v) continue;
            bool status = dsu.unite(u, v);
            cnt += status; 
            weight += status * k;
        }
    }

    cout << (cnt != n-1 ? -1 : weight);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}