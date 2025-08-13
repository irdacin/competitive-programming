#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, sizes;
  DSU(int n) : parent(n), sizes(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int u) {
    return u == parent[u] ? u : parent[u] = find(parent[u]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    
    if(sizes[u] < sizes[v]) swap(u, v);
    sizes[u] += sizes[v];
    parent[v] = u;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for(auto &[w, u, v] : edges) cin >> u >> v >> w, u--, v--;
  sort(edges.begin(), edges.end());

  DSU dsu(n);
  long long ans = 0;

  for(auto [w, u, v] : edges) {
    if(dsu.unite(u, v)) ans += w;
  }

  cout << ans << '\n';

  return 0;
}