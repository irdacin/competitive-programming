struct KMP {
  int m;  
  string pat;
  vec<int> pi;

  KMP(const string& s) : m(len(s)), pat(s) {
    pi.resize(m);
 
    for(int i = 1, j = 0; i < m; i++) {
      for(; j > 0 && s[i] != s[j]; j = pi[j - 1]); 
      if(s[i] == s[j]) j++;
      pi[i] = j;
    }
  }

  vec<int> match(const string& text) {
    vec<int> res;
    for(int i = 0, j = 0; i < len(text); i++) {
      for(; j > 0 && text[i] != pat[j]; j = pi[j - 1]);
      if(text[i] == pat[j]) j++;
      if(j == m) res.eb(i - m + 1), j = pi[j - 1];
    }
 
    return res;
  }
};