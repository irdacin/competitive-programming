#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for(int u, v, t; m--;) {
    cin >> u >> v >> t;
    u--, v--;
    adj[u].emplace_back(v, t);
  }

  vector<long long> dp(n, -2);
  auto dfs = [&](auto dfs, int u) {
    if(u + 1 == n) return 0LL;

    long long &res = dp[u];
    if(res != -2) return res;

    res = -1;
    for(auto [v, t] : adj[u]) {
      long long nxt = dfs(dfs, v);
      if(nxt != -1)
        res = max(res, nxt + t);
    }

    return res;
  };

  cout << dfs(dfs, 0) << '\n';

  return 0;
}