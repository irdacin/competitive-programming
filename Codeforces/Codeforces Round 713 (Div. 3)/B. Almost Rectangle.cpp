#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin >> n;
    char grid[n][n];
    for(auto &s:grid) for(auto &c:s) cin >> c;

    vector<pair<int,int>>star;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]=='*') star.push_back({i,j});

    auto [x1,y1] = star[0];
    auto [x2,y2] = star[1];

    // row
    if(x1==x2)
        star.push_back({(x1+1)%n,y1}),
        star.push_back({(x2+1)%n,y2});
    // column
    else if(y1==y2)
        star.push_back({x1,(y1+1)%n}),
        star.push_back({x2,(y2+1)%n});
    // diagonal
    else
        star.push_back({x1,y2}),
        star.push_back({x2,y1});

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool flag = false;
            for(auto &[x,y]:star){
                if(i==x && j==y) cout << '*', flag=true;
                if(flag) break;
            }
            if(flag) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve();
}