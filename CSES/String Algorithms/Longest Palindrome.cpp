#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; string s;
    cin >> s;

    // manacher's algorithm

    string str = "|";
    for(auto c:s) str += c, str += '|';

    n = len(str);
    vector<int> palindromeRadius(n);

    int maxLPSLength = 0;
    int start = 0;

    for(int center = 0, radius = 0; center < n;){
        int left = center - radius;
        int right = center + radius;

        for(; left - 1 >= 0 && right + 1 < n && 
            str[left-1] == str[right+1]; left--, right++) radius++;
        
        if(maxLPSLength < radius){ 
            maxLPSLength = radius;
            start = left/2;
        }

        palindromeRadius[center] = radius;

        radius = 0; 


        int oldCenter = center;
        center++;

        for(; center <= right; center++){
            int mirroredCenter = oldCenter - (center - oldCenter);
            palindromeRadius[center] = palindromeRadius[mirroredCenter];

            int maxMirroredRadius = right - center; 

            if(palindromeRadius[mirroredCenter] >= maxMirroredRadius){
                radius = maxMirroredRadius;
                break;
            }
        }
    }

    // cout << maxLPSLength;
    cout << s.substr(start, maxLPSLength);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}