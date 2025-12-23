#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> friends(n);
    for(int a, b; m--;){
        cin >> a >> b;
        a--, b--;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    vector<bool> vis(n, false);

    int ans = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            int res = 0, edges = 0;
            auto func = [&](auto func, int user) -> void{ 
                vis[user] = true;
                res++;
                edges += len(friends[user]);

                for(auto next:friends[user]){
                    if(!vis[next]){
                        func(func, next);
                    }
                } 
            };

            func(func, i);
            // cout << res << ' ' << edges << endl;

            ans += res*(res-1)/2 - edges/2;
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}