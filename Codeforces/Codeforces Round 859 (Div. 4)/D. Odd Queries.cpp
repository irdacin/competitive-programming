#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int t;
    cin >> t;
 
    while(t--){
        int n, q;
        cin >> n >> q;
 
        vector <int> a(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        
        vector <int> cb {0};
        for(int i=0;i<n;i++){
            int temp = cb[i] + a[i];
            cb.push_back(temp);
        }
        
        int l, r, k;
        while(q--){
            cin >> l >> r >> k;
            int guna = (r-l+1)*k;
            int ga_guna = cb[r] - cb[l-1];
            int jumlah = sum - ga_guna + guna;
            // cout << jumlah;
            if(jumlah%2) cout << "Yes";
            else cout << "No";
            cout << endl;
        }
    }
    return 0;
}