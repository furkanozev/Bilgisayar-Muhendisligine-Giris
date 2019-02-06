#include<stdio.h>
int main()
{
	int dongu,secenek;                      					/* While ile döngü yapacak bir menü yapmak için koþulu doðru olan bir eþitlik ile döngüye giriyoruz. */
	dongu=1;
	while(dongu && 1 == 1)										/* dongu=1 ise koþul saðlanýr ve while döngüsüne girer. Eðer dongu=0 ise while saðlanamaz ve program sonlanýr. */
	{
		printf("\n---- MENU ----\n");							/* Ekrana Menü basýldý. */
		printf("1. Yildizlardan elmas ciz\n");	
		printf("2. Ogrenci bilgisini goster\n");	
		printf("0. Cikis\n\n");		
		printf("Seceneginiz:");           		 				 /* Kullanýcýdan yapmak istediði iþlemi sorup girdiði deðere göre if parametresini uygula. */
		scanf("%d", &secenek);
		printf("\n");
		
		if(secenek == 1)										/* 	Kullanýcý seçenek 1 i seçerse ekrana yüksekliðe baðlý olarak elmas çizilecek. */ 
		{
 			int yildiz,yildiz_tut,satir_tut,satir,yukseklik;
 			printf("Yuksekligi giriniz:");						/* Kullanýcýya elmasýn yüksekliðini sor */
   			scanf("%d", &yukseklik);
			while((yukseklik%2)==0)								/* Girilen sayý çiftse kullanýcýdan tek sayý girmesini iste. */
			{
				printf("\nLutfen tek sayi giriniz:");
				scanf("%d",&yukseklik);
			 }
	
			if((yukseklik%2)==1)								/* Yüksekliðin tek sayý olduðunu doðruluyor. */
			{
	 			satir=((yukseklik+1)/2);						/* Satýr sayýsýný satir a tanýmlýyorum üst kýsým için (yükseklik+1)/2 formülünden !Alt kýsým için for döngüsünden çýkýnca deðiþecek. */
 				/* Elmasýn orta dahil üst kýsmýný yazan kod */
				for(yildiz=1; yildiz<=yukseklik; yildiz++)		/* Girilen yükseklik sayýsý kadar for döngüsünü döndür */
				{
 					yildiz_tut=yildiz;								/* yildiz deðerini yildiz_tut 'ta tut çünkü içerdeki for da yildiz üzerinden dönecek ve yildiz deðeri sürekli deðiþebilir */
 					satir_tut=satir;							/* Satir sayýsý da deðiþebileceðinden satir_tut ta satir sayýsýný tut*/
 					for(satir; 0<satir; satir--)				/* Elmasýn üst kýsmý için satir sayýsý (n+1)/2 idi satir sayýsý kadar boþluk býrakýlacak */
					{
 						printf(" ");
	 				}
					for(yildiz; 0<yildiz; yildiz--)				/* Elmasýn üst kýsmý için 1. satýrda 1 * olmak üzere her sonraki satýr için +2 * olacak */
					{
						printf("*");
					}					   
					printf("\n");
					yildiz=yildiz_tut+1;						/* Her satýr sonrasý +2 * olmasý için 1 tane burda bir tane ise for döngüsünde eklme yapýyorum. */
					satir=satir_tut-1;							/* Elmasýn üst kýsmý için her satýrda 1 boþluk daha az olacaðý ve boþluk sayýsýnýn satýr sayýsýyla for döndürdüðü için satýr sayýsýný azaltýyorum. */
				 }
 				/* Elmasýn ortadan sonraki kýsmýný yazan kod */
			 	for(yildiz=yukseklik-2; 0<=yildiz; yildiz--)	/* Orta kýsým yükseklik kadar yýldýz basacaðýndan ortadan sonraki satýrlar için -2 * basýlmasý lazým. */							
				{
 					yildiz_tut=yildiz;
 					satir_tut=satir;
 					for(satir; satir<2; satir++)				/* Boþluk sayýsý satir sayýsýyla doðru orantýlý olacak þekilde 2 þer artacak */ 
					{
						printf(" ");
					 }
					for(yildiz; 0<yildiz; yildiz--)
					{
						printf("*");
					 }
    				printf("\n");
    				yildiz=yildiz_tut-1;						/* Yildiz sayýsý 2 þer 2 þer satýr sayýsýyla doðru orantýlý azalacak */
    				satir=satir_tut-1;							/* Döngüde satir sayýsý 2 ye kadar arttýrarak çalýþtýðý için 1 eksilterek daha fazla boþluk koymayý saðlarým. */
				 }
			}
		}
	
		
		else if(secenek == 2)									/* Seçenek 2 ise öðrenci bilgilerini gösterecek */
		{
			printf("\nAd: <Furkan>\n");
			printf("Soyad: <Ozev>\n");
			printf("Ogrenci No: <161044036>\n");
		}
		
		else if(secenek == 0)									/* Çýkýþ için seçenek 0 ý seçtiyse en baþtaki while þartýndaki döngüyü 0 a eþitleyerek 0 && 1=1 saðlamayacaðýndan while döngüsüne girmeden programý sonlandýracak. */ 
		{
			printf("\nBasariyla cikis yapildi.");
			dongu=0;
		}
		
		else if(secenek != 0,1,2)								/* 0,1,2 den baþka deðerler girilirse bu deðerlerin yanlýþ olduðunu ve tekrar seçim yapýlmasýný isteyecek. */
		{
			printf("\nYanlis deger girildi!\n");
			printf("Menuye donuyorsunuz...\n");
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
return 0;
}
