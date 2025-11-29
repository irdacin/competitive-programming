#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << (x) << endl
 
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) { 
  os << "(" << _p.first << ", " << _p.second << ")"; return os; 
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for (auto& _x : _v) { is >> _x; } return is;
}
template <typename Ch, typename Tr, typename Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, const Container& _c) {
  int _i = 0; os << "{ "; for (const auto& _x : _c) { os << (_i++ ? ", " : "") << _x; }
  return os << " }";
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, char sp = ' ') { prin(A, sp); }

template <typename T> using vec = vector<T>;
template <typename T> struct vvec : vec<vec<T>> {
  using vec<vec<T>>::vec;
  vvec(int N = 0, int M = 0, const T& _init_value = T())
    : vec<vec<T>>(N, vec<T>(M, _init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
  using vec<vvec<T>>::vec;
  vvvec(int N = 0, int M = 0, int K = 0, const T& _init_value = T())
    : vec<vvec<T>>(N, vvec<T>(M, K, _init_value)) {}
};

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

template <typename T> 
struct treap {
  struct node;
  using pnode = node*;

  struct node {
    T val;
    int prior, size;
    pnode l, r;
    bool rev;
    T sum;
    node(const T& v) : val(v), prior(rand()), size(1), l(NULL), r(NULL), rev(false), sum(val) {}
  };

  pnode root;
  treap() : root(NULL) {}

  int size(pnode t) { return t ? t->size : 0; }
  T sum(pnode t) { return t ? t->sum : T(); }

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
    t->sum = t->val + sum(t->l) + sum(t->r);
  }

  pair<pnode, pnode> split(pnode t, int pos) {
    if(!t) return {NULL, NULL};

    push(t);

    if(size(t->l) < pos) {
      auto [a, b] = split(t->r, pos - size(t->l) - 1);
      t->r = a; pull(t);
      return {t, b};
    }

    auto [a, b] = split(t->l, pos);
    t->l = b; pull(t);
    return {a, t};
  }

  pnode merge(pnode a, pnode b) {
    push(a), push(b);

    if(!a || !b) return a ? a : b;

    if(a->prior < b->prior) {
      a->r = merge(a->r, b);
      return pull(a), a;
    }

    b->l = merge(a, b->l);
    return pull(b), b;
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
    auto [a, x] = split(root, l);
    auto [b, c] = split(x, r - l + 1);
    
    b->rev = true;
    
    root = merge(merge(a, b), c);
  }
  
  T query(int l, int r) {
    auto [a, x] = split(root, l);
    auto [b, c] = split(x, r - l + 1);

    T res = sum(b);
    return root = merge(merge(a, b), c), res;
  }

};

void solve() {
  int n, m; cin >> n >> m;
 
  treap<int> tr;
  for(int a; n--;) cin >> a, tr.insert(a);
 
  for(int t, l, r; m--;) {
    cin >> t >> l >> r;
    l--, r--;
 
    if(t == 1) tr.update(l, r);
    else print(tr.query(l, r));
  }
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}