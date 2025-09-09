template <typename T>
struct FenwickTree {
  int n;
  vec<T> d;

  FenwickTree(int _n) : n(_n + 1) {
    d.resize(n);
  }

  FenwickTree(const vec<int>& v) : FenwickTree(len(v)) {
    for(int i = 0; i < len(v); i++)
      update(i, v[i]);
  }

  void update(int pos, T val) {
    for(pos++; pos < n; pos += pos & -pos) 
      d[pos] += val;
  }

  T query(int pos) {
    T res = 0;
    for(pos++; pos > 0; pos -= pos & -pos)
      res += d[pos];
    return res;
  }

  T query(int l, int r) { // [l, r]
    return query(r) - query(l - 1);
  }
};