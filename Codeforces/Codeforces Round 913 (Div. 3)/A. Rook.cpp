#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    char s[2];
    cin>>s[0]>>s[1];
    for(int i=1;i<=8;i++)
    if (i!=s[1]-'0') cout << s[0] << i << endl;
    for(char i='a';i<='h';i++)
    if (i!=s[0]) cout << i << s[1] << endl;
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}