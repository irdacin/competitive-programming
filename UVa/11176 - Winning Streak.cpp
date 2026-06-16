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
const int MAXN = 505;
double dp[MAXN + 1][MAXN + 1][MAXN + 1];

void solve(int n) {
  double p; cin >> p;

  // for(int i = 0; i <= MAXN; i++) 
  //   for(int j = 0; j <= MAXN; j++)
  //     for(int k = 0; k <= MAXN; k++) 
  //       dp[i][j][k] = -1;

  function<double(int, int, int)> func = [&](int i, int cur, int streak) -> double {
    if(i == n) return streak;

    double &res = dp[i][cur][streak];
    if(res != -1) return res;

    res = func(i + 1, 0, streak) * (1.0 - p);
    res += func(i + 1, cur + 1, max(streak, cur + 1)) * p;
    return res;
  };
  
  // print(func(0, 0, 0));

  for(int cur = 0; cur <= n; cur++)
    for(int streak = 0; streak <= n; streak++) dp[n][cur][streak] = streak;

  for(int i = n - 1; i >= 0; i--) {
    for(int cur = 0; cur <= i; cur++) {
      for(int streak = 0; streak <= i; streak++) {
        dp[i][cur][streak] = dp[i + 1][0][streak] * (1.0 - p) + dp[i + 1][cur + 1][max(streak, cur + 1)] * p;
      }
    }
  }

  print(dp[0][0][0]);
}

signed main() {
  fastio;
  cout << fixed << setprecision(4);

  // precompute();
  // int t; cin >> t; while(t--)
  for(int n; cin >> n && n;)
  solve(n);
}