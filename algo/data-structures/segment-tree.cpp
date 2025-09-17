template <class node>
struct SegmentTree {
  int n;
  vec<node> d;

  SegmentTree(int _n) : n(_n) {
    d.resize(n << 1);
  }

  SegmentTree(const vec<node>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = v[i];
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, node t) { // [id]
    d[id += n].apply(t);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  node query(int id) { // [id]
    return d[id += n];
  }

  node query(int l, int r) { // [l, r)
    node resL, resR;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }
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