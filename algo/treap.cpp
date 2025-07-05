template <typename T> 
struct treap {
  struct node;
  using pnode = node*;
  pnode root;
  
  struct node {
    T val;
    int prior, size;
    pnode l, r;
    bool rev;
    node(const T& v) : val(v), prior(rand()), size(1), l(NULL), r(NULL), rev(false) {}
  };
  
  treap() : root(NULL) {}

  int size(pnode t) { return t ? t->size : 0; }

  void push(pnode t) {
    if(!t) return;

    if(t->rev) {
      swap(t->l, t->r);

      if(t->l) t->l->rev ^= 1;
      if(t->r) t->r->rev ^= 1;

      t->rev = false;
    }
  }

  void pull(pnode t) {
    if(!t) return;

    t->size = 1 + size(t->l) + size(t->r);
  }

  pair<pnode, pnode> split(pnode t, int pos) {
    if(!t) return {NULL, NULL};

    push(t);

    if(size(t->l) < pos) {
      auto [a, b] = split(t->r, pos - size(t->l) - 1);
      t->r = a, pull(t);

      return {t, b};
    }

    auto [a, b] = split(t->l, pos);
    t->l = b, pull(t);
    
    return {a, t};
  }

  pnode merge(pnode a, pnode b) {
    if(!a || !b) return a ? a : b;
    
    push(a), push(b);

    if(a->prior < b->prior) {
      a->r = merge(a->r, b), pull(a);
      return a;
    }

    b->l = merge(a, b->l), pull(b);
    return b;
  }

  T at(pnode t, int index) {
    assert(index >= 0 && index < size(root));
    
    push(t);
    if(index < size(t->l))
      return at(t->l, index);
    if(index > size(t->l))
      return at(t->r, index - size(t->l) - 1);

    return t->val;
  }

  T operator[](int index) {
    return at(root, index);
  }
  
  int size() { return size(root); }
  
  void insert(const T& val) {
    root = merge(root, new node(val));
  }

  void insert_at(int index, const T& val) {
    assert(index >= 0 && index <= size(root));
    
    auto [a, b] = split(root, index);
    root = merge(merge(a, new node(val)), b);
  }

  void erase_at(int index) {
    assert(index >= 0 && index < size(root));

    auto [a, x] = split(root, index);
    auto [b, c] = split(x, 1);

    root = merge(a, c);
  }

  void clear() {
    root = NULL;
  }

  void update(int l, int r) {
    l--, r--;
    
    auto [a, x] = split(root, l);
    auto [b, c] = split(x, r - l + 1);

    b->rev = true;
    
    root = merge(merge(a, b), c);
  }
  
  T query(int l, int r) {

  }
};