#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;

    // manacher's algorithm

    // preprocess stringnya agar len dari string selalu ganjil yaitu tepat 2*n+1
    string str = "|";
    for(auto c:s) str += c, str += '|';

    n = len(str);
    vector<int> palindromeRadius(n);

    int maxLPSLength = 0;

    for(int center = 0, radius = 0; center < n;){
        // get left dan right border dari string yang sudah pasti palindrom
        int left = center - radius;
        int right = center + radius;

        // expand left sama right selama masih ada palindrom di center ini
        for(; left - 1 >= 0 && right + 1 < n && 
            str[left-1] == str[right+1]; left--, right++) radius++;
        
        if(maxLPSLength < radius){ // track maxLPSLength
            maxLPSLength = radius;
        }

        // store the radius
        palindromeRadius[center] = radius;

        radius = 0; // reset radius jadi 0 karena ga pake lagi

        // sampe sini, sudah dihitung value dari left border [left, center]
        // berarti value dari right border [center+1, right] akan sama dengan mirrornya, tapi ...

        int oldCenter = center;
        center++;

        for(; center <= right; center++){
            int mirroredCenter = oldCenter - (center - oldCenter);
            palindromeRadius[center] = palindromeRadius[mirroredCenter];

            int maxMirroredRadius = right - center; // dari ujung right border ke center

            // ... jika palindrom yang di mirror itu lebih besar dari maximum mirrored radiusnya
            if(palindromeRadius[mirroredCenter] >= maxMirroredRadius){
                // bisa jadi center saat ini bisa menghasilkan radius lebih besar (belum tentu)
                // jadi harus dicari ulang untuk memastikan
                radius = maxMirroredRadius;
                break;
            }
        }
    }

    cout << maxLPSLength;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}