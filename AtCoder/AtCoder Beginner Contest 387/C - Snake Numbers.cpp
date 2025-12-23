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

int calc(int n){
  vec<int> digit;
  for(; n > 0; n /= 10) digit.eb(n % 10);
  int sz = len(digit);

  // dp digit
  vvvec<int> dp(sz, 10, 2, -1);
  // dp[idx][maxDigit][tight]
  // idx utk tau nilai sekarang dari kanan
  // maxDigit utk tau terakhir max itu digit apa
  //    maxDigit = 0 ==> blm diinit
  // tight utk tau apakah dibatasi atau ga
  //    jika dibatasi, maka rentagnya dari 0 sampe digit[idx] (inklusif)
  //    jika ga, maka rentangnya dari 0 sampe 9 (inklusif)

  auto func = [&](auto func, int idx, int maxDigit, int tight){
    if(idx == -1) return 1LL;

    int &res = dp[idx][maxDigit][tight];
    if(res != -1) return res;

    res = 0;

    int k = tight ? digit[idx] : 9;
    if(maxDigit == 0){
      for(int i = 0; i <= k; i++){
        res += func(func, idx - 1, i, tight && digit[idx] == i);
      }
    } else {
      // spesial case, dikarenakan digit berikutnya mau lebih besar dari yang pertama,
      // batas akhirnya cuma ambil minimum dari maxDigit - 1 dan k
      for(int i = 0; i <= min(maxDigit - 1, k); i++){
        res += func(func, idx - 1, maxDigit, tight && digit[idx] == i);
      }
    }
    
    return res;
  };

  return func(func, sz - 1, 0, 1);
}

void solve(){
  int l, r; cin >> l >> r;
  print(calc(r) - calc(l - 1));
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}