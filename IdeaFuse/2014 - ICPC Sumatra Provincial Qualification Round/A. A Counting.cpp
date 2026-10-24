#include <iostream>
using namespace std;

int main(){
    unsigned long long t;
    cin >> t;
    for(int i=0;i<t;i++){
        unsigned long long mimik,kikil;
        cin >> mimik >> kikil;
        
        // cara ini tle
        // while(mimik!=kikil){
        //     mimik+=7;kikil-=5;
        //     if(mimik>kikil){
        //         beda = true;
        //         break;
        //     }
        // }
        
        /* kita coba pake cara yg lbh efisien
        100 kalo ditambah menjadi 625 itu harus ada 525 berarti harus looping sebanyak 75 kali
        1000 kalo dikurang menjadi 625 itu harus ada 375 berarti harus looping sebanyak 75 kali
        
        daripada looping lbh baik pake perkalian
        jadi 
        mimik = 100 + 7*75 = 625
        kikil = 1000 - 5*75 = 625
        
        sekarang tinggal bagaimana mencari 75
        kalo dikurang 1000-100 = 900
        wait 900/12 = 75 wow is this rumus?
        
        tapi kalo 1001
        1001-100 = 901
        901/12 = 75 (kalo kita pake unsigned long long)
        berarti kita harus cari habis bagi
        jika bisa dibagi baru kita masukin rumus jika tidak ya imposible
        
        tinggal mau pake yg mana ni mimik atau kikil?
        terserah si wkwk kita coba ya
        */
        
        // // yey AC pake mimik
        // unsigned long long ans = mimik + 7 * (kikil-mimik)/12;
        
        // sekarang kikil
        unsigned long long ans = kikil - 5 * (kikil-mimik)/12;
        
        cout << "Case #" << i+1 << ": "<< ((kikil-mimik)%12 ? "impossible" : to_string(ans)) << endl;
        // kenapa aku buat string? karna muncul error katanya ga bisa 1 string 1 integer maklum c++ :)
    }
    return 0;
}