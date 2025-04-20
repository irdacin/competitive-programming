struct SegmentTree {
  #define m ((l + r) >> 1)
  #define lc (id << 1)
  #define rc (lc | 1)

  struct node {
    int val;
    node(int _val = 0) : val(_val) {}
  };

  int n;
  vec<int> v;
  vec<node> tree;
  
  SegmentTree(int _n) : n(_n) {
    int sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
  }
  
  SegmentTree(vec<int> _v) : n(len(_v)), v(_v) {
    int sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
    build(0, n - 1, 1);
  }

  node merge(node left, node right){
    return left + right;
  }

  void build(int l, int r, int id){
    if(l == r){
      tree[id] = node(v[l]);
      return;
    }
    
    build(l, m, lc);
    build(m + 1, r, rc);
    tree[id] = merge(tree[lc], tree[rc]);
  }
  
  void update(int l, int r, int id, int pos, int val){
    if(l == r){
      tree[id] = node(val);
      return;
    }

    if(pos <= m) update(l, m, lc, pos, val);
    else update(m + 1, r, rc, pos, val);
    tree[id] = merge(tree[lc], tree[rc]);
  }

  node query(int l, int r, int id, int pl, int pr){
    if(l > pr || r < pl) return node();
    if(pl <= l && r <= pr){
      return tree[id];
    }

    return merge(query(l, m, lc, pl, pr), query(m + 1, r, rc, pl, pr));
  }

  void update(int pos, int val){
    update(0, n - 1, 1, pos, val);
  }

  int query(int l, int r){
    return query(0, n - 1, 1, l, r);
  }

  #undef m
  #undef lc
  #undef rc
};