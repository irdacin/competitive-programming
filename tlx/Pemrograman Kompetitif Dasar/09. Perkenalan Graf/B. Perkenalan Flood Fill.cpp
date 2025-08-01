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
  size_t _i = 0; os << "{ "; for (const auto& _x : _c) { os << (_i++ ? ", " : "") << _x; }
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
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

void solve() {
  int c, r; cin >> c >> r;
  vvec<char> grid(r, c); cin >> grid;

  vec<pii> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  auto bfs = [=](int i, int j) {
    queue<pii> q;
    q.emplace(i, j);
    auto temp = grid;

    int res = 0;
    while(!q.empty()) {
      auto [row, col] = q.front(); q.pop();

      for(auto [x, y] : dir) {
        x += row, y += col;
        if(x >= 0 && x < r && y >= 0 && y < c && temp[x][y] == '.') {
          res++;
          temp[x][y] = '#';
          q.emplace(x, y);
        }
      }
    }

    return res;
  };

  int k = 0, b = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(grid[i][j] == 'K') k += bfs(i, j);
      else if(grid[i][j] == 'B') b += bfs(i, j);
    } 
  }

  if(k > b) print("K", k - b);
  else if(k < b) print("B", b - k);
  else print("SERI");
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}