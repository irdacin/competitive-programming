#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;
const int mod = 256;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;
    int ganjil=0;
    for(auto &i:a) 
        if(i%2) ganjil++;
    ganjil%2==0 ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main(){
    AC;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}