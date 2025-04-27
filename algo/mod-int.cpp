template<auto M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  operator int() const { return val; }

  ModInt& operator+=(const ModInt& mi) { return (val += mi) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& mi) { return (val -= mi) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& mi) { return (val *= mi) %= M, *this; }
  ModInt& operator/=(const ModInt& mi) { return *this *= inv(mi); }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator-() const { return ModInt() -= *this; }
  ModInt operator+(const auto& mi) const { return ModInt(*this) += mi; }
  ModInt operator-(const auto& mi) const { return ModInt(*this) -= mi; }
  ModInt operator*(const auto& mi) const { return ModInt(*this) *= mi; }
  ModInt operator/(const auto& mi) const { return ModInt(*this) /= mi; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; --*this; return mi; }

  friend ModInt pow(ModInt mi, int k) { ModInt r = 1; for(; k > 0; k /= 2, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(ModInt mi) { return pow(mi, M - 2); }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; } // // use this for div if M is not prime

  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

using mint = ModInt<1000000007>;
// using mint = ModInt<998244353>;
// using mint = ModInt<Barrett{}>;