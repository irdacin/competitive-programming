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
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e18;
const int MAXN = 2e5;

void solve(){
  int c, r; cin >> c >> r;
  vvec<char> grid(r, c); cin >> grid;
  vec<pii> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int k = 0, b = 0;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(grid[i][j] == 'K' || grid[i][j] == 'B'){
        auto temp = grid;
        queue<pii> q;
        q.emplace(i, j);

        while(!q.empty()){
          auto [row, col] = q.front(); q.pop();
          for(auto [x, y] : dir){
            x += row, y += col;
            if(x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == '.'){
              grid[x][y] = '#';
              q.emplace(x, y);
              k += grid[i][j] == 'K', b += grid[i][j] == 'B';
            }
          }
        }
        grid = temp;
      }
    }
  }

  if(k > b) print("K", k - b);
  else if(k < b) print("B", b - k);
  else print("SERI");
}

signed main(){
  // #define INTERACTIVE
  #ifdef INTERACTIVE
  #undef endl
  #else
  fastio;
  #endif

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}