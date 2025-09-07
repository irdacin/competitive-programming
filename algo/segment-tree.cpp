struct SegmentTree {
  struct node {
    int val;
    node(int v = 0) : val(v) {}

    friend node merge(const node& left, const node& right) {
      node res;
      res.val = left.val + right.val;
      return res;
    }

    friend ostream& operator<<(ostream &os, const node& n) {
      return os << "(" << n.val << ")";
    }
  };

  struct tag {
    int val;

    tag() {}
    tag(int v) : val(v) {}

    void apply(node& t) {
      t.val += val;
    }
  };

  int n;
  vec<node> d;

  SegmentTree(int _n) : n(_n) {
    d.resize(n << 1);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = node(v[i]);
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void _update(int id, tag t) {
    t.apply(d[id += n]);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  node _query(int id) {
    return d[id += n];
  }

  node _query(int l, int r) { // [l, r)
    node resL, resR;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }

  void update(int id, int val) { _update(id, tag(val)); }
  int query(int l, int r) { return _query(l, r).val; }
};