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
  int n, m; cin >> n >> m;
 
  vvec<int> dp(m, 1 << n, -1);
  auto func = [&](auto func, int i, int mask1) {
    if(i == m) return mask1 == 0  ? 1LL : 0LL;
    
    int &res = dp[i][mask1];
    if(res != -1) return res;
 
    res = 0;
    auto generate = [&](auto self, int row, int cur1, int cur2 ) {
      if(row == n) {
        (res += func(func, i + 1, cur2)) %= MOD;
        return;
      }

      if(cur1 >> row & 1) {
        self(self, row + 1, cur1, cur2);
        return;
      }
 
      // place 2 x 1
      if(row + 1 < n && (cur1 >> (row + 1) & 1) == 0)
        self(self, row + 2, cur1 | (1 << row) | (1 << (row + 1)) , cur2);
      
      // place 1 x 2
      if(i + 1 < m)
        self(self, row + 1, cur1 | (1 << row), cur2 | (1 << row));
    };
 
    generate(generate, 0, mask1, 0);
    return res;
  };
 
  print(func(func, 0, 0));

}
 
signed main() {
  fastio;
  // cout << fixed << setprecision(6);
 
  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}