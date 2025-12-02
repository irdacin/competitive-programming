#include <bits/stdc++.h>
#define start ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b>=10 || a+c>=10 || b+c>=10) cout << "Yes";
    else cout << "NO";
    cout << endl;
}

int main(){
    start;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}