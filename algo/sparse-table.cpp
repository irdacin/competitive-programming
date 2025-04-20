struct SparseTable {
  int n;
  vec<int> lg;
  vvec<int> table;

  SparseTable(vec<int> v) : n(len(v)) {
    build(v);
  }

  void build(vec<int> v){
    lg.resize(n + 1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    
    table.resize(lg[n] + 1, vec<int>(n));
    for(int i = 0; i < n; i++) table[0][i] = v[i];
    for(int j = 1; j <= lg[n]; j++){
      for(int i = 0; i + (1 << j) <= n; i++){
        table[j][i] = merge(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  int merge(int left, int right){
    return min(left, right);
  }

  int query(int l, int r){
    l--, r--;
    int k = lg[r - l + 1];
    // return merge(table[k][l], table[k][r - (1 << k) + 1])

    int res = INF;
    for(int j = k; j >= 0; j--){
      if((1 << j) <= r - l + 1){
        res = merge(res, table[j][l]);
        l += 1 << j;
      }
    }

    return res;
  }
};