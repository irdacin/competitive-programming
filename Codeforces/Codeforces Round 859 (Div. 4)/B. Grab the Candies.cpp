#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        int a;
        int mihai=0, bianca=0;
        for(int i=0;i<n;i++){
            cin >> a;
            if(a%2) bianca+=a;
            else mihai+=a;
        }
        string result = mihai > bianca ? "Yes" : "No";
        cout << result << endl;
    }
    return 0;
}