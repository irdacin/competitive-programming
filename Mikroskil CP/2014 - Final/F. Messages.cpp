#include <iostream>
#include <vector>
#include <string>
using namespace std;

string repeat(string a,int n){
    string ulang = "";
    for(int i=0;i<n;i++){
        ulang+=a;
    }
    return ulang;
}

int main(){
    vector <string> keypad(10);
    keypad[1] = ".,?!1";
    keypad[2] = "abc2";
    keypad[3] = "def3";
    keypad[4] = "ghi4";
    keypad[5] = "jkl5";
    keypad[6] = "mno6";
    keypad[7] = "pqrs7";
    keypad[8] = "tuv8";
    keypad[9] = "wxyz9";
    keypad[0] = " ";
    
    char pesan;
    bool kecil = true, besar = false;
	string ans ="";
    while(cin.get(pesan)){
        if(pesan=='\n') ans+="#";
        else{
            if(pesan>='A' && pesan<='Z' && !besar){
                ans+="*";
                kecil = false;
                besar = true;
            }
            else if(pesan>='a' && pesan<='z' && !kecil){
                ans+="*";
                kecil = true;
                besar = false;
            }
        
			pesan = tolower(pesan);
            for(int i=0;i<keypad.size();i++){
                for(int j=0;j<keypad[i].length();j++){
                    if(pesan == keypad[i][j]){
                        ans+=repeat(to_string(i),j+1);
                        break;
                    }
                }
            }
        }
        ans+=" ";
    }
	cout << ans;
    return 0;
}