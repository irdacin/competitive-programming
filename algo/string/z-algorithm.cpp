struct ZAlgo {
  vec<int> z_function(const string& s) {
    int n = len(s);
    vec<int> z(n);

    for(int l = 0, r = 0, i = 1; i < n; i++) {
      if(i < r) z[i] = min(r - i, z[i - l]);
      for(; i + z[i] < n && s[z[i]] == s[i + z[i]]; z[i]++);
      if(i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
  }

  vec<int> match(const string& text, const string& pat) {
    string s = pat + '#' + text;
    vec<int> res, z = z_function(s);
 
    for(int m = len(pat), i = m + 1; i < len(s); i++) {
      if(z[i] == m) res.eb(i - m - 1);
    }
    return res;
  }
};