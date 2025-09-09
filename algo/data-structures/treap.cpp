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

  void split(pnode t, pnode &a, pnode &b, int pos) {
    if(!t) return void(a = b = NULL);
 
    push(t);
 
    if(size(t->l) < pos) 
      split(t->r, t->r, b, pos - size(t->l) - 1), a = t;
    else 
      split(t->l, a, t->l, pos), b = t;
 
    pull(t);
  }
 
  void merge(pnode &t, pnode a, pnode b) {
    push(a), push(b);
 
    if(!a || !b) 
      t = a ? a : b;
    else if(a->prior < b->prior) 
      merge(a->r, a->r, b), t = a;
    else
      merge(b->l, a, b->l), t = b;
 
    pull(t);
  }

  T at(pnode t, int index) {
    push(t);

    if(index < size(t->l))
      return at(t->l, index);
    if(index > size(t->l))
      return at(t->r, index - size(t->l) - 1);

    return t->val;
  }

  T operator[](int index) {
    assert(index >= 0 && index < size(root));
    return at(root, index);
  }
 
  int size() { return size(root); }
  
  void insert(const T& val) {
    merge(root, root, new node(val));
  }

  void insert_at(int index, const T& val) {
    assert(index >= 0 && index <= size());

    pnode a, b;
    split(root, a, b, index);
    merge(a, a, new node(val));
    merge(root, a, b);
  }
 
  void erase_at(int index) {
    assert(index >= 0 && index < size());

    pnode a, b, c;
    split(root, a, b, index);
    split(b, b, c, 1);
    merge(root, a, c);
  }

  void clear() {
    root = NULL;
  }

  void update(int l, int r) {
    l--, r--;

    pnode a, b, c;
    split(root, a, b, l);
    split(b, b, c, r - l + 1);

    b->rev = true;

    merge(root, a, b);
    merge(root, root, c);
  }

  T query(int l, int r) {

  }
};