#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; 
    getline(cin, s);

    deque<char> ans;
    bool flag = true;
    string tmp = "";
    for(auto ch:s){
        if(ch==']'){
            flag = true;

            reverse(tmp.begin(), tmp.end());
            for(auto c:tmp) ans.push_front(c);

            tmp="";
        }
        else if(ch=='['){
            flag = false;

            reverse(tmp.begin(), tmp.end());
            for(auto c:tmp) ans.push_front(c);

            tmp="";
        }
        else if(ch=='<' && !flag && !tmp.empty()) tmp.pop_back();
        else if(ch=='<' && flag && !ans.empty()) ans.pop_back();
        else if(ch=='<');

        else if(flag){
            
            ans.push_back(ch);

            // tmp = "";
        }
        else {
            tmp+=ch;
        }
        
    }

    reverse(tmp.begin(), tmp.end());
    for(auto c:tmp) ans.push_front(c);
    
    for(auto c:ans) cout << c;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; 
    cin.ignore();
    while(t--)
    solve(), cout << endl;
}