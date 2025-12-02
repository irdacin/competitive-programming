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

struct KMP {
  int m;  
  string pat;
  vec<int> pi;

  KMP(const string& s) : m(len(s)), pat(s) {
    pi.resize(m);

    for(int i = 1, j = 0; i < m; i++) {
      for(; j > 0 && s[i] != s[j]; j = pi[j - 1]); 
      if(s[i] == s[j]) j++;
      pi[i] = j;
    }
  }

  vec<int> match(const string& text) {
    vec<int> res;
    for(int i = 0, j = 0; i < len(text); i++) {
      for(; j > 0 && text[i] != pat[j]; j = pi[j - 1]);
      if(text[i] == pat[j]) j++;
      if(j == m) res.eb(i - m + 1), j = pi[j - 1];
    }

    return res;
  }
};

void solve() {
  string s; cin >> s;
  KMP kmp("bear");

  int ans = 0;
  int prev = -1;
  for(auto x : kmp.match(s)) {
    // debug(x);
    ans += (x - prev) * (prev + 1);
    prev = x;
  }

  // debug(prev);
  ans += (len(s) - (prev + 4) + 1) * (prev + 1);

  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}