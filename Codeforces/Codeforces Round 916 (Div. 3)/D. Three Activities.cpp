#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    pair<int,int> a[n], b[n], c[n];
    
    int i;
    i=1; for(auto &[day,friends]:a) day=i++, cin >> friends;
    i=1; for(auto &[day,friends]:b) day=i++, cin >> friends;
    i=1; for(auto &[day,friends]:c) day=i++, cin >> friends;

    auto sortFriends = [](const auto a, const auto b){
        return a.second > b.second;
    };

    sort(a,a+n, sortFriends);
    sort(b,b+n, sortFriends);
    sort(c,c+n, sortFriends);

    int ans=0;
    for(int i=0;i<3;i++){
        auto [dayA, friendsA] = a[i];
        for(int j=0;j<3;j++){
            auto [dayB, friendsB] = b[j];
            if(dayA==dayB) continue;

            for(int k=0;k<3;k++){
                auto [dayC, friendsC] = c[k];
                if(dayA==dayC || dayB==dayC) continue;

                ans = max(ans, friendsA+friendsB+friendsC);
            }
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}