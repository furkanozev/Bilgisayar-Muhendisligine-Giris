#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Kullanicalacak fonksiyonlari tanimladim */
void test(int sayi);
void random_dizi(int boy[],int sayi);
void dizi_kopya(double kopya[], int boy[], int sayi);
void dizi_yazdir(int boy[], int sayi);
int yarisma(int boy[], double kopya[], int sayi);
void kontrol (int a,int b);

int main()
{
											/* Dizi uzunlugunu degistirebilirsiniz. Ornek olarak 6 istenmisti. */
	test(6);
	
return 0;
}

void test(int sayi)
{
	srand(time(NULL));
	int boy[sayi],sayac1=0,sayac2=0; 		/* sayi parametresi dizi uzunlugu , sayac1 mehmetin cikolata yeme sayisi, sayac 2 aysenin cikolata sayisi */
	double kopya[sayi]; 					/* Algoritmamda gerekli kontrolleri yapamabilmek icin boy dizisinin double kopyasini olusturmak icin tanimladim */ 
	random_dizi(boy,sayi);					/* Boylarý rastgele olan cikolata sayisi kadar uzunluklu bir dizi olusturmak icin random_dizi fonksiyonunu cagirdim. */
	dizi_kopya(kopya,boy,sayi);				/* Olusturdugum boy dizisinin double kopyasini olusturmak icin dizi_kopya fonksiyonunu cagirdim. */
	dizi_yazdir(boy,sayi);					/* cikolata sayisi kadar uzunluklu boylari random olusturulan boy dizisi yazdirmak icin dizi_yazdir fonksiyonunu cagirdim. */ 
	sayac1=yarisma(boy,kopya,sayi);			/* Mehmet'in yedigi cikolata sayisini bulabilmek icin yarisma fonksiyonunu cagirdim. */
	sayac2=sayi-sayac1;						/* Cikolata sayisindan mehmetin yedigi cikolata sayisini cikarip aysenin cikolata sayisini buldum. */
	kontrol(sayac1,sayac2);					/* Yarismanin kazanani belirlemek ve yazdirmak icin kontrol fonksiyonunu cagirdim */
}
void random_dizi(int boy[],int sayi)
{
											/* rand()%11+1 fonksiyonu ile random gelen sayinin 11 e göre modunun 1 fazlasini alarak 1-11 arasi sayilardan rasgetele olusan boy dizisi olusturdum. */
	int i;
	for(i=0;i<sayi;i++)
	{
		boy[i]=rand()%11+1;
	}
}
void dizi_kopya(double kopya[], int boy[], int sayi)
{
											/* Dizinin kopyasini olusturmak icin indexleri 0 dan cikolata sayisina kadar arttýrdým ve kopya dizisini boy dizisine esitledim. */
	int i;
	for(i=0;i<sayi;i++)
	{
		kopya[i]=boy[i];
	}
}
void dizi_yazdir(int boy[], int sayi)
{
											/* Index i 0 dan baslatip cikolata sayisina kadar arttirip her cikolatanin boyunu ekrana yazdirdim. */
	int i;
	for(i=0;i<sayi;i++)
	{
		printf("%d ",boy[i]);
	}
}
int yarisma(int boy[], double kopya[], int sayi)
{
	int i,k=0,j=sayi-1,sayac1=0,sayac2=0;
											/* i döngülerde kullanabilmek icin, k mehmetin yedigi cikolatalarin indexini tutar, j aysenin yedigi cikolatalarin indexini tutar,
												sayac1 mehmetin yedigi cikolata sayisini tutar, sayac2 aysenin yedigi cikolata sayisini tutar. */ 
	double mehmet=0,ayse=0,k_mehmet=0,k_ayse=0;
											/* mehmet Mehmetin zamana göre yedigi cikolata uzunlugunu tutuyor, ayse Aysenin zamana göre yedigi cikolata uzunulugunu tutuyor,
												k_mehmet Mehmetin kontrolu, k_ayse Aysenin kontrolü */
												
		while(j>k)							/* Mehmet ve Ayse ayni cikolataya gelene kadar donguyu dondur. */
		{
			while(kopya[k]>0 && kopya[j]>0)	/* Mehmet veya Aysenin yedigi cikolata bitene kadar yani herhangi birtanesinin uzunlugu 0 olana kadar donguyu dondur. */
			{
				kopya[k]=kopya[k]-1;		/* Mehmet in yedigi cikolatanýn uzunlugunu zamanla 1 azalt. */
				kopya[j]=kopya[j]-0.5;		/* Aysen in yedigi cikolata uzunlugunu zamanla 0.5 azalt. */
				mehmet=mehmet+1;			/* Mehmet in yedigi cikolata uzunlugunu tut. */
				ayse=ayse+0.5;				/* Ayse in yedigi cikolata uzunlugunu tut. */
			}
											/* while dongusunde herhangi bir cikolata bittigi icin kimin cikolatasini bittirdigini buluyorum. */
			if(kopya[k]==0)					/* Mehmet in yedigi cikolata nin uzunlugu 0 olmussa yani bitmisse sayac1 i arttirip diger cikolataya gecmesi icin k(indexini) 1 arttiriyorum. */
			{
				
				k_mehmet=k_mehmet+boy[k];
				k=k+1;
				sayac1=sayac1+1;
			}
			if(kopya[j]==0)					/* Ayse in yedigi cikolata nin uzunlugu 0 olmussa yani bitmisse sayac2 i arttirip diger cikolataya gecmesi icin j(indexini) 1 azaltiyorum. */
			{
				k_ayse=k_ayse+boy[j];
				j=j-1;
				sayac2=sayac2+1;
			}	
		}
											/* Dongu bittigine gore ayse ve mehmet in indexleri ayni cikolataya geldi demektir.*/
		if(boy[k]==kopya[k])				/* Kalan cikolatanin herhangi biri tarafindan yenmeye baslanip baslanmadigini kontrol ediyorum. */
		{									/* Eger baslanmadiysa Mehmet yiyecegi icin Mehmet'in sayac1 ini 1 arttiriyorum. */
				sayac1=sayac1+1;
		}
		else								/* Eger yenmeye baslandiysa kimin yemeye basladigini tespit ediyorum */
		{
			if(kopya[k]!=0)					/* son indexteki cikolata eger 0 ise yenmis demektir o yüzden herhangi bir islem yapmaya gerek yok cunku o hesaplanmýstýr. */
			{
				if(mehmet>k_mehmet)			/* Mehmet'in yedigi uzunluk miktari yedigi tam cikolata sayisinin uzunlugundan fazla ise son indexteki cikolatayi mehmet yemeye baslamis demektir. */
				{
					sayac1=sayac1+1;
				}
				else						/* Yoksa ayse baslamis demektir ve baslayan cikolatayi bitirecegi icin aysenin sayac2 ini 1 arttiriyorum. */
				{
					sayac2=sayac2+1;
				}	
			}
		}
	return sayac1; /* Mehmet'in yedigi cikolata sayisini donduruyorum . */
}
void kontrol (int a,int b)
{
	printf("\nMehmet: %d\nAyse: %d",a,b);
	if(a>b)									/* Mehmet in yedigi cikolata sayisi Ayse nin yediklerinden buyukse Mehmet kazanir .*/
	{
		printf("\nSonuc: Mehmet Kazandi.");
	}
	if(a<b)									/* Ayse nin yedigi cikolata sayisi Mehmet in yediklerinden buyukse Ayse kazanir .*/
	{
		printf("\nSonuc: Ayse Kazandi.");
	}
	if(a==b)								/* Esit ise Beraberlik durumu olusur. */
	{
		printf("\nSonuc: Berabare");
	}
}
