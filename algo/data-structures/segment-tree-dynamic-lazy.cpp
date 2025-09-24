template <class node, class tag, bool PERSISTENT = false>
struct SegmentTree {
  struct vertex {
    int l, r;
    node d;
    tag lz;

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

      int m = (l + r) / 2;
      pool[v].l = build(build, l, m);
      pool[v].r = build(build, m, r);
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

  void apply(int v, const tag& t, int k = 1) {
    t.apply(pool[v].d, k);
    pool[v].lz.combine(t);
  }

  void push(int v, int k) {
    if(pool[v].lz.empty()) return;
    apply(pool[v].l = clone(pool[v].l), pool[v].lz, k / 2);
    apply(pool[v].r = clone(pool[v].r), pool[v].lz, (k + 1) / 2);
    pool[v].lz = tag();
  }

  void pull(int v) {
    pool[v].d = merge(
      pool[v].l != -1 ? pool[pool[v].l].d : node(),
      pool[v].r != -1 ? pool[pool[v].r].d : node()
    );
  }

  int update(int v, int l, int r, int pos, const tag& t) {
    v = clone(v);
    if(l + 1 == r) return apply(v, t), v;

    push(v, r - l);
    int m = (l + r) / 2;
    if(pos < m) pool[v].l = update(pool[v].l, l, m, pos, t);
    else pool[v].r = update(pool[v].r, m, r, pos, t);
    pull(v);
    return v;
  };

  int update(int v, int l, int r, int pl, int pr, const tag& t) {
    if(pl >= pr) return v;
    v = clone(v);
    if(l == pl && r == pr) return apply(v, t, r - l), v;
  
    push(v, r - l);
    int m = (l + r) / 2;
    pool[v].l = update(pool[v].l, l, m, pl, min(m, pr), t);
    pool[v].r = update(pool[v].r, m, r, max(pl, m), pr, t);
    pull(v);
    return v;
  }

  node query(int v, int l, int r, int pos) {
    if(v == -1) return node();
    if(l + 1 == r) return pool[v].d;

    push(v, r - l);
    int m = (l + r) / 2;
    if(pos < m) return query(pool[v].l, l, m, pos);
    else return query(pool[v].r, m, r, pos);
  }

  node query(int v, int l, int r, int pl, int pr) {
    if(v == -1 || pl >= pr) return node();
    if(l == pl && r == pr) return pool[v].d;

    push(v, r - l);
    int m = (l + r) / 2;
    return merge(query(pool[v].l, l, m, pl, min(m, pr)), query(pool[v].r, m, r, max(pl, m), pr));
  }

  int update(int root, int pos, tag t) { return update(root, l0, r0, pos, t); } // [pos]
  int update(int root, int l, int r, tag t) { return update(root, l0, r0, l, r, t); } // [l, r)
  node query(int root, int pos) { return query(root, l0, r0, pos); } // [pos]
  node query(int root, int l, int r) { return query(root, l0, r0, l, r); } // [l, r)
};

struct node {
  int val;
  node(int v = 0) : val(v) {}
  
  friend node merge(const node& left, const node& right) {
    node res;
    res.val = left.val + right.val;
    return res;
  }
};

struct tag {
  int val;

  tag() : val(0) {}
  tag(int v) : val(v) {}

  bool empty() const {
    return val == 0;
  }

  void apply(node& x, int k) const {
    x.val += k * val;
  }

  void combine(const tag& t) {
    val += t.val;
  }
};