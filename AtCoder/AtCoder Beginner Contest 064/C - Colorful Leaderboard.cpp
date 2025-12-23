#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){    
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;
    
    auto getColor = [](int rating){
        if(rating<400) return "gray";
        else if(rating<800) return "brown";
        else if(rating<1200) return "green";
        else if(rating<1600) return "blue";
        else if(rating<2000) return "cyan";
        else if(rating<2400) return "yellow";
        else if(rating<2800) return "orange";
        else if(rating<3200) return "red";
        else return "free";
    };

    map<string,int>mp;
    for(auto &i:a) mp[getColor(i)]++;
    int mn=mp.size(), mx=mp.size();
    if(mp.find("free")!=mp.end()) mn--, mx--, mx+=mp["free"];
    // if(mx>9) mx=9;
    if(mn<1) mn=1;
    cout << mn << ' ' << mx;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}