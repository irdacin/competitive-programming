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
const double EPS = 1e-9;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vec<int> a(n); cin >> a;
  vec<int> pref(n + 1);
  for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ a[i - 1];

  vec<iii> queries(m);
  for(int i = 0; auto &[l, r, id] : queries) cin >> l >> r, id = i++;

  const int BLOCK = sqrt(n) + 1;
  sort(all(queries), [BLOCK](auto a, auto b) {
    auto [l1, r1, id1] = a;
    auto [l2, r2, id2] = b;
    if(l1 / BLOCK == l2 / BLOCK) return r1 < r2;
    return l1 / BLOCK < l2 / BLOCK;
  });

  int res = 0;
  vec<int> mp(2'000'001);

  auto add = [&](int x) {
    res += mp[k ^ x];
    mp[x]++;
  };

  auto remove = [&](int x) {
    mp[x]--;
    res -= mp[k ^ x];
  };

  vec<int> ans(m);
  for(int curL = 1, curR = 0; auto [l, r, id] : queries) {
    while(curL < l) remove(pref[curL++]);
    while(curR > r) remove(pref[curR--]);
    while(curL >= l) add(pref[--curL]);
    while(curR < r) add(pref[++curR]);

    // print(curL, curR);
    ans[id] = res;
  }

  for(auto x : ans) print(x);
} 

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}