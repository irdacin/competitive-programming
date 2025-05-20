template<auto M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  explicit operator int() const { return val; }
 
  ModInt& operator+=(const ModInt& other) { return (val += other.val) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& other) { return (val -= other.val) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& other) { return (val *= other.val) %= M, *this; }
  ModInt& operator/=(const ModInt& other) { return *this *= inv(other.val); }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; --*this; return mi; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt() -= *this; }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }
 
  friend ModInt pow(ModInt mi, int k) { ModInt r = 1; for(; k > 0; k /= 2, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(ModInt mi) { return (int) pow(mi, M - 2); }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; } // use this for div if M is not prime
 
  bool operator==(const ModInt& other) const { return val == other.val; }
  bool operator!=(const ModInt& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

using mint = ModInt<1000000007>;
// using mint = ModInt<998244353>;
// using mint = ModInt<Barrett{}>;