#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int a[9][9];
    for(auto &i:a) for(auto &j:i) cin >> j;

    // row
    int cnt=0;
    for(int i=0;i<9;i++){
        set<int>num;
        for(int j=0;j<9;j++) num.insert(a[i][j]);
        if(num.size()!=9) exit("No");
    }

    // col
    for(int i=0;i<9;i++){
        set<int>num;
        for(int j=0;j<9;j++) num.insert(a[j][i]);
        if(num.size()!=9) exit("No");
    }


    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            set<int>num;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++) num.insert(a[k][l]);
            }
            if(num.size()!=9) exit("No");
            // for(auto &n:num) cout << n << ' ';
            // cout << endl;
        }
    }
    cout << "Yes";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}