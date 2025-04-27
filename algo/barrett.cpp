struct Barrett {
  using u128 = __uint128_t;
  static inline u128 mod, mu;

  static void set_mod(int m) { mod = m, mu = -1 / mod; }
  operator int() const { return mod; }
  friend auto operator%(auto x, const Barrett) { return reduce(x); }

  static u128 reduce(u128 val) {
    u128 a = val * uint64_t(mu);
    u128 b = val * (mu >> 64);
    u128 c = mu * (val >> 64);
    u128 d = (val >> 64) * (mu >> 64);
    u128 q = d + ((b + c + (a >> 64)) >> 64);
    u128 r = val - q * mod;
    if(r >= mod) r -= mod;
    return r;
  }
};