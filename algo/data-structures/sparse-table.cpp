struct SparseTable {
  int n;
  vec<int> lg;
  vvec<int> table;

  SparseTable() {}
  SparseTable(const vec<int>& v) : n(len(v)) {
    lg.resize(n + 1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    table.resize(lg[n] + 1, vec<int>(n));
    for(int i = 0; i < n; i++) table[0][i] = v[i];
    for(int k = 1; k <= lg[n]; k++) {
      for(int i = 0; i + (1 << k) <= n; i++) {
        table[k][i] = merge(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  int merge(int left, int right) {
    return min(left, right);
  }

  int query(int l, int r) {
    // l--, r--;
    int k = lg[r - l + 1];
    return merge(table[k][l], table[k][r - (1 << k) + 1]);

    int res = INF;
    for(; k >= 0; k--) {
      if((1 << k) <= r - l + 1) {
        res = merge(res, table[k][l]);
        l += 1 << k;
      }
    }

    return res;
  }
};