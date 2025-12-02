#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    pb--, ps--;

    int p[n], a[n];
    for(auto &i:p) cin >> i, i--;
    for(auto &i:a) cin >> i;

    auto getScore = [&](int pos){
        int score = 0, res = 0;
        vector<bool> vis(n, false);
        for(int i=k; i-->0 && !vis[pos]; ){
            vis[pos] = true;
            res = max(res, score+a[pos]*(i+1));
            score+=a[pos];
            pos = p[pos];
        }
        return res;
    };

    int bodya = getScore(pb);
    int sasha = getScore(ps);
    // cout << bodya << ' ' << sasha;

    if(bodya > sasha) cout << "Bodya";
    else if(bodya < sasha) cout << "Sasha";
    else cout << "Draw";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}