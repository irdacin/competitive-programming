template <class node, class tag>
struct SegmentTree {
  int n, h;
  vec<node> d;
  vec<tag> lz;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    d.resize(n << 1);
    lz.resize(n);
  }

  SegmentTree(const vec<node>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = v[i];
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, tag& t, int k = 1) {
    t.apply(d[id], k);
    if(id < n) lz[id].combine(t);
  }

  void push(int id, int k) {
    apply(id << 1, lz[id], k >> 1);
    apply(id << 1 | 1, lz[id], k >> 1);
    lz[id] = tag();
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, tag value) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    apply(id, value);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int l, int r, tag value) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    for(int le = l, ri = r, k = 1; le < ri; le >>= 1, ri >>= 1, k <<= 1) {
      if(le & 1) apply(le++, value, k);
      if(ri & 1) apply(--ri, value, k);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  node query(int id) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    return d[id];
  }

  node query(int l, int r) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    node resL, resR;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }
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
  
  void apply(node& t, int k) {
    t.val += k * val;
  }

  void combine(const tag& t) {
    val += t.val;
  }
};