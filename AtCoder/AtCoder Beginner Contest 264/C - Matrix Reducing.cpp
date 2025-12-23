#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, const char* sp = " ") { prin(A, sp); }

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
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
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

void solve() {
  int h1, w1; cin >> h1 >> w1;
  vvec<int> a(h1, w1); cin >> a;
  int h2, w2; cin >> h2 >> w2;
  vvec<int> b(h2, w2); cin >> b;

  vec<bool> row(h1, true), col(w1, true);
  auto func2 = [&](auto func, int w, int takew) {

    if(w1 - takew == w2) {
      // vvec<int> cur;
      for(int i = 0, r = 0; i < h1; i++) {
        if(row[i]) {
          for(int j = 0, c = 0; j < w1; j++) {
            if(col[j] && a[i][j] != b[r][c++]) return false;
          }
          r++;
        }
      }

      // for(auto x : cur) print(x); print();
      // return cur == b;
      return true;
    }

    if(w == w1 || w1 - takew < w2) return false;
    col[w] = false;
    if(func(func, w + 1, takew + 1)) return true;
    col[w] = true;
    if(func(func, w + 1, takew)) return true;
    return false;
  };
  
  auto func = [&](auto func, int h, int takeh) {
    // print(h, w);
    // if(h > h1 || w > w1 ) return false;

    
    if(h1 - takeh == h2) {

      return func2(func2, 0, 0);
    }
    if(h1 == h || h1 - takeh < h2 ) return false;
    

      row[h] = false;
      if(func(func, h + 1, takeh + 1)) return true;
      row[h] = true;
      if(func(func, h + 1, takeh)) return true;
    

    return false;
  };

  print(func(func, 0, 0) ? "Yes" : "No");
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}