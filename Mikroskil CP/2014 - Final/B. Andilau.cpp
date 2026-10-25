#include <cstdio>

int main(){
	double n;
	scanf("%lf", &n);

    /*  
    soal : sigma i=2 sampai n  sigma j=1 sampai i-1  (j/i)
    // sigma j=1 sampai i-1 (j/i) : jika j=1 -> 1/i
                                    jika j=2 -> 2/i
                                    jika j=3 -> 3/i
                                    dst
                                    jika j=i-2 -> (i-2)/i
                                    jika j=i-1 -> (i-1)/i
        jadi, 1/i + 2/i + 3/i + ... + (i-2)/i + (i-1)/i
        // nah kita bisa pakai rumus deret aritmatika Sn = n/2 * (a+Un) 
        dengan n adalah byk suku, a adalah suku pertama dan Un adalah suku terakhir
       berarti banyak sukunnya ... (belum kita cari hehe), suku pertamanya 1, suku terakhirnya (i-1)/i
       
       // kita cari banyak sukunya menggunakan rumus barisan aritmatika 
       Un = a + (n-1)*b dengan b adalah beda suku kedua dengan pertama berarti b = 2 - 1 = 1
       # rumus --> Un = a + (n-1)*b
       (i-1)/i = 1 + (n-1) * 1
       (i-1)/i = 1+ n - 1
       n = (i-1)/i
        jadi, banyak sukunya barisan tersebut (i-1)/i tinggal masukin rumus deh
        # rumus --> Sn = n/2 * (a+Un)
        Sn = ((i-1)/i) / 2 * (1+i-1)
           = (i-1) / i / 2 * i  # i nya bisa dicoret
           = (i-1) / 2
        sehingga, 
        sigma j=1 sampai i-1 (j/i) = (i-1) / 2
                                   
    sehingga, soal diatas menjadi
    sigma i=2 sampai n ((i-1)/2) 
    // jika i=2 -> 1/2
       jika i=3 -> 2/2
       jika i=4 -> 3/2
       dst
       jika i=n -> (n-1)/2
    jadi pesoalan diatas, 1/2 + 2/2 + 3/2 + ... + (n-1)/2
    // nah kita bisa pakai rumus deret aritmatika yang tadi Sn = n/2 * (a+Un)
    berarti byk sukunya ...(kita cari dibawah), suku pertamanya 1/2 dan suku terakhirnya (n-1)/2
    
    // kita cari byk sukunya terlebih dahulu pake rumus yg tadi Un = a + (n-1)*b berarti b = 2/2 - 1/2 = 1/2
    //// trigered!! kita ganti variabel n yg dirumus menjadi byk ////
    # rumus --> Un = a + (byk-1)*b
    (n-1)/2 = 1/2 + (byk-1)*1/2
    (n-1)/2 = (1 + byk-1) / 2  # 'per 2' nya bisa kita coret
    n - 1 = byk
    sehingga, byk sukunya = n-1 langsung kita bisa cari jumlah deretnya
    
    # rumus --> Sn = byk/2 * (a+Un)
    sehingga, 
    Sn = (n-1)/2 * (1/2 + ((n-1)/2))
       = (n-1)/2 * (1+n-1)/2 
       = (n-1)/2 * n/2
       
    FINALLY, rumus sigma itu adalahhhhh (n-1)/2 * n/2
    */
    
   double rumus = (n-1)/2 * n/2;
	printf("%.2lf\n",rumus);
	return 0;
}