struct RollingHash {
  using mint7 = ModInt<1000000007>;
  using mint9 = ModInt<1000000009>;
  const int BASE = 131;

  vec<mint7> hash1, power1;
  vec<mint9> hash2, power2;

  RollingHash(const string& s) {
    int n = len(s);
    hash1.resize(n + 1);
    hash2.resize(n + 1);
    power1.resize(n + 1);
    power2.resize(n + 1);
    hash1[0] = 0;
    hash2[0] = 0;
    power1[0] = 1;
    power2[0] = 1;

    for(int i = 0; i < n; i++) {
      hash1[i + 1] = hash1[i] * BASE + s[i];
      hash2[i + 1] = hash2[i] * BASE + s[i];
      power1[i + 1] = power1[i] * BASE;
      power2[i + 1] = power2[i] * BASE;
    }
  }

  pair<mint7, mint9> get(int l, int r) { // [l, r)
    mint7 h1 = hash1[r] - hash1[l] * power1[r - l];
    mint9 h2 = hash2[r] - hash2[l] * power2[r - l];
    return {h1, h2};
  }
};