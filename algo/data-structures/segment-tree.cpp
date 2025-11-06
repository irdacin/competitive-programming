template <class info>
struct SegmentTree {
  int n;
  vec<info> d;

  SegmentTree(int _n) : n(_n) {
    d.resize(n << 1);
  }

  SegmentTree(const vec<typename info::value_type>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = info(v[i]);
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, info t) { // [id]
    d[id += n] = t;
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int id, typename info::value_type t) { // [id]
    d[id += n].apply(t);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  info query(int id) { // [id]
    return d[id += n];
  }

  info query(int l, int r) { // [l, r)
    info resL, resR;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }
};

struct info {
  using value_type = int;
  int val;
  info() : val(0) {}
  info(value_type v) : val(v) {}

  void apply(value_type v) {
    val += v;
  }

  friend info merge(info left, info right) {
    info res;
    res.val = left.val + right.val;
    return res;
  }
};