#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    pair<int,int> points[n];
    for(auto &[x,y]:points) cin >> x >> y;

    for(auto [x,y]:points){
        int ans = n;
        int id = 1;
        double mx = INT_MIN;
        for(auto [i,j]:points){
            if(x==i && y==j);
            else {
                double dis = sqrt((x-i)*(x-i) + (y-j)*(y-j));
                if(dis > mx) mx = dis, ans = id;
            }

            id++;
        }

        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}