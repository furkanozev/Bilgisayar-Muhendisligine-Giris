												/*
 													FURKAN 
														ÖZEV 
															161044036
																		*/
#include<stdio.h>
int main()
{
	int guncelhiz,hedefhiz; 											// Güncel hýz ile Hedef hýzý tam sayý olarak programa tanýmladým.
		printf("Guncel hizinizi giriniz:\n");							// Ekrana guncel hýzý giriniz yazýsýný yazdýrdým.
			scanf("%d", &guncelhiz);									// Kullanýcýdan güncel hýz için integer deðer girilmesini istedim.

		printf("Hedef hizinizi giriniz:\n");							// Güncel hýz girildikten sonra Hedef hýzý giriniz yazýsýný ekrana yazdým.
			scanf("%d", &hedefhiz);										// Kullanýcýdan hedef hýz için integer deðer girilmesini istedim.
			
		printf("Guncel hiz= %d\n",guncelhiz);							// Kullanýcýnýn girdiði güncel hýzý Guncel hiz= x diye ekrana yazdým.
		printf("Hedef hiz= %d\n",hedefhiz);								// Kullanýcýnýn girdiði hedef hýzý Hedef hiz= x diye ekrana yazdým.
			
	if(guncelhiz<hedefhiz)												// Eðer hedef hýz güncel hýzdan büyükse for döngüsüne girecek.
		{
		int i=guncelhiz;												// For döngüsünde kullanabilmek için i tanýmladým ve güncel hýz a eþitledim.
			for(i;i<=hedefhiz;i++)										// For döngüsü güncel hýz hedef hýzdan büyük olana kadar güncel hýza 1 ilave edilerek printf e devam edecek.
				printf("Guncel hiz= %d\t\n\t",i);						// Ýlk olarak güncel hýzý ekrana yazacak daha sonra her döngü sýrasýnda ekrana güncel hýzý yazacak.

		}

	else																// Hedef hýz güncel hýzdan büyük deðilse else parametresine gidecek.
		{

			if(guncelhiz>hedefhiz)										// Eðer güncel hýz hedef hýzdan büyükse printf deki komutu yazacak.
				{
					printf("Hiziniz hedef hizdan yuksektir.");			// Ekrana "Hiziniz hedef hizdan yüksektir." yazdýr.
				 }

			else														// Güncel hiz hedef hiz a eþitse printf deki komutu yazacak.
				{
					printf("Hiziniz hedef hiza esittir.");				// Ekrana "Hiziniz hedef hiza esittir." yazacak.
				 } 

		}
	
	
	return 0;
}
