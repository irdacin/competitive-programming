#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    /*
    n = 3:
    169
    196
    961

    n is always odd
    so if n = 5
    16900
    19600
    96100 
    10609
    90601

    n = 7
    1690000
    1960000
    9610000
    1060900
    9060100
    1006009
    9006001
    
    */
    // base case
    if(n==1) return void(cout << 1 << endl);

    auto reptZero=[](int times){
        string res="";
        while(times--) res+='0';
        return res;
    };

    vector<string>ans={"169","196","961"};
    
    for(int k=1;k*2<=n-3;k++){
        string temp="";
        for(int i=0;i<3;i+=2){
            temp+=ans[i][0];
            temp+=reptZero(k);
            temp+=ans[i][1];
            temp+=reptZero(k);
            temp+=ans[i][2];
            temp+=reptZero(n-3-k-k);
            ans.push_back(temp);
            temp="";
        }
    }

    for(int i=0;i<3;i++) ans[i]+=reptZero(n-3);

    for(auto &i:ans) cout << i << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve();
}