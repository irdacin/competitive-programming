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

void solve(string& s) {
  double x = 0, y = 0;

  auto get = [](char c) -> pii {
    if(c == 'N') return {0, 1};
    else if(c == 'E') return {1, 0};
    else if(c == 'S') return {0, -1};
    return {-1, 0};
  };

  int num = 0; string dir;
  for(auto c : s) {
    if(c == ',' || c == '.') {
      // print(num, dir);
      
      double row = 0, col = 0;
      for(auto ch : dir) {
        auto [x, y] = get(ch);
        row += x, col += y;
      }

      double d = sqrt(len(dir));
      row *= num / d, col *= num / d;
      x += row, y += col;

      num = 0;
      dir = "";
    } else if(c >= '0' && c <= '9') num = num * 10 + (c - '0');
    else dir += c;
  }

  prin("The treasure is located at ", "(", x, ",", y); print(").");
  prin("The distance to the treasure is ", sqrt(x * x + y * y)); print(".");
}

signed main() {
  fastio;
  cout << fixed << setprecision(3);

  // precompute();
  int tc = 1;
  for(string s; cin >> s && s != "END"; tc++)
  prin("Map #", tc), print(),
  solve(s), print();
}