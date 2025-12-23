#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    string a[n];
    for(auto &s:a) cin >> s;

    pair<int,int>dir[8] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

    string ans="";
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    function<void(int,int,string, int)>dfs = [&](int r, int c, string cur, int cnt){
        if(cnt==8){
            return;
        }

        cur+=a[r][c];
        if(cur.length()==n){
            // cout << cur << endl;
            ans = max(ans, cur);
            dfs(r, c, "", cnt+1);
            return;
        }

        auto &[dx,dy] = dir[cnt];
        int row=r+dx, col=c+dy;
        row+=n, row%=n;
        col+=n, col%=n;

        dfs(row,col, cur, cnt);

        // for(auto &[dx,dy]:dir){
        //     int row=r+dx, col=c+dy;
        //     row+=n, row%=n;
        //     col+=n, col%=n;
            
        //     if(vis[row][col]) continue;
        //     vis[row][col] = true;
        //     dfs(row,col, cur);
        //     vis[row][col] = false;
        // }

    };

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            vis[r][c]=true;
            dfs(r,c, "", 0);
            vis[r][c]=false;
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