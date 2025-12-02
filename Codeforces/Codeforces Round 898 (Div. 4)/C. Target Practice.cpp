#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    char grid[10][10];
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) 
    cin >> grid[i][j];
    
    int ans=0;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++)
    
    if(grid[i][j]=='X') ans += min(min(i,9-i),min(j,9-j))+1;
    cout << ans << endl;
}

int main(){
    AC;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}