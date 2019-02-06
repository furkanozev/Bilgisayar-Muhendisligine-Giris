#include <stdio.h>
/* Fonksiyonun adini arkadas_sayi olarak tanimladim. */
int arkadas_sayi(int sayi)
{
	/* Algoritma: girilen_sayi nin 1 den baslayarak modunu aliyorum ve her sayi icin 
		if kosuluna sokarak mod sonucu 0 olan sayilari topluyorum boylece
		girilen_sayi nin carpanlari toplamini hesaplýyorum. */ 
	int carpan=0,i;
	for(i=1 ; i<sayi ; i++)
	{
		if(sayi%i==0)
		{
			carpan=carpan+i;
		}
	}
	/* retur carpan; yaparak degeri fonksiyon disina cýkarabiliyorum. */
	return carpan;
	
}

int main()
{
	int girilen_sayi,carpan_toplami,kontrol,sonuc,tut;
		/* Kullanilacak integer degerleri tanimladim. */
	printf("Arkadasini bulmak istediginiz sayiyi girin:");
	scanf("%d", &girilen_sayi);
	printf("\n");
		/* Kullanýcýdan arkadas sayýsýný bulmak istedigi integer degeri girmesini istedim. */
			
	carpan_toplami = arkadas_sayi(girilen_sayi);
		/* girilen_sayi yi arkadas_sayi fonksiyonunda isleme sokarak carpan_toplami na esitledim. */
	sonuc = arkadas_sayi(carpan_toplami);
		/* carpan_toplami ni arkadas_sayi fonksiyonuna sokarak sonuc degerine yükledim. */
	
/* Iki farkli sayi birbirinin kendisi haric pozitif bolenleri toplamina esitse bu sayilara arkadas sayilar denir. 
	Pozitif ve farkli olmasý kosulu var ornegin 6'ýn arkadas sayisi 6 degildir, 6 nin arkadas sayisi yoktur.
	Kisacasi arkadas sayisi kendisine esit olamaz bunu da if icine kosul koyarak belirttim.
	
	Algoritma: Girilen sayýnýn kendisi hariç çarpanlarýnýn toplamýný bularak bir deðere yüklüyor sonra o deðer için ayný iþlemi yürütüyor
	yani o deðer içinde çarpanlarýnýn toplamýný hesaplýyor. Son çýkan sonuç eðer girilen sayýya eþit ise arkadaþ sayýsý vardýr ve
	bunu ekrana yazýyor. */
		
		if(girilen_sayi==sonuc && girilen_sayi!=carpan_toplami)
			/* girilen_sayi sonuc 'a esit ve girilen_sayi nin carpanlarý toplamý kendisi olmayacak. */
		{
			printf("%d'nin arkadas sayisi %d'dir.",girilen_sayi,carpan_toplami);
		}
		else
		{
			printf("%d'nin arkadas sayisi yoktur.",girilen_sayi);
		}
}
