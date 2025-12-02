#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;
const int mod = 256;

int power(int a, int k){
    if(k==0) return 1;
    int hasil = power(a,k/2);
    return k%2 ? hasil*hasil*a : hasil*hasil;
}

int bi_to_dec(string binary){
    int desimal = 0,
    pangkat = 0;
    for(int i=binary.length()-1;i>=0;i--){
        if(binary[i]=='1') desimal+=power(2,pangkat);
        pangkat++;
    }
    return desimal;
}

string dec_to_bi(int desimal){
    if(desimal==1) return "1";
    else if(desimal%2) return dec_to_bi(desimal/2) + "1";
    else return dec_to_bi(desimal/2) + "0";
}

void rev(string &a){
    for(int i=0;i<a.length()/2;i++){
        char temp=a[i];
        a[i]=a[a.length()-i-1];
        a[a.length()-i-1]=temp;
    }
}

void solve(){
    string text;
    getline(cin, text);
    
    int res = 0;
    for(auto &word:text){
        string biner = dec_to_bi(int(word));
        rev(biner); while(biner.length()<8) biner+="0";
        int decimal = bi_to_dec(biner);
        // cout << biner << ' ' << decimal << endl;
        
        int ans = res-decimal;
        if(ans<0) ans+=mod;
        ans%=mod;
        cout << ans << endl;
        res=decimal;
    }
    
}

int main(){
    AC;
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}