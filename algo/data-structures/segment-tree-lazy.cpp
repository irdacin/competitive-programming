template <class info, class tag>
struct SegmentTree {
  int n, h;
  vec<info> d;
  vec<tag> lz;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    d.resize(n << 1);
    lz.resize(n);
  }

  SegmentTree(const vec<typename info::value_type>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = info(v[i]);
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, tag t, int k = 1) {
    t.apply(d[id], k);
    if(id < n) lz[id].combine(t);
  }

  void push(int id, int k) {
    if(lz[id].empty()) return;
    apply(id << 1, lz[id], k >> 1);
    apply(id << 1 | 1, lz[id], k >> 1);
    lz[id] = tag();
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, info t) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    d[id] = t;
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int id, tag t) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    apply(id, t);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int l, int r, tag t) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    for(int le = l, ri = r, k = 1; le < ri; le >>= 1, ri >>= 1, k <<= 1) {
      if(le & 1) apply(le++, t, k);
      if(ri & 1) apply(--ri, t, k);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  info query(int id) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    return d[id];
  }

  info query(int l, int r) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    info resL, resR;
    for(; l < r; l >>= 1, r >>= 1) {
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

  friend info merge(info left, info right) {
    info res;
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

  void apply(info& x, int k) const {
    x.val += k * val;
  }

  void combine(tag t) {
    val += t.val;
  }
};