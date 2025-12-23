#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(auto &row:a) for(auto &c:row) cin >> c;

    pair<int,int> dir[2] = {{0,1},{1,0}};
    auto valid = [&](int row, int col){
        return row>=0 && row<h && col>=0 && col<w;
    };

    set<int> st = {a[0][0]};
    function<int(int, int)> func = [&](int row, int col) -> int{
        if(row==h-1 && col==w-1) return 1;

        int res = 0;
        for(auto [x, y]:dir){
            x+=row, y+=col;
            if(valid(x,y) && st.find(a[x][y])==st.end()){
                st.insert(a[x][y]);
                res+=func(x,y);
                st.erase(a[x][y]);
            }
        }

        return res;
    };

    cout << func(0,0);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}