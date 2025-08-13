struct Tree {
  vvec<int> adj;
  int h;
  vvec<int> up;
  vec<int> tin, tout;
  vec<int> depth;
  int timer;

  Tree(int n) : adj(n), tin(n), tout(n), depth(n) {
    for(h = 0; 1 << h <= n; h++);
    up.resize(n, vec<int>(h, -1));
  }

  void add_edge(int u, int v) {
    adj[u].eb(v);
    adj[v].eb(u);
  }

  void build() {
    timer = 0;
    depth[0] = 0;
    dfs(0);
  }

  void dfs(int u, int p = -1) {
    tin[u] = ++timer;

    up[u][0] = p;
    for(int i = 1; i < h && up[u][i - 1] != -1; i++) {
      up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for(auto v : adj[u]) {
      if(v == p) continue;

      depth[v] = depth[u] + 1;
      dfs(v, u);
    }

    tout[u] = ++timer;
  }

  int kth_ancestor(int u, int k) {
    for(int i = 0; k > 0 && u != -1; i++, k >>= 1) {
      if(k & 1) u = up[u][i];
    }

    return u == -1 ? -1 : u + 1;
  }

  bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  }

  int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = h - 1; i >= 0; i--) {
      if(up[u][i] != -1 && !is_ancestor(up[u][i], v))
        u = up[u][i];
    }

    return up[u][0];
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
};