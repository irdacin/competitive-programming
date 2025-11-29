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
  struct node {
    T val;
    int prior, size;
    node *l, *r;
    node(const T& v) : val(v), prior(rand()), size(1), l(NULL), r(NULL) {}
  } *root = NULL;

  inline int size(node *t) { return t ? t->size : 0; }

  void push(node *t) {

  }

  void pull(node *t) {
    if(!t) return;

    t->size = 1 + size(t->l) + size(t->r);
  }

  void split(node *t, node *&a, node *&b, int pos) {
    if(!t) return void(a = b = NULL);

    if(size(t->l) < pos) 
      split(t->r, t->r, b, pos - size(t->l) - 1), a = t;
    else 
      split(t->l, a, t->l, pos), b = t;

    pull(t);
  }

  void merge(node *&t, node *a, node *b) {
    if(!a || !b) 
      t = a ? a : b;
    else if(a->prior < b->prior) 
      merge(a->r, a->r, b), t = a;
    else
      merge(b->l, a, b->l), t = b;

    pull(t);
  }

  T at(node *t, int index) {
    if(index < 0 || index >= size()) throw;
    if(index < size(t->l))
      return at(t->l, index);
    if(index > size(t->l))
      return at(t->r, index - size(t->l) - 1);

    return t->val;
  }
  
  int size() { return size(root); }
  
  void emplace_back(const T& val) {
    merge(root, root, new node(val));
  }

  void update(int l, int r) {
    node *a, *b, *c, *d;
    split(root, a, b, l - 1); 
    split(b, c, d, r - l + 1);

    merge(root, a, d);
    merge(root, root, c);
  }

  T operator[](int index) {
    return at(root, index);
  }

};

void solve() {
  treap<char> t;

  int n, m; cin >> n >> m;
  for(char c; n--;) cin >> c, t.eb(c);

  for(int l, r; m--;) {
    cin >> l >> r;
    t.update(l, r);
  }

  for(int i = 0; i < len(t); i++) prin(t[i]);
}

signed main() {
  fastio;
  // #undef endl
 
  // precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}