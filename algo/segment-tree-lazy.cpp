struct SegmentTree {
  #define m ((l + r) >> 1)
  #define lc (id << 1)
  #define rc (lc | 1)

  struct node {
    int val;
    node(int _val = 0) : val(_val) {}
    // node &operator+=(int other){ return val += other, *this; }
  };

  int n;
  vec<int> v;
  vec<node> tree;
  vec<int> lazy;
  
  SegmentTree(int _n) : n(_n) {
    int sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
    lazy.resize(sz << 1);
  }
  
  SegmentTree(vec<int> _v) : n(len(_v)), v(_v) {
    int sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
    lazy.resize(sz << 1);
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

  void propagate(int l, int r, int id){
    if(lazy[id]){
      // tree[id] += (r - l + 1) * lazy[id];
      if(l < r){
        lazy[lc] += lazy[id];
        lazy[rc] += lazy[id];
      }

      lazy[id] = 0;
    }
  }

  void update(int l, int r, int id, int pl, int pr, int val){
    propagate(l, r, id);

    if(l > pr || r < pl) return;
    if(pl <= l && r <= pr){
      lazy[id] = val;
      propagate(l, r, id);
      return;
    }

    update(l, m, lc, pl, pr, val);
    update(m + 1, r, rc, pl, pr, val);
    tree[id] = merge(tree[lc], tree[rc]);
  }

  node query(int l, int r, int id, int pos){
    propagate(l, r, id);

    if(l == r){
      return tree[id];
    }

    if(pos <= m) return query(l, m, lc, pos);
    else return query(m + 1, r, rc, pos);
  }

  node query(int l, int r, int id, int pl, int pr){
    propagate(l, r, id);

    if(l > pr || r < pl) return node();
    if(pl <= l && r <= pr){
      return tree[id];
    }

    return merge(query(l, m, lc, pl, pr), query(m + 1, r, rc, pl, pr));
  }

  void update(int l, int r, int val){
    update(0, n - 1, 1, l, r, val);
  }

  int query(int pos){
    return query(0, n - 1, 1, pos);
  }

  int query(int l, int r){
    return query(0, n - 1, 1, l, r);
  }

  #undef m
  #undef lc
  #undef rc
};