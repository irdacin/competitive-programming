#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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
const int MAXN = 2e6;

void solve(){
  int n; cin >> n;

  // x**3 - y**3 = n
  // because overflow of long long,  
  // it can't be binary search directly like that
  
  // so want to convert into that equation into like this
  // (x - y) * (x**2  + xy + y**2) = n
  // (x**2  + xy + y**2) = n / (x - y)
  // first we brute force first all number of (x - y)
  // lets say the variabel name i
  // we can get x
  // x = i + y
  // just plug it into the equation

  // so we get
  // (i + y)**2 + (i + y)*y + y**2 = n / i
  // i**2 + 2iy + y**2 + iy + y**2 + y**2 = n / i
  // 3*y**2 + 3iy + i**2 = n / i
  // now just binary search the y to solve the equation
  
  for(int i = 1; i <= MAXN; i++){
    if(n % i != 0) continue;

    for(int left = 1, right = INF; left <= right;){
      int y = (left + right) / 2;

      int res = 3LL * y * y  + 3LL * i * y + i * i;
      if(res == n / i) return print(i + y, y);

      if(res < n / i) left = y + 1;
      else right = y - 1;
    }
  }

  print(-1);
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}