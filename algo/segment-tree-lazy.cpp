struct SegmentTree {
  struct node {
    int val;
    node(int v = 0) : val(v) {}

    friend node merge(node left, node right) {
      node res;
      res.val = left.val + right.val;
      return res;
    }
  };

  struct lazy {
    int val;
    lazy(int v = 0) : val(v) {}
  };

  int n, h;
  vec<node> tree;
  vec<lazy> lz;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    tree.resize(n << 1);
    lz.resize(n);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < len(v); i++) tree[i + n] = node(v[i]);
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, int k, int value) {
    tree[id].val += k * value;
    
    if(id < n) {
      lz[id].val += value;
    }
  }
  
  void push(int id, int k) {
    if(lz[id].val != 0) {
      apply(id << 1, k, lz[id].val);
      apply(id << 1 | 1, k, lz[id].val);
 
      lz[id].val = 0;
    }
  }

  void pull(int id) {
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
  }

  void update(int l, int r, int value) {
    // --l, --r;
    l += n, r += n + 1;

    for(int i = h, k = 1 << (h - 1); i; i--, k >>= 1) {
      if((l >> i) << i != l) push(l >> i, k);
      if((r >> i) << i != r) push((r - 1) >> i, k);
    }

    for(int le = l, ri = r, k = 1; le < ri; le >>= 1, ri >>= 1, k <<= 1) {
      if(le & 1) apply(le++, k, value);
      if(ri & 1) apply(--ri, k, value);
    }

    for(int i = 1; i <= h; i++) {
      if((l >> i) << i != l) pull(l >> i);
      if((r >> i) << i != r) pull((r - 1) >> i);
    }
  }

  int query(int id) {
    // --id;
    id += n;

    for(int i = h, k = 1 << (h - 1); i; i--, k >>= 1) push(id >> i, k);
    return tree[id].val;
  }

  int query(int l, int r) {
    // --l, --r;
    l += n, r += n + 1;

    for(int i = h, k = 1 << (h - 1); i; i--, k >>= 1) {
      if((l >> i) << i != l) push(l >> i, k);
      if((r >> i) << i != r) push((r - 1) >> i, k);
    }

    node resL, resR;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, tree[l++]);
      if(r & 1) resR = merge(tree[--r], resR);
    }

    return merge(resL, resR).val;
  }
};