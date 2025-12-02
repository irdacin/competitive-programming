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
template <typename T> inline void printsp(T&& A, char sp = ' ') { prin(A, sp); }

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

struct SparseTable {
  int n;
  vec<int> lg;
  vvec<int> table;

  SparseTable(vec<int> v) : n(len(v)) {
    build(v);
  }

  void build(vec<int> v){
    lg.resize(n + 1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    
    table.resize(lg[n] + 1, vec<int>(n));
    for(int i = 0; i < n; i++) table[0][i] = v[i];
    for(int j = 1; j <= lg[n]; j++){
      for(int i = 0; i + (1 << j) <= n; i++){
        table[j][i] = merge(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  int merge(int left, int right){
    return max(left, right);
  }

  int query(int l, int r){
    // l--, r--;
    int k = lg[r - l + 1];
    return merge(table[k][l], table[k][r - (1 << k) + 1]);

    int res = INF;
    for(int j = k; j >= 0; j--){
      if((1 << j) <= r - l + 1){
        res = merge(res, table[j][l]);
        l += 1 << j;
      }
    }

    return res;
  }
};

void solve() {
  int n, s, x; cin >> n >> s >> x;
  vec<int> a(n); cin >> a;

  SparseTable st(a);
  map<int, vec<int>> mp;
  mp[0].eb(-1);

  int ans = 0;

  for(int sum = 0, r = 0; r < n; r++) {
    sum += a[r];
    if(mp.find(sum - s) != mp.end()) {
      
      // for(auto l : mp[sum - s]) {
      //   print(l + 2, r + 1);
      //   if(st.query(l + 1, r) == x) ans++;
      // }

      auto &v = mp[sum - s];
      
      int posLeft = len(v);
      for(int left = 0, right = len(v) - 1; left <= right;) {
        int mid  = (left + right) / 2;

        if(st.query(v[mid] + 1, r) > x)  left = mid + 1;
        else posLeft = mid , right = mid - 1;
      }
  
      int posRight = -1;
      for(int left = 0, right = len(v) - 1; left <= right;) {
        int mid  = (left + right) / 2;

        if(st.query(v[mid] + 1, r) >= x) posRight = mid , left = mid + 1;
        else right = mid - 1;
      }

      // print(posLeft, posRight);

      ans += max(0LL, posRight - posLeft + 1);
    }

    mp[sum].eb(r);
  }

  print(ans);
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  int t; cin >> t; while(t--)
  solve();
}