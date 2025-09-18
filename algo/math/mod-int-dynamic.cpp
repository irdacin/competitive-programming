struct mint {
  using u128 = __uint128_t;
  static inline uint64_t mod, mu;
  uint64_t val;

  mint() : val(0) {}
  mint(int v) { if (v < 0) (v %= (int)mod) += mod; val = reduce(v); }
  explicit operator int() const { return val; }
  static void set_mod(int m) { mod = m, mu = -1ULL / m; }
  static inline uint64_t reduce(u128 x) {
    u128 q = (x * mu) >> 64;
    u128 r = x - q * mod;
    return r >= mod ? r - mod : r;
  }

  mint& operator+=(const mint& other) { return (val += other.val) >= mod ? val -= mod : val, *this; }
  mint& operator-=(const mint& other) { return (val -= other.val) >= mod ? val += mod : val, *this; }
  mint& operator*=(const mint& other) { return val = reduce(u128(val) * other.val), *this; }
  mint& operator/=(const mint& other) { return *this *= inv(other); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  mint operator++(int32_t) { mint mi = *this; ++*this; return mi; }
  mint operator--(int32_t) { mint mi = *this; --*this; return mi; }
  mint operator+() const { return *this; }
  mint operator-() const { return mint() -= *this; }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }

  friend mint pow(mint mi, int k) { mint r(1); for(; k > 0; k >>= 1, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; }
  static mint inv(mint mi) {
    // return pow(mi, mod - 2);
    // if(gcd(mi.val, mod) != 1) return -1;
    return mint(inv(mi.val, mod)); // use this inv if mod is not prime
  }

  bool operator==(const mint& other) const { return val == other.val; }
  bool operator!=(const mint& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, mint& mi) { int x; is >> x; mi = mint(x); return is; }
  friend ostream& operator<<(ostream& os, const mint& mi) { return os << mi.val; }
};