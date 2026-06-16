#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(int n){
    cout << "Original number was " << n << endl;

    set<int> st;
    int chain = 1;
    for(;;chain++){
        string a = to_string(n);
        string b = to_string(n);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<char>());

        int value1 = stoll(a);
        int value2 = stoll(b);

        n = value2 - value1;
        cout << value2 << " - " << value1 << " = " << n << endl;

        if(st.find(n)!=st.end()) break;
        st.insert(n);
    }

    cout << "Chain length " << chain << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(int n; cin >> n;){
        if(n==0) break;
        solve(n), cout << endl;
    }
}