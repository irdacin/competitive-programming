struct FenwickTree {
  int n;
  vec<int> bit;

  FenwickTree(int _n) : n(_n + 1) {
    bit.resize(n);
  }

  FenwickTree(const vec<int>& v) : FenwickTree(len(v)) {
    for(int i = 1; i < n; i++)
      update(i, v[i - 1]);
  }

  void update(int pos, int val) {
    for(; pos < n; pos += pos & -pos) 
      bit[pos] += val;
  }

  int query(int pos) {
    int res = 0;
    for(; pos > 0; pos -= pos & -pos)
      res += bit[pos];
    return res;
  }

  void update(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};