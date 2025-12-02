#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    (n%3) ? cout << "First" : cout << "Second";
    cout << endl;  
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}