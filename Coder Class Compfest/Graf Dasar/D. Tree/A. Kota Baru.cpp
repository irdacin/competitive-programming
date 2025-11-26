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

  auto dfs = [&](auto dfs, int u, int par = -1) -> pair<int, int> {
    int mxDist = 0, node = u;
    for(auto v : adj[u]) {
      if(v != par) {
        auto [dist, x] = dfs(dfs, v, u);
        if(mxDist < dist + 1) {
          mxDist = dist + 1;
          node = x;
        }
      }
    }

    return {mxDist, node};
  };

  int farthest = dfs(dfs, 0).second;
  cout << dfs(dfs, farthest).first << '\n';
  
  return 0;
}