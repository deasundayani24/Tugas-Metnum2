/* Nama  : Dhea Sundayani (3411151003)
           Nurul Af'idah  (3411151008)
   Kelas : SIE-A
   Tugas Metode Numerik
*/
   
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define nmax 100

int main(){
	
//kamus data
int a, jarak;
int x[nmax+1];
int y[nmax+1];
float pre[nmax+1], error[nmax+1];
float m, c, fx, err;
int totx, toty, toterror=0, totxy=0, totxkuadrat=0, totykuadrat=0, totkuadratx;
int n, i;
int kuadratx[nmax+1], kuadraty[nmax+1], xy[nmax+1];

//algoritma
printf("\n===============SELAMAT DATANG DI TUGAS METODE NUMERIK===============");
printf("\n\n Dhea Sundayani - 3411151003");
printf("\n Nurul Af'Idah  - 3411151008");
printf("\n\n===============SELAMAT DATANG DI TUGAS METODE NUMERIK===============");
printf ("\n\nMasukkan Jumlah Data yang Diinputkan : "); scanf ("%d", &n);
printf ("\n\n");

//nilai x
for(i=1;i<=n;i++){
	printf ("Masukkan nilai x : ");scanf("%d", &a);
	x[i]=a;
	kuadratx[i]=pow(x[i], 2);
    totx=totx + x[i];
    totxkuadrat=totxkuadrat + kuadratx[i];
} 

//nilai y
for (i=1;i<=n;i++){
	printf("Masukkan nilai y : "); scanf("%d", &a);
	y[i]=a;
	toty = toty + y[i];
    kuadraty[i]=pow(y[i], 2);
    totykuadrat=totykuadrat + kuadraty[i];
    xy[i]=x[i]*y[i];
    totxy = totxy + xy[i];
}

//menghitung m
m=((n*totxy)-(totx*toty)) / ((n*totxkuadrat)-pow(totx, 2));
  printf("\nNilai m = %.2f \n", m);
  
//menghitung c
c=((toty*totxkuadrat)-(totx*totxy)) / ((n*totxkuadrat)-pow(totx, 2));
printf("\nNilai c = %.2f \n", c);
  
//menghitung prediksi
for (i=1; i<=n;i++){
    pre[i]=(m*x[i])+c;
    printf ("\nNilai Prediksi jika f[%d] = %.2f \n", x[i], pre[i]);
}
  
//menghitung error
for (i=1; i<=n;i++){
	error[i]=y[i]-pre[i];
   	if (error[i]<0){
          error[i]=pre[i]-y[i];
	}
   	toterror=toterror + error[i];
   	err=toterror/n;
}
   
//tampil error tiap prediksi
printf ("\n================================================");
printf ("\n========= SELISIH WAKTU (ERROR) ===============\n");
for (i=1; i<=n;i++){
    printf ("\nSelisih Waktu jika f(x)=%.2f yaitu %.2f \n", pre[i], error[i]);
}

//tampil nilai error keseluruhan
printf ("\n=========================");
// printf ("\nNilai Sigma error = %f \n ", sigmaerror);
printf ("\n====== ERROR ======\n");
printf ("\nMaka nilai error sebesar %.2f \n ", err);
   
  return 0;
}
