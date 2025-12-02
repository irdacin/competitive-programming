#include <bits/stdc++.h>
#define start ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    char game[3][3];
	for(auto &a:game) for(auto &b:a) cin >> b;
	
	char ans='-';
	// horizontal
	for(auto &a:game){
		int countX=0,
		countO=0,
		countPlus=0;
		for(auto &b:a){
			if(b=='X') countX++;
			if(b=='O') countO++;
			if(b=='+') countPlus++;
		}
		if(countX==3) ans='X';
		if(countO==3) ans='O';
		if(countPlus==3) ans='+';
	}

	// vertical
	for(int i=0;i<3;i++){
		int countX=0,
		countO=0,
		countPlus=0;
		for(int j=0;j<3;j++){
			if(game[j][i]=='X') countX++;
			if(game[j][i]=='O') countO++;
			if(game[j][i]=='+') countPlus++;
		}
		if(countX==3) ans='X';
		if(countO==3) ans='O';
		if(countPlus==3) ans='+';
	}

	// diagonal kiri
	int countX=0,
	countO=0,
	countPlus=0;
	for(int i=0;i<3;i++){
		if(game[i][i]=='X') countX++;
		if(game[i][i]=='O') countO++;
		if(game[i][i]=='+') countPlus++;
	}
	if(countX==3) ans='X';
	if(countO==3) ans='O';
	if(countPlus==3) ans='+';
	
	// diagonal kanan
	if(game[0][2]=='X' && game[1][1]=='X' && game[2][0]=='X') ans='X'; 
	else if(game[0][2]=='O' && game[1][1]=='O' && game[2][0]=='O') ans='O'; 
	else if(game[0][2]=='+' && game[1][1]=='+' && game[2][0]=='+') ans='+'; 

	(ans=='X' || ans=='O' || ans=='+') ? cout << ans : cout << "DRAW";
	cout << endl;
}

int main(){
    start;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}