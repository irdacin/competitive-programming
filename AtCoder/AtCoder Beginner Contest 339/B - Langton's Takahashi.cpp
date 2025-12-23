#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>>grid(h,vector<char>(w,'.'));

    function<void(int,int,int,char)> func = [&](int i, int j, int cnt, char arah){
        if(cnt==n) return;

        if(grid[i][j]=='.'){
            grid[i][j] = '#';
            if(arah=='t') func(i, j+1==w ? 0:j+1, cnt+1,'r');
            else if(arah=='r') func(i+1==h ? 0:i+1, j, cnt+1, 'd');
            else if(arah=='d') func(i, j-1==-1 ? w-1:j-1, cnt+1, 'l');
            else func(i-1==-1 ? h-1:i-1,j, cnt+1, 't');
        } else {
            grid[i][j] = '.';
            if(arah=='t') func(i, j-1==-1 ? w-1:j-1, cnt+1, 'l');
            else if(arah=='r') func(i-1==-1 ? h-1:i-1,j, cnt+1, 't');
            else if(arah=='d') func(i, j+1==w ? 0:j+1, cnt+1,'r');
            else func(i+1==h ? 0:i+1, j, cnt+1, 'd');
        }
    };

    // t => top
    // r => right
    // d => down
    // l => left 

    func(0,0,0,'t'); 
    for(auto &i:grid) {for(auto &j:i) cout << j; cout << endl;}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}