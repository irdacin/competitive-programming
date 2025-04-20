template<int M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  
  ModInt& operator+=(const ModInt& mi) { return (val += mi.val) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& mi) { return (val -= mi.val) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& mi) { return (val *= mi.val) %= M, *this; }
  ModInt& operator/=(const ModInt& mi) { return (val *= inv(mi)) %= M, *this; }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator-() const { return ModInt() -= *this; }
  ModInt operator+(const ModInt& mi) const { return ModInt(*this) += mi; }
  ModInt operator-(const ModInt& mi) const { return ModInt(*this) -= mi; }
  ModInt operator*(const ModInt& mi) const { return ModInt(*this) *= mi; }
  ModInt operator/(const ModInt& mi) const { return ModInt(*this) /= mi; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; --*this; return mi; }
  
  friend ModInt pow(ModInt mi, int k) { ModInt r = 1; for(; k > 0; k /= 2, mi *= mi) if(k & 1) r *= mi; return r; }
  friend int inv(ModInt mi) { return pow(mi, M - 2).val; }
  friend int inv(ModInt mi, int mod) { return mi == 1 ? 1 : mod - inv(ModInt(mod % mi.val), mi.val) * mod / mi.val; } // use this for divisor if M is not prime
  
  bool operator==(const ModInt& mi) const { return val == mi.val; }
  bool operator!=(const ModInt& mi) const { return val != mi.val; }
  bool operator>=(const ModInt& mi) const { return val >= mi.val; }
  bool operator<=(const ModInt& mi) const { return val <= mi.val; }
  bool operator>(const ModInt& mi) const { return val > mi.val; }
  bool operator<(const ModInt& mi) const { return val < mi.val; }
  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

using mint = ModInt<MOD>;