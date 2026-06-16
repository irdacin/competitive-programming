// Source: https://usaco.guide/general/io

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
  int t; cin >> t;

  for(bool first = true; t--; first = false) {
    if(!first) cout << '\n';
    
    char n; cin >> n; n -= 'A'; n++;
    cin.ignore();
    
    DSU dsu(n);
    for(char u, v; cin.get(u) && u != '\n'; cin.ignore()) {
      cin >> v;
      u -= 'A', v -= 'A';
      dsu.unite(u, v);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans += i == dsu.find(i);
    cout << ans << '\n';
  }
}