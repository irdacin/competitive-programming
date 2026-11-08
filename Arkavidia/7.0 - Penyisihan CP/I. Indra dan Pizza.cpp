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

const int MOD = 1e9 + 7;
const int INF = 2e9;
const int MAXN = 2e5;

void solve(){
  int n, m, q; cin >> n >> m >> q;

  vec<pii> plate(n + 1, {-1, -1});
  vec<pii> pos(m + 1, {-1, -1});

  for(int l, i = 1; i <= m; i++){
    cin >> l;

    int prev = -1;
    for(int a; l--;){
      cin >> a;
      if(pos[i].fi == -1) pos[i].fi = a;

      plate[a].fi = prev;
      if(prev != -1) plate[prev].se = a;
      prev = a;
    }

    pos[i].se = prev;
  }

  for(int type; q--;){
    cin >> type;

    if(int p, t; type == 1){
      cin >> p >> t;

      int cur = pos[t].se;
      if(cur != -1){
        plate[p].fi = cur;
        plate[cur].se = p;
      }
      else pos[t].fi = p;

      pos[t].se = p;
      
    } else if(int t1, t2; type == 2){
      cin >> t;

      int cur = pos[t].se;
      assert(cur != -1);
      assert(plate[cur].se == -1);

      int prev = plate[cur].fi;
      pos[t].se = prev;
      plate[cur] = {-1, -1};

      if(prev != -1) plate[prev].se = -1;
      else pos[t].fi = -1;

    } else {
      cin >> t1 >> t2;

      int last = pos[t2].se;
      int pertama = pos[t1].fi;

      if(pertama == -1) continue;

      if(last != -1){
        plate[last].se = pertama;
        plate[pertama].fi = last;
      } else {
        pos[t2].fi = pertama;
      }

      pos[t2].se = pos[t1].se;
      pos[t1] = {-1, -1};
    }
  }
  
  for(int i = 1; i <= m; i++){
    if(pos[i].fi == -1) continue;
    
    prin(i, ": ");
    for(int cur = pos[i].fi; cur != -1; cur = plate[cur].se) printsp(cur);
    print();
  }
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}