#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;
typedef pair<int,int> pii;

void solve(){
    // dijkstra's algorithm
    
    int n; cin >> n;
    vector<vector<pii>> graph(n);
    
    for(int i=0;i<n-1;i++){
        int a, b, x;
        cin >> a >> b >> x;
        graph[i].push_back(make_pair(i+1, a));
        graph[i].push_back(make_pair(x-1, b));
    }

    // for(int i=0;i<n-1;i++){ 
    //     cout << "vertex : " << i << endl;
    //     for(auto [key, value]:graph[i]) cout << key << ' '  << value << endl;
    //     cout << endl;
    // } cout << endl;

    vector<int>distance(n, LLONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        auto [dist_u, u] = pq.top();
        pq.pop();
        
        // cout << u << ' ' << dist_u << endl;

        if(dist_u > distance[u]) continue;

        for(auto &neighbor:graph[u]){
            auto [v, cost] = neighbor;
            // cout << v<<"-->"<<u <<' '<< distance[u] << ' '<< distance[v]<< endl;
            if(distance[u] + cost < distance[v]){
                distance[v] = distance[u]+cost;
                pq.push({distance[v], v});
            }
        }
    }

    // for(auto &d:distance) cout << d << ' ';
    cout << distance[n-1];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}