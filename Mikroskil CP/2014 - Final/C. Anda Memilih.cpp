#include <cstdio>

int main() {
    double n, k, ki;
    scanf("%lf %lf", &n, &k);
    
    // ga tau fungsi input utk apa :) canda tlx
    for(double i=0;i<k;i++) scanf("%lf", &ki);
    
    /* 
    rumus peluang = n(a) / n(s)
    // mencari peluang pas oski
    untuk n(a) (disebut juga banyak kejadian)
    kita mencari jumlah kandidat yang pas oski sukai
    karena pas oski ga suka k orang maka jumlah kandidat yg disukainya =  n- k - 1 (dikurang 1 karena dikurangi sama dirinya)

    untuk ruang sampelnya atau n(s)
    kita cari banyak cara memilih 2 org dari n org
    untuk mencarinya, kita bisa menggunakan permutasi karena tidak diperhatikan ututannya
    P(n,2) = n! / ((n-2)!)
           = n*(n-1)*(n-2)! / (n-2)!   # (n-2)! bisa dicoret
           = n*(n-1)
    
    jadi peluang pas oski = (n-k-1) / n*(n-1)
    */
    
    double nA, nS, peluang; 
    nA = n-k-1;
    nS = n*(n-1);
    
    peluang = nA / nS;
    printf("%.5lf", peluang);
    return 0;
}