#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T &&A = "", U &&...B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T &&A, U &&...B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T &&A, const char* sp = " ") { prin(A, sp); }

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
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
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7; // 998244353
const int INF = 2e9;

void solve(){
  int n; cin >> n;

  int head = 0;
  map<int, pii> mp;
  for(int a, prev =0; n--;){
    cin >> a;
    if(head == 0) head = a;
    if(prev != 0) mp[prev].se = a;
    mp[a].fi = prev;
    prev = a;
  }

  int q; cin >> q;
  for(int t; q--;){
    cin >> t;
    if(int x, y; t == 1){
      cin >> x >> y;
      int nxt = mp[x].se;
      mp[x].se = y;
      mp[y] = {x, nxt};
      mp[nxt].fi = y;
    } else {
      cin >> x;

      pii cur = mp[x];
      if(cur.fi != 0) mp[cur.fi].se = cur.se;
      else head = cur.se;
      if(cur.se != 0) mp[cur.se].fi = cur.fi;
      mp[x] = {0, 0};
    }
  }

  for(; mp[head].se != 0; head = mp[head].se) printsp(head);
  print(head);
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}