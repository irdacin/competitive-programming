#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(string a, string b){
    // 45 * 32
    /*
    45
    32 x
    ----

    step 1 : 2*5 = 10 simpan 1 tulis 0
    step 2 : 3*5 = 15 tambah simpan 1 = 16

    45
    32 x
    ----
    160
    
    step 3 : 4*2 = 8 tulis 8
    step 4 : 4*3 = 12 tulis 12

     45
     32 x
    -----
     160
    1280 +  --> add zero at back to simplify calculation
    -----
    
    step 5 : 0 + 0 = 0 tulis 0
    step 6 : 6 + 8 = 14 tulis 4 simpan 1
    step 7 : 1 + 2 = 2 tambah simpan 1 = 3
    step 8 : 1 tulis 1

     45
     32 x
    -----
     160
    128  +
    -----
    1440

    */

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result = "";
    for(string zero=""; auto digit1:a){
        
        // a = 45
        // first iteration take 5
        int num1 = digit1 - '0';

        int carry = 0;
        string current = "";
        for(auto digit2:b){

            // b = 32
            // first iteration take 2
            int num2 = digit2 - '0';

            // 5*2 = 10
            int res = num1 * num2;    
            // write 0 and save the carry 1

            res += carry; // add previous carry

            carry = res / 10;
            res %= 10;

            current += to_string(res);
        }
        current = zero + current + to_string(carry);
        // cout << current << endl;

        // add two number

        // 061    --> add 0 at back
        // 0821 + 
        // ------
        
        while(len(result) != len(current)){
            if(len(result) < len(current)) result += "0";
            else current += "0";
        }

        carry = 0;
        for(int i=0; i<len(result); i++){
            int num1 = result[i] - '0';
            int num2 = current[i] - '0';

            int res = num1 + num2;

            res += carry;

            carry = res / 10;
            res %= 10;

            result[i] = res + '0';
        }
        result += to_string(carry);
        
        while(result.back()=='0') result.pop_back();
        // cout << result << endl;

        zero += "0";
    } 

    reverse(result.begin(), result.end());
    cout << (result=="" ? "0":result);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(string a, b; cin >> a >> b;)
    solve(a, b), cout << endl;
}