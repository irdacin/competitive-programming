#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string c; cin>>c;
    int countB=0;
    for(auto &i:c) if(i=='B') countB++;

    if(countB==k) cout << 0 << endl;
    else if(countB<k) {
        cout << 1 << endl;

        int ans=0, cnt=0;
        for(auto &i:c) {
            if(i=='A') cnt++;
            if(cnt==k-countB) break;
            ans++;
        }

        cout << ++ans << " B" << endl;
    }
    else{
        cout << 1 << endl;
        
        int countA=0;
        for(auto &i:c) if(i=='A') countA++;


        int ans=0, cnt=0;
        for(auto &i:c) {
            if(i=='B') cnt++;
            if(cnt==countB-k) break;
            ans++;
        }

        cout << ++ans << " A" << endl;
        
    }
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}