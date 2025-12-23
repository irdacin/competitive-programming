#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    stack<int> st;
    for(auto i:a){
        if(st.empty()){
            st.push(i);
            continue;
        }
        if(i==st.top()){
            while(!st.empty() && i==st.top()){
                st.pop();
                i++;
            }
            
        } 
        st.push(i);
    }

    // while(!st.empty()) cout << st.top() << endl, st.pop();
    cout << len(st);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}