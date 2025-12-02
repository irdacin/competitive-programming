#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    int book[3][n];
    for(auto &a:book) for(auto &i:a) cin >> i;

    int knowledge = 0;
    for(auto &a:book){
        for(auto &i:a){
            if((i|x)==x) knowledge|=i;
            else break;
        }
    }
    cout << (knowledge==x ? "Yes":"No");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}