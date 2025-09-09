struct trie {
  struct node {
    array<int, 26> child;
    int cnt;
    int end;

    node() {
      child.fill(-1);
      cnt = end = 0;
    }

    int& operator[](char c) { return child[c - 'a']; }
  };

  vec<node> tr;
  trie() { tr.reserve(100'001), tr.eb(); }
  node& operator[](int idx) { return tr[idx]; }
  int nodes() { return len(tr) - 1; }

  void insert(string &s) {
    int u = 0;
    for(auto c : s) {
      if(tr[u][c] == -1) tr[u][c] = len(tr), tr.eb();
      u = tr[u][c];
      tr[u].cnt++;
    }
    tr[u].end++;
  }
};