#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Tumay Isildak
//20360859071
/*
0=tas='t'
1=Kagit='k'
2=Makas='m'
*/
int karsilastir(char kullanici, int bilgisayar){
    if(kullanici=='t' && bilgisayar==0)
        return 0;
    if(kullanici=='k' && bilgisayar==1)
        return 0;
    if(kullanici=='m' && bilgisayar==2)
        return 0;
    if(kullanici=='t' && bilgisayar==2)
        return 1;
    if(kullanici=='k' && bilgisayar==0)
        return 1;
    if(kullanici=='m' && bilgisayar==1)
        return 1;
    if(kullanici=='t' && bilgisayar==1)
        return 2;
    if(kullanici=='k' && bilgisayar==2)
        return 2;
    if(kullanici=='m' && bilgisayar==0)
        return 2;
}


int main()
{   printf("Tas-Kagit-Makas Oyna\n\n");

    int bilgisayar_dizi[3]={0,1,2};
    char kullanici_dizi[3]={'t','k','m'};
    int kullanici_puani=0, bilgisayar_puani=0;
    int bilgisayar_secimi;
    int kullanici_secimi;
    int kullanici_index=0,bilgisayar_index=0;
    int dizi_oyuncu[100];
    int dizi_pc[100];
    int sayac=0;

    while(1){

        printf("Yapmak istediginizi seciniz:Tas:0 Kagit:1 Makas:2\n");
        scanf("%d",&kullanici_secimi);
        srand(time(0));
        bilgisayar_secimi=rand()%3;
        dizi_pc[bilgisayar_index++]=bilgisayar_dizi[bilgisayar_secimi];
        dizi_oyuncu[kullanici_index++]=kullanici_secimi;

        int sonuc=karsilastir(kullanici_dizi[kullanici_secimi],bilgisayar_dizi[bilgisayar_secimi]);
        if(kullanici_secimi==0 || kullanici_secimi==1 || kullanici_secimi==2){
            if (sonuc==2){
                bilgisayar_puani++;
                printf("Kaybettiniz!\n------------------------------------------------\n");
                printf("Skor: Kullanici %d - %d Bilgisayar\n\n",kullanici_puani, bilgisayar_puani);}
            else if (sonuc==1){
                kullanici_puani++;
                printf("Kazandiniz!\n------------------------------------------------\n");
                printf("Skor: Kullanici %d - %d Bilgisayar\n\n",kullanici_puani, bilgisayar_puani);}
            else if (sonuc==0){
                printf("Berabere!\n------------------------------------------------\n");
                printf("Skor: Kullanici %d - %d Bilgisayar\n\n",kullanici_puani, bilgisayar_puani);}
        }
            else
                printf("Lutfen 0-1-2 degerlerinden birini giriniz!\n\n");


        if(bilgisayar_puani==5 || kullanici_puani==5)
            break;


            sayac++;
    }


        if(bilgisayar_puani>kullanici_puani){
            printf("Oyunun kazanani: BILGISAYAR!");
        }
        else
            printf("Oyunun kazanani: KULLANICI!");
        printf("\n\n");


        for(int i=0;i<sayac;i++){
            printf("Bilgisayarin secimleri[%d]:%d\n",i,dizi_pc[i]);}

        printf("\n\n");

        for(int i=0;i<sayac;i++){
            printf("oyuncu secimleri[%d]:%d\n",i,dizi_oyuncu[i]);}


    return 0;
}
