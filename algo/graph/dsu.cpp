struct DSU {
  vec<int> parent, sizes;
  DSU(int n) : parent(n), sizes(n, 1) {
    iota(all(parent), 0);
  }

  int find(int u){
    return u == parent[u] ? u : parent[u] = find(parent[u]);
  }

  void unite(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    
    if(sizes[u] < sizes[v]) swap(u, v);
    sizes[u] += sizes[v];
    parent[v] = u;
  }
};