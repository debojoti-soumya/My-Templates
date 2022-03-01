template<typename T>
struct FenwickTree {
  vector<T> t;
  int n;
  FenwickTree(int _n) : n(_n) {
    t.resize(n + 1);
  }
  void update(int i, T v) {
    while (i <= n) {
      t[i] += v;
      i += i & (-i);
    }
  }
  T query(int i) {
    T ret = T();
    while (i >= 0) {
      ret += t[i];
      i -= i & (-i);
    }
    return ret;
  }
};

// needs invariant and (+) function