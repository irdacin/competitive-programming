template <class info, bool PERSISTENT = false>
struct SegmentTree {
  struct vertex {
    int l, r;
    info d;

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

  int new_root(const vec<typename info::value_type>& a) {
    l0 = 0, r0 = len(a);
    auto build = [&](auto&& build, int l, int r) -> int {
      if(l == r) return -1;
      int v = new_vertex();
      if(l + 1 == r) return pool[v].d = info(a[l]), v;

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

  void pull(int v) {
    pool[v].d = merge(
      pool[v].l != -1 ? pool[pool[v].l].d : info(),
      pool[v].r != -1 ? pool[pool[v].r].d : info()
    );
  }

  int update(int v, int l, int r, int pos, const info& t) {
    v = clone(v);
    if(l + 1 == r) return pool[v].d = t, v;

    int m = (l + r) / 2;
    if(pos < m) pool[v].l = update(pool[v].l, l, m, pos, t);
    else pool[v].r = update(pool[v].r, m, r, pos, t);
    pull(v);
    return v;
  };

  int update(int v, int l, int r, int pos, const typename info::value_type& t) {
    v = clone(v);
    if(l + 1 == r) return pool[v].d.apply(t), v;

    int m = (l + r) / 2;
    if(pos < m) pool[v].l = update(pool[v].l, l, m, pos, t);
    else pool[v].r = update(pool[v].r, m, r, pos, t);
    pull(v);
    return v;
  };
  
  info query(int v, int l, int r, int pos) {
    if(v == -1) return info();
    if(l + 1 == r) return pool[v].d;

    int m = (l + r) / 2;
    if(pos < m) return query(pool[v].l, l, m, pos);
    else return query(pool[v].r, m, r, pos);
  }
  
  info query(int v, int l, int r, int pl, int pr) {
    if(v == -1 || pl >= pr) return info();
    if(l == pl && r == pr) return pool[v].d;

    int m = (l + r) / 2;
    return merge(query(pool[v].l, l, m, pl, min(m, pr)), query(pool[v].r, m, r, max(pl, m), pr));
  }

  int update(int root, int pos, info t) { return update(root, l0, r0, pos, t); } // [pos]
  int update(int root, int pos, typename info::value_type t) { return update(root, l0, r0, pos, t); } // [pos]
  info query(int root, int pos) { return query(root, l0, r0, pos); } // [pos]
  info query(int root, int l, int r) { return query(root, l0, r0, l, r); } // [l, r)
};

struct info {
  using value_type = int;
  int val;
  info() : val(0) {}
  info(int v) : val(v) {}

  void apply(value_type v) {
    val += v;
  }

  friend info merge(info left, info right) {
    info res;
    res.val = left.val + right.val;
    return res;
  }
};