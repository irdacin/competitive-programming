#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

string swap(char a, char b,char c){
    string res;
    res+=b;
    res+=c;
    res+=a;
    return res;
}

void solve(){
    string str;
    cin >> str;
    if(str=="abc") cout << "YES";
    else if(swap(str[2], str[1], str[0])=="abc") cout << "YES";
    else if(swap(str[1], str[0], str[2])=="abc") cout << "YES";
    else if(swap(str[0], str[2], str[1])=="abc") cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main(){
    AC;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}