#include <iostream>
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ll long long
using namespace std;

int main(){
    ios
    int t; cin >> t; 
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        
        int max = 0, count=0;
        for(auto& a:arr){
            if(a==1) max=max<count?count:max,count=0;
            else count++;
        }
        max = max<count ? count:max;
        cout << max << endl;
    }
    return 0;
}