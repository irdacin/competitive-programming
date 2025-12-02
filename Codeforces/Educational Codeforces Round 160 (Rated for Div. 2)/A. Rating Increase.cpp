#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    string s;
    cin >> s;

    vector<string>num;
    string temp="";
    for(int i=0;i<s.length();i++){
        temp+=s[i];
        if(i!=s.length()-1 && s[i+1]!='0') num.push_back(temp), temp="";
    }
    num.push_back(temp);

    // for(auto &i:num) cout << i << ' ';
    if(num.size()==2){
        if(stoi(num[0])>=stoi(num[1])) cout << -1;
        else cout << num[0] << ' ' << num[1];
    }
    else if(num.size()>2){
        string temp="";
        for(int i=1;i<num.size();i++) temp+=num[i];

        if(stoi(num[0])>=stoi(temp)) cout << -1;
        else cout << num[0] << ' ' << temp;
    }
    else cout << -1;
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve();
}