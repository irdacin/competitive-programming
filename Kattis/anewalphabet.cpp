#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    map<char,string>mp ={
        {'a',"@"},
        {'b',"8"},
        {'c',"("},
        {'d',"|)"},
        {'e',"3"},
        {'f',"#"},
        {'g',"6"},
        {'h',"[-]"},
        {'i',"|"},
        {'j',"_|"},
        {'k',"|<"},
        {'l',"1"},
        {'m',"[]\\/[]"},
        {'n',"[]\\[]"},
        {'o',"0"},
        {'p',"|D"},
        {'q',"(,)"},
        {'r',"|Z"},
        {'s',"$"},
        {'t',"']['"},
        {'u',"|_|"},
        {'v',"\\/"},
        {'w',"\\/\\/"},
        {'x',"}{"},
        {'y',"`/"},
        {'z',"2"},
    };

    char c;
    while(cin.get(c)){
        c = tolower(c);
        if(mp.find(c)==mp.end()) cout << c;
        else cout << mp[c];
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}