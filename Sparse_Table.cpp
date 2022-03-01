template<typename T, class F = function<T(const T&, const T&)>>
struct SparseTable {
  vector<vector<T>> v;
  F f;
  SparseTable() { };
  SparseTable(vector<T> a, F _f) : f(_f) {
    int n = (int) a.size();
    a.resize(n);
    int lg = 32 - __builtin_clz(n);
    v.resize(lg);
    v[0] = a;
    for (int j = 1; j < lg; j++) {
      v[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        v[j][i] = f(v[j - 1][i], v[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int lg = 31 - __builtin_clz(r - l + 1);
    return f(v[lg][l], v[lg][r - (1 << lg) + 1]);
  }
};