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

  struct tag {
    int val;
    
    tag() : val(0) {}
    tag(int v) : val(v) {}

    bool empty() const { 
      return val == 0;
    }

    void apply(node &t, int k) const {
      t.val += k * val;
    }

    void combine(const tag& t) {
      val += t.val;
    }
  };
  
  struct vertex {
    int l, r;
    node d;
    tag lz;

    vertex() : l(-1), r(-1) {}
  };

  vec<vertex> pool;
  int root;

  SegmentTree() {
    pool.reserve(6'000'001);
    root = new_vertex();
  }

  int new_vertex() {
    pool.eb();
    return len(pool) - 1;
  }

  void apply(int v, const tag& t, int k = 1) {
    t.apply(pool[v].d, k);
    pool[v].lz.combine(t);
  }

  void push(int v, int l, int r) {
    if(pool[v].lz.empty()) return;
    int mid = (l + r) / 2;
    if(pool[v].l != -1) apply(pool[v].l, pool[v].lz, mid - l + 1);
    if(pool[v].r != -1) apply(pool[v].r, pool[v].lz, r - mid);
    pool[v].lz = tag();
  }

  void pull(int v) {
    pool[v].d = merge(
      pool[v].l != -1 ? pool[pool[v].l].d : node(),
      pool[v].r != -1 ? pool[pool[v].r].d : node()
    );
  }
  
  void update(int &v, int l, int r, int pos, const tag& t) {
    if(v == -1) v = new_vertex();
    if(l == r) return void(apply(v, t));
    
    push(v, l, r);
    int mid = (l + r) / 2;
    if(pos <= mid) update(pool[v].l, l, mid, pos, t);
    else update(pool[v].r, mid + 1, r, pos, t);
    pull(v);
  };
  
  void update(int &v, int l, int r, int pl, int pr, const tag& t) {
    if(l > pr || r < pl) return;
    if(v == -1) v = new_vertex();
    if(pl <= l && r <= pr) return void(apply(v, t, r - l + 1));
    
    push(v, l, r);
    int mid = (l + r) / 2;
    update(pool[v].l, l, mid, pl, pr, t);
    update(pool[v].r, mid + 1, r, pl, pr, t);
    pull(v);
  }

  node query(int v, int l, int r, int pos) {
    if(l == r) return pool[v].d;
    
    push(v, l, r);
    int mid = (l + r) / 2;
    if(pos <= mid) return query(pool[v].l, l, mid, pos);
    else return query(pool[v].r, mid + 1, r, pos);
  }
  
  node query(int v, int l, int r, int pl, int pr) {
    if(v == -1 || l > pr || r < pl) return node();
    if(pl <= l && r <= pr) return pool[v].d;
    
    push(v, l, r);
    int mid = (l + r) / 2;
    return merge(query(pool[v].l, l, mid, pl, pr), query(pool[v].r, mid + 1, r, pl, pr));
  }

  void update(int pos, int val) { update(root, 1, 1e9, pos, tag(val)); }
  void update(int l, int r, int val) { update(root, 1, 1e9, l, r, tag(val)); }
  int query(int l, int r) { return query(root, 1, 1e9, l, r).val; }
};