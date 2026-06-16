#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << "NO " << x)
#define len(x) (int) x.size()
using namespace std;

void solve(string s){
    stack<string> st;

    set<char> bracket = {'(', ')', '[', ']', '{', '}', '<', '>'};
    vector<string> soal;

    for(int i=0; i<len(s);i++){
        string tmp = "";

        if(i+1!=len(s) && s[i]=='*' && s[i+1]==')') tmp+="*)", i++;
        
        else if(bracket.find(s[i])!=bracket.end()){
            if(i+1!=len(s) && s[i]=='(' && s[i+1]=='*') tmp+="(*", i++;
            else tmp+=s[i];
        }

        soal.push_back(tmp);
    }

    set<string> open = {"(", "[", "{", "<", "(*"};
    set<string> close = {")", "]", "}", ">", "*)"};

    for(int i=0; i<len(soal); i++){
        // cout << i+1 << ' ' << soal[i] << endl;

        if(open.find(soal[i])!=open.end()) st.push(soal[i]);

        if(close.find(soal[i])!=close.end()){
            if(st.empty()) exit(i+1);

            string cur = st.top();

            int x=0, y=0;
            for(auto c:open){
                if(c==cur) break;
                x++;
            }
            for(auto c:close){
                if(c==soal[i]) break;
                y++;
            }

            if(x!=y) exit(i+1);
            
            st.pop();

        }
        
    }

    if(!st.empty()) exit(len(soal)+1);

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(string s; getline(cin, s);)
    solve(s), cout << endl;
}