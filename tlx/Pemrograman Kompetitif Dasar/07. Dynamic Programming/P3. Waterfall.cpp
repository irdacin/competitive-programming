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
template <typename T> inline void prinsp(T&& A, char sp = ' ') { prin(A, sp); }

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

void solve() {
  int v, h, n; cin >> v >> h >> n;
  vvec<bool> grid(v, h);
  for(int v1, h1, v2, h2; n--;) {
    cin >> v1 >> h1 >> v2 >> h2;
    for(int i = v1 - 1; i < v2; i++) {
      for(int j = h1 - 1; j < h2; j++) grid[i][j] = true;
    }
  }
  
  vvec<int> dp(v, h, -1);
  auto func = [&](auto func, int row, int col) {
    if(row == v) return 0LL;

    int &res = dp[row][col];
    if(res != -1) return res;

    if(grid[row][col]) {
      int left = col, right = col;
      for(; left >= 0 && grid[row][left]; left--);
      for(; right < h && grid[row][right]; right++);
      
      int cost = 1;
      if(left != -1)
        cost += func(func, row, left);
      if(right != h)
        cost += func(func, row, right);
      
      res = max(res, cost);
    } else res = func(func, row + 1, col);

    return res;
  };

  int ans = 0;
  for(int i = 0; i < h; i++) ans = max(ans, func(func, 0, i));
  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}