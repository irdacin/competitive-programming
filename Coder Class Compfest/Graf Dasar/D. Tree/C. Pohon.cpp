#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i = 1, p; i < n; i++) {
    cin >> p, p--;
    adj[p].emplace_back(i);
  }

  auto dfs = [&](auto dfs, int u, int par = -1) -> pair<int, int> {
    int leaf = adj[u].empty(), height = 0;

    for(auto v : adj[u]) {
      if(v != par) {
        auto [l, h] = dfs(dfs, v);
        leaf += l, height = max(height, h + 1);
      }
    }

    return {leaf, height};
  };

  auto [leaf, height] = dfs(dfs, 0);
  cout << leaf << ' ' << height << '\n';
  
  return 0;
}