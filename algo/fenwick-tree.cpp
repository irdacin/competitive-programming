struct FenwickTree {
  int n;
  vec<int> bit;

  FenwickTree(int _n) : n(_n + 1) {
    bit.resize(n);
  }

  FenwickTree(const vec<int>& v) : FenwickTree(len(v)) {
    for(int i = 0; i < len(v); i++)
      update(i, v[i]);
  }

  void update(int pos, int val) {
    for(++pos; pos < n; pos += pos & -pos) 
      bit[pos] += val;
  }

  int query(int pos) {
    int res = 0;
    for(++pos; pos > 0; pos -= pos & -pos)
      res += bit[pos];
    return res;
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};