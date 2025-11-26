#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> tin(n), tout(n);
  int timer = 0;

  auto dfs = [&](auto dfs, int u, int par = -1) -> void {
    tin[u] = ++timer;

    for(auto v : adj[u]) {
      if(v != par) {
        dfs(dfs, v, u);
      }
    }

    tout[u] = ++timer;
  };

  auto is_ancestor = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  };

  dfs(dfs, 0);

  int q; cin >> q;
  for(int x, y; q--;) {
    cin >> x >> y; x--, y--;
    cout << (is_ancestor(x, y) ? "TIDAK" : "YA") << '\n';
  }

  return 0;
}