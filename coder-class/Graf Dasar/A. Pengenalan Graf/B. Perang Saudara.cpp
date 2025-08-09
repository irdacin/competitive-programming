#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int u, v; m--;) {
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int q; cin >> q;
  for(int a, b; q--;) {
    cin >> a >> b;
    a--, b--;

    int ans = 0;

    for(auto u : adj[a]) {
      for(auto v : adj[b]) {
        if(u == v) ans++;
      }
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}