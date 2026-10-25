template <typename T>
struct CoordCompress {
  vector<T> v;
  CoordCompress() {}
  CoordCompress(const vector<T>& _v) : v(_v) { build(); }

  void build() { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
  void emplace(const T& x) { v.emplace_back(x); }
  int get(const T& x) const { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
  const T& operator[](int i) const { return v[i]; }
  size_t size() const { return v.size(); }
  void clear() { v.clear(); }
};