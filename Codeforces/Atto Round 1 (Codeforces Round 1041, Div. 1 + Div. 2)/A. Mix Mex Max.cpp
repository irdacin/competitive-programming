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
  int n; cin >> n;
  vec<int> a(n); cin >> a;

  for(int i = 0; i < n - 2; i++) {
    int x = a[i];
    int y = a[i + 1];
    int z = a[i + 2];
    if(x != -1 && y != -1 && z != -1) {
      if(x > y) swap(x, y);
      if(y > z) swap(y, z);
      if(x > y) swap(x, y);

      int mex = 0;
      if(mex == x) mex++;
      if(mex == y) mex++;
      if(mex == z) mex++;

      if(mex != z - x) return print("NO");
    } 

    else if(x == -1) {
      if(y == -1 && z == 0) return print("NO");
      else if(z == -1 && y == 0) return print("NO"); 
      else if(y != -1 && z != -1 && y != z) return print("NO");
      else if(y != -1 && z != -1 && y == z && y == 0) return print("NO");

      int val = -1;
      if(y != -1) val = y;
      if(z != -1) val = z;

      a[i] = val;
      if(a[i + 1] == -1) a[i + 1] = val;
      if(a[i + 2] == -1) a[i + 2] = val;
      
    } else if(y == -1) {
      if(x == -1 && z == 0) return print("NO");
      else if(z == -1 && x == 0) return print("NO");
      else if(x != -1 && z != -1 && x != z) return print("NO");
      else if(x != -1 && z != -1 && x == z && x == 0) return print("NO");
      
      int val = -1;
      if(x != -1) val = x;
      if(z != -1) val = z;

      a[i] = val;
      if(a[i + 1] == -1) a[i + 1] = val;
      if(a[i + 2] == -1) a[i + 2] = val;
      
    } else if(z == -1) {
      if(x == -1 && y == 0) return print("NO");
      else if(y == -1 && x == 0) return print("NO");
      else if(x != -1 && y != -1 && x != y) return print("NO");
      else if(x != -1 && y != -1 && x == y && x == 0) return print("NO");
      
      int val = -1;
      if(x != -1) val = x;
      if(y != -1) val = y;
  
      a[i] = val;
      if(a[i + 1] == -1) a[i + 1] = val;
      if(a[i + 2] == -1) a[i + 2] = val;
      
    }
  }

  print("YES");
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  int t; cin >> t; while(t--)
  solve();
}