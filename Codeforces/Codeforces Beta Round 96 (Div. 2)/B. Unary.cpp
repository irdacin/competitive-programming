#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;
const int mod = 1e6 + 3;

ll power(int a,int k){
    if(k==0) return 1;
    ll hasil = power(a,k/2);
    return k%2 ? (hasil*hasil*a) % mod : (hasil*hasil) % mod;
}

void solve(){
    map <char, string> binary;
    binary['>'] ="1000";
    binary['<'] ="1001";
    binary['+'] ="1010";
    binary['-'] ="1011";
    binary['.'] ="1100";
    binary[','] ="1101";
    binary['['] ="1110";
    binary[']'] ="1111";
    
    string p;
    cin >> p;
    
    string word="";
    for(int i=0;i<p.length();i++){
        for(auto &bin:binary){
            if(bin.first==p[i]) word+=bin.second;
        }
    }    
    
    ll desimal = 0,
    pangkat = 0;
    for(int i=word.length()-1;i>=0;i--){
        if(word[i]=='1') desimal+=power(2,pangkat);
        // desimal%=mod;
        pangkat++;
    }
    cout << desimal%mod;
}

int main(){
    AC;
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}