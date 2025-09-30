struct Tree {
  vvec<int> adj;
  vec<int> tin, sz, par, depth, head;
  int timer;

  const bool VALUES_ON_EDGES = false;

  Tree(int n)
    : adj(n), tin(n), sz(n), par(n), depth(n), head(n)
  {}

  void add_edge(int u, int v) {
    adj[u].eb(v);
    adj[v].eb(u);
  }

  void build(int root = 0) {
    par[root] = -1;
    depth[root] = 0;
    timer = -1;
    head[root] = root;
    dfs_sz(root);
    dfs_hld(root);
  }

  void dfs_sz(int u) {
    sz[u] = 1;

    for(auto &v : adj[u]) {
      if(v == par[u]) continue;
      par[v] = u;
      depth[v] = depth[u] + 1;
      dfs_sz(v);

      sz[u] += sz[v];
      if(sz[v] > sz[adj[u][0]])
        swap(v, adj[u][0]);
    }
  }

  void dfs_hld(int u) {
    tin[u] = ++timer;

    for(auto v : adj[u]) {
      if(v == par[u]) continue;
      head[v] = v == adj[u][0] ? head[u] : v;
      dfs_hld(v);
    }
  }

  int lca(int u, int v) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
    }

    return depth[u] < depth[v] ? u : v;
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }

  template <class F>
  void process(int u, F&& op) {
    op(tin[u]);
  }

  template <class F>
  void process_subtree(int u, F&& op) {
    op(tin[u] + VALUES_ON_EDGES, tin[u] + sz[u]);
  }

  template <class F>
  auto process_path(int u, int v, F&& op) -> decltype(void(op(0, 0))) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
      op(tin[head[u]], tin[u] + 1);
    }

    if(depth[u] > depth[v]) swap(u, v);
    op(tin[u] + VALUES_ON_EDGES, tin[v] + 1);
  }

  template <class F>
  auto process_path(int u, int v, F&& op) -> decltype(void(op(0, 0, false))) {
    for(int l = lca(u, v), i = 2; i--; swap(u, v)) {
      for(; head[u] != head[l]; u = par[head[u]]) {
        op(tin[head[u]], tin[u] + 1, i);
      }
    }

    if(depth[u] > depth[v]) op(tin[v] + VALUES_ON_EDGES, tin[u] + 1, 1);
    else op(tin[u] + VALUES_ON_EDGES, tin[v] + 1, 0);
  }
};