struct SegmentTree {
  struct node {
    int val;
    node(int v = 0) : val(v) {}

    friend node merge(const node& left, const node& right) {
      node res;
      res.val = left.val + right.val;
      return res;
    }
  };

  int n;
  vec<node> tree;

  SegmentTree(int _n) : n(_n) {
    tree.resize(n << 1);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) tree[i + n] = node(v[i]);
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
  }

  void update(int id, int value) {
    // --id;
    id += n;

    tree[id].val = value;
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  int query(int id) {
    // --id;
    id += n;

    return tree[id].val;
  }

  int query(int l, int r) {
    // --l, --r;
    
    node resL, resR;
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, tree[l++]);
      if(r & 1) resR = merge(tree[--r], resR);
    }

    return merge(resL, resR).val;
  }
};