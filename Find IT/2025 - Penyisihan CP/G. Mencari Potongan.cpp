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
const int INF = 2e18;
const double EPS = 1e-9;

void solve() {
  int n; cin >> n;
  vec<int> a(n); cin >> a;

  /*
  kenapa sum / 2?
  pertama-tama cari dulu jumlah angka pada bagian satu, katakanlah itu x
  nah berarti bisa dapat jumlah angka pada bagian dua itu sum - x
  jadi permasalahan ini ialah cari maximum dari persamaan x * (sum - x)

  pake sifat distributif, x nya bisa dikali masuk
  x * (sum - x) 
  x * sum - x**2
  => merupakan persamaan kuadrat

  untuk mendapatkan nilai maximum dari persamaan kuadrat
  rumusnya -b / 2a dengan b koef x dan a koef x**2
  sehingga nilai maximumnya 
  = -sum / (2 * (-1))
  = sum / 2
  kerenn
  */

  int sum = accumulate(all(a), 0LL);
  int ans = -INF;
  set<int> st;

  for(int i = 0, cur = 0; i < n; i++) {
    cur += a[i];

    // x = sum / 2
    // nyari current sum yang mendekati sum / 2
    auto it = st.lower_bound(cur - sum / 2);
    
    if(it != st.end()) {
      int x = cur - *it;
      ans = max(ans, x * (sum - x));
    }
    
    if(it != st.begin()) {
      int x = cur - *prev(it);
      ans = max(ans, x * (sum - x));
    }

    st.emplace(cur);
  }

  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}