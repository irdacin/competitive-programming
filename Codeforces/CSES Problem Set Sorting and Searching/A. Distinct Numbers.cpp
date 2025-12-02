#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    set<int>x;
    for(int i=0;i<n;i++){
        int temp; cin >> temp;
        x.insert(temp);
    }
    // int ans=0;
    // for(auto a:num) 
    // cout << a.first << ' ' << a.second << endl; 
    // if(a.second>1) ans++;
    
    cout << x.size() << endl;    
}

int main(){
    ez;
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}