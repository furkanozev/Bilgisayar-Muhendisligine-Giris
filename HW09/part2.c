#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/* random sayilar icin stdlib.h ve time.h , kok almak icin math.h kutuphanelerini kullandim. */
int main()
{
	srand(time(NULL));
	int v1[20],v2[20],v_toplam[20],i=0,sayac1=0,sayac2=0;
	double dot=0,v1_uzunluk=0,v2_uzunluk=0;
	/* Kullanacagim parametreleri tanimladim. */
	/* Dizideki degerleri random almak icin for dongusune soktum. */
	for(i;i<20;i++)
	{
		v1[i]=rand()%10;
		v2[i]=rand()%10;
	}
	/* 1. Vektordeki degerleri for dongusune sokarak tek tek yazdirdim. */
	printf("v1: ");
	for(i=0;i<20;i++)
	{
		printf("%d, ",v1[i]);
	}
	printf("\n");
	/* 2. Vektordeki degerleri for dongusune sokarak tek tek yazdirdim. */
	printf("v2: ");
	for(i=0;i<20;i++)
	{
		printf("%d, ",v2[i]);
	}
	/* norm degerlerini bulmak icin dizilerdeki her deger icin 0 ile esit olmadigini kontrol edip esitse sayaclari arttiriyorum. */
	for(i=0;i<20;i++)
	{
		if(v1[i]!=0)
		{
			sayac1=sayac1+1;
		}
		if(v2[i]!=0)
		{
			sayac2=sayac2+1;
		}
	}
	/* Norm sonuclarini yazdiriyorum. */
	printf("\n\nv1 L0 norm : %d \nv2 L1 norm : %d \n",sayac1,sayac2);
	/* Vektorlerin toplamýný bulmak icin index i 1 er arttýrarak 2 vektorun o indexteki degerini toplayýp yeni bir diziye yaziyorum. */
	printf("\nv1 + v2 = ");
	for(i=0;i<20;i++)
	{
		v_toplam[i]=v1[i]+v2[i];
		printf("%d, ",v_toplam[i]);
	}
	/* vektorlerin carpimi , vektorlerin uzunluklarý icin ortak for kullandim. i yi yani index i 1 er arttirarak hesaplamami yapiyorum. */
		for(i=0;i<20;i++)
	{
		/* dot(vektorlerin carpimi) = v1[0]*v2[0]+v1[1]*v2[1]....+v1[19]+v2[19] */
		dot=dot+v1[i]*v2[i];
		/* 1. vektorun kareleri toplami = v1[0]*v1[0]+v1[1]v1[1]...+v1[19]v1[19] */
		v1_uzunluk=v1_uzunluk+(v1[i]*v1[i]);
		/* 2. vektorun kareleri toplami = v2[0]*v2[0]+v2[1]v2[1]...+v2[19]v2[19] */
		v2_uzunluk=v2_uzunluk+(v2[i]*v2[i]);
	}
	/* uzunluklarý hesaplarken degerlerin karelerinin toplaminin karekökunu aliyoduk kareleri toplamini hesapladik bir de kokunu almamiz lazim. */
	v1_uzunluk=sqrt(v1_uzunluk);
	v2_uzunluk=sqrt(v2_uzunluk);
	/* cosine similarity formulunu uyguluyorum. */
	printf("\n\nsim(v1,v2) : %lf",dot/(v1_uzunluk*v2_uzunluk));
return 0;	
}
