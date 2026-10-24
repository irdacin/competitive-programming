#include <iostream>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
	string s;
	while(cin>>s){
	int count=0;
	// selection sort
	for(int i=0;i<s.length()-1;i++){
		int min_idx=i;
		for(int j=i+1;j<s.length();j++)
			if(s[j]<s[min_idx]) min_idx=j;
	    if(min_idx!=i) {
	    	char temp=s[i];
	    	s[i]=s[min_idx];
	    	s[min_idx]=temp;
	    	count++;
	    }
	}
	cout << count << endl;
	}
}

int main(){
    ez;
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}