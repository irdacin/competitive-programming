#include <iostream>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ll long long
using namespace std;
 
int main(){
    ez int t; cin >> t;
    while(t--){
		int n,m;
		cin >> n >> m;
 
		int a[n], b[m];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		
		ll tsoundu = 0, tenzing = 0;
		for(int i=0;i<n;i++) tsoundu+=a[i];
		for(int i=0;i<m;i++) tenzing+=b[i];
		
		(tsoundu>tenzing) ? cout << "Tsondu" : (tsoundu<tenzing) ? cout << "Tenzing" : cout << "Draw"; 
		cout << endl;
	}
    return 0;
}