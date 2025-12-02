#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int a[4];
    for(auto &i:a) cin >> i;
    
    map<int,vector<int>>check[4];

    auto beautiful = [&](){
        check[0][0] = {1,2};
        check[0][1] = {3};
        check[0][2] = {3};

        check[1][0] = {2};
        check[1][1] = {0,3};
        check[1][3] = {2};
        
        check[2][1] = {0};
        check[2][2] = {0};
        check[2][3] = {1,2};

        check[3][0] = {1};
        check[3][2] = {0,3};
        check[3][3] = {1};

        for(auto &mp:check){
            int cnt=0;
            for(auto &[idx,vec]:mp){
                for(auto &i:vec){
                    if(a[idx]<a[i]) cnt++;
                }
            }
            if(cnt==4) return true;
        }
        return false;
    };

    if(beautiful()) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}