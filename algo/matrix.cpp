struct matrix : vvec<mint> {
  using vvec<mint>::vvec;

  matrix& operator*=(const matrix& other) {
    int n = len((*this));
    int m = len((*this)[0]);
    assert(m == len(other));

    matrix res(n, len(other[0]));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < len(other[0]); j++)
        for(int k = 0; k < m; k++)
          res[i][j] += (*this)[i][k] * other[k][j];
    return *this = res;
  }

  matrix operator*(const matrix& other) const { 
    return matrix(*this) *= other; 
  }

  friend matrix pow(matrix mat, int k) {
    int n = len(mat);
    assert(n == len(mat[0]));

    matrix res(n, n);
    for(int i = 0; i < n; i++) res[i][i] = 1;
    for(; k > 0; k /= 2, mat *= mat) if(k & 1) res *= mat;
    return res;
  }
};