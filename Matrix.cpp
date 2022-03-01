template<typename T, const int n>
struct Matrix {
  T t[n + 1][n + 1] = {0};
  Matrix() { }
  Matrix(T x) {
    for (int i = 1; i <= n; i++) t[i][i] = x;
  }
  Matrix operator*(Matrix<T, n> o) {
    Matrix<T, n> ret(0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          ret.t[i][j] += t[i][k] * o.t[k][j];
        }
      }
    }
    return ret;
  }
  friend Matrix power(Matrix a, long long k) {
    Matrix<T, n> ret(1);
    while (k > 0) {
      if (k & 1) ret = ret * a;
      a = a * a, k >>= 1;
    }
    return ret;
  }
  friend ostream& operator<<(ostream &out, Matrix<T, n> a) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) cout << a.t[i][j] << " ";
      cout << "\n";
    }
    return out;
  }
};