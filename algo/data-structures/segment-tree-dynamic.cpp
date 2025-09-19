template <class node, bool PERSISTENT = false>
struct SegmentTree {
  struct vertex {
    int l, r;
    node d;

    vertex() : l(-1), r(-1) {}
  };

  int l0, r0;
  vec<vertex> pool;

  SegmentTree(int n = 10'000'000) {
    pool.reserve(n);
  }

  int new_root(int l, int r) {
    l0 = l, r0 = r;
    pool.eb();
    return len(pool) - 1;
  }

  int new_root(const vec<node>& a) {
    l0 = 0, r0 = len(a);
    auto build = [&](auto&& build, int l, int r) -> int {
      if(l == r) return -1;
      int v = new_vertex();
      if(l + 1 == r) return pool[v].d = a[l], v;

      int mid = (l + r) / 2;
      pool[v].l = build(build, l, mid);
      pool[v].r = build(build, mid, r);
      pull(v);
      return v;
    };
    return build(build, l0, r0);
  }

  int new_vertex(const vertex& v = vertex()) {
    pool.eb(v);
    return len(pool) - 1;
  }

  int clone(int v) {
    if(v == -1) return new_vertex();
    if(PERSISTENT) return new_vertex(pool[v]);
    return v;
  }

  void pull(int v) {
    pool[v].d = merge(
      pool[v].l != -1 ? pool[pool[v].l].d : node(),
      pool[v].r != -1 ? pool[pool[v].r].d : node()
    );
  }

  int update(int v, int l, int r, int pos, const node& t) {
    v = clone(v);
    if(l + 1 == r) return pool[v].d.apply(t), v;

    int mid = (l + r) / 2;
    if(pos < mid) pool[v].l = update(pool[v].l, l, mid, pos, t);
    else pool[v].r = update(pool[v].r, mid, r, pos, t);
    pull(v);
    return v;
  };
  
  node query(int v, int l, int r, int pos) {
    if(v == -1) return node();
    if(l + 1 == r) return pool[v].d;

    int mid = (l + r) / 2;
    if(pos < mid) return query(pool[v].l, l, mid, pos);
    else return query(pool[v].r, mid, r, pos);
  }
  
  node query(int v, int l, int r, int pl, int pr) {
    if(v == -1 || l >= pr || r <= pl) return node();
    if(pl <= l && r <= pr) return pool[v].d;

    int mid = (l + r) / 2;
    return merge(query(pool[v].l, l, mid, pl, pr), query(pool[v].r, mid, r, pl, pr));
  }

  int update(int root, int pos, node t) { return update(root, l0, r0, pos, t); } // [pos]
  node query(int root, int pos) { return query(root, l0, r0, pos); } // [pos]
  node query(int root, int l, int r) { return query(root, l0, r0, l, r); } // [l, r)
};

struct node {
  int val;
  node(int v = 0) : val(v) {}

  void apply(const node& t) {
    val += t.val;
  }

  friend node merge(const node& left, const node& right) {
    node res;
    res.val = left.val + right.val;
    return res;
  }
};