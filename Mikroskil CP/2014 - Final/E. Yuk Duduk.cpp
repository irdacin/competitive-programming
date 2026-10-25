#include <iostream>
using namespace std;

int main() {
    short n;
    cin >> n;
    
    string org[n];
    for(int i=0;i<n;i++){
        cin >> org[i];
    }
    
    /*
    Nama    Index di array   Seharusnya      
    Bapak  --> 0                1       (dikurangi 1)  0
    Abang  --> 1                3       (karena array) 2
    Adik   --> 2                5       (mulai dari 0) 4
    Kakak  --> 3                4                      3
    Ibu    --> 4                2                      1
    berarti logikanya dia ambil awal dulu baru ambil yang paling terakhir baru ambil yg kedua lalu ambil yg kedua terakhir lalu sisanya
    */
    
    // looping sampai n/2 saja karena kita ambil yang awal dan yang akhir bersamaan
    int t = n; //  buat variabel baru yang sama dengan n agar bisa ambil index terakhir
    for(int i=0;i*2<n;i++){
        // ambil yang awal
        cout << org[i] << endl;
        
        // karena di c++, ganjil jika dibagi 2 hasilnya floor maka variabel yang terakhir akan terambil juga jadi...
        if(n%2 && i==n/2) break;
        else{
            // ambil yang akhir
            cout << org[t-1] << endl;
            t--;
        }
    }
    return 0;
}