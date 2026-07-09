#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

#ifndef ONLINE_JUDGE
void _print(bool _x) { cout << (_x ? "true" : "false"); }
template <typename T> void _print(const T& _x) {
  if constexpr (ranges::range<T> && !is_convertible_v<T, string>) {
    cout << "{ "; bool _f = 0;
    for (auto _e : _x) cout << (_f ? ", " : (_f = 1, "")), _print(_e);
    cout << " }";
  }
  else if constexpr (requires(T _c) { _c.empty(); _c.pop(); }) {
    cout << "{ "; bool _f = 0;
    for (auto _c = _x; !_c.empty(); _c.pop(), _f = 1) {
      cout << (_f ? ", " : "");
      if constexpr (requires{ _c.top(); }) _print(_c.top());
      else _print(_c.front());
    } cout << " }";
  }
  else if constexpr (requires { typename tuple_size<T>::type; }) {
    cout << "("; bool _f = 0; apply([&](const auto&... _e) {
      ((cout << (_f ? ", " : ""), _print(_e), _f = 1), ...); }, _x
    ); cout << ")";
  }
  else cout << _x;
}
template <typename... T> void print(const T&... _x) {
  if constexpr (sizeof...(_x)) {
    bool _f = 0; ((cout << (_f ? " " : ""), _print(_x), _f = 1), ...);
  } cout << endl;
}
#define prind(...) cout << "[" << #__VA_ARGS__ << "] = "; print(__VA_ARGS__)
#else
#define prind(...)
inline void print() { cout << endl; }
template <typename T> inline void print(T&& A) { cout << A << endl; }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { cout << A << ' '; print(B...); }
#endif
template <typename T = const char*, typename... U>
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T> inline void prins(T&& A) { cout << A << ' '; }

template <typename T> bool chmax(T& a, const T& b) { return b > a ? (a = b, 1) : 0; }
template <typename T> bool chmin(T& a, const T& b) { return b < a ? (a = b, 1) : 0; }
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for (auto& _x : _v) { is >> _x; } return is;
}
template <typename T> inline void prinv(const T& A, string sp = " ") {
  bool _f = 0; for (const auto& _x : A) cout << (_f ? sp : "") << _x, _f = 1;
  cout << endl;
}

template <typename T> using vec = vector<T>;
template <typename T> struct vvec : vec<vec<T>> {
  using vec<vec<T>>::vec;
  vvec(size_t N = 0, size_t M = 0, const T& _init_value = T())
    : vec<vec<T>>(N, vec<T>(M, _init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
  using vec<vvec<T>>::vec;
  vvvec(size_t N = 0, size_t M = 0, size_t K = 0, const T& _init_value = T())
    : vec<vvec<T>>(N, vvec<T>(M, K, _init_value)) {}
};

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second
#define emp emplace
#define eb emplace_back
#define run(...) [&](){__VA_ARGS__}()
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;
const double EPS = 1e-9;

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
    // l--, r--;

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

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  treap<int> tr;
  for(int i = 1; i <= n; i++) tr.insert(i);
  for(int i = 0; i < n; i++) if(s[i] == 'o') tr.update(0, i);

  for(int i = 0; i < n; i++) prins(tr[i]);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while (t--)
  solve();
}