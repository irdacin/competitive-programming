#include <bits/stdc++.h>
#define start ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> poin;
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b;
        if(a<=10) poin.push_back(b);
        else poin.push_back(0);
    }

    int max = 0;
    for(int i=0;i<poin.size();i++){
        if(max<poin[i]) max=poin[i];
    }

    for(int i=0;i<poin.size();i++){
        if(max==poin[i]){
            cout << i+1 << endl;
            break;
        }
    }
    
}

int main(){
    start;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}