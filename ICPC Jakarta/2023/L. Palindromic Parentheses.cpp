#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
	int n, k; cin>>n >> k;
	if(k<n/2 || k==n){
		cout<<-1;
		return;
	}
	
    if(n%k==0){
        for(int i=0;i<k;i++) cout<< '(';
        for(int i=0;i<n-k;i++) cout<< ')';
        return;
    }

	int butuh = n/2 - n%k;
	if(butuh%2){
	    for(int i=0;i<butuh/2+1;i++) cout<<'('<<')';
	} else {
	    for(int i=0;i<butuh/2;i++) cout<<'('<<')';
	}
	
	for(int i=0;i<n%k;i++) cout<< '(';
	for(int i=0;i<n%k;i++) cout<< ')';
	if(butuh%2){
	    for(int i=0;i<butuh/2;i++) cout<<'('<<')';
	} else {
	    for(int i=0;i<butuh/2;i++) cout<<'('<<')';
	}
}

int main(){
	ez;
	// int t; cin >> t; while(t--)
	solve();
	return 0;
}