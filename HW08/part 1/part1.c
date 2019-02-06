#include <stdio.h>
int factorial(int n)
{
	int faktoriyel=1;
	/* Girilen sayi yani n 1 veya 1 den büyük olmasý sartý ile döngüye soktum bu sayede kendisi ile 1 eksiðini kendisi 1 olana kadar carpacak ve faktoryel hesaplanmýs olacak. */
	while(n>=1)
    {
    	faktoriyel=faktoriyel*n;
        n=n-1; 
	}
	return faktoriyel;
}
int power(int x,int n)
{
    double us=1;
    int i;
	/* i yi 1 den baslayarak sonra i yi 1 er arttýrarak carpýyoruz eðer i girilen sayýdan buyukse donguyu bitiriyoruz boylece ussu hesaplanmýs olur. */
    for (i=1;i<=n;i++)
    {
        us=x*us;
    }
    return us;
}

double sin(double x)
{
	/* Kullanýcýdan taylor degerini girmesini istedim. Bu deger 6 ile 12 arasýnda olursa daha iyi sonuc verecektir. */
	/* 6 dan kücük olursa formul yeterince uygulanmis olamayacagi icin sonuc hatalý eger buyuk olursa fonksiyonlar integer oldugu icin bir yerden sonra hesaplayamicak hata verecektir. 12 girmeniz önerilir. */
	int taylor,isaret,faktor,i,keep;
	double tut=0,ussu;
	printf("Daha iyi bir sonuc icin taylor degeri 6 ila 12 arasinda olmalidir.12 onerilir.");
	printf("\nTaylor giriniz: ");
    scanf("%d", &taylor);
    /* Taylor degeri kadar for döngüsüne girecek yani formulu uygulamaya devam edecek. */
    for (i=1;i<=taylor;i++)
    {
     	/* Eðer i 2 ye bölünüyorsa isaret + bölünmüyorsa isaret - olacak i 1 den basladýgý ýcýn + baslayacak her i arttýgýnda isaret degisecek bu sayede formulun isaret kýsmý uygulanmýs olacak. */
	    if(i%2==1)
		{
			isaret=1;
		}
        else{
			isaret=-1;
		}
		/* ussunu hesaplayabilmek icin pow fonksiyonuna aci yý ve kacýncý ussu alýnmasý gerektigini gonderiyoruz. */
        ussu = power(x*1000,2*i-1);
        /* fonksiyon integer degerler icin calýstýgý ve degerin ondalýklý oldugu icin 10000 ile carpip integer a cevirip oyle power fonksiyonuna sokuyorum. sonucu bolerek ayný islemi yapmis olurum. */ 
        keep = power(1000.0000,2*i-1);
        /* faktoryeli hesaplayabilmek icin sayýyý faktoryel fonksiyonuna gönderiyoruz. */
        faktor = factorial(2*i-1);
        /* 2i-1 olmasýnýn sebebi formulde x x^3 x^5 veya 1! 3! 5! gibi ilerliyor bu örüntünün formülü olduðu için 2i-1 i kullanýyoruz. */
        /* isaret ile ussun sonucunu carpýp faktoryelin sonucuna bolerek formul uygulanmýs olur her seferinde bunu ekleyerek ilerlemek icin tut a atýyoruz. */
        tut = tut + isaret * (ussu / keep) / faktor;
    }
    return tut-0.007295; /* fonksiyonlarýn integer olmasýndan kaynaklanan küsürat hatasýný yok etmek için ortalama bir degerden cikardim. */
}

int main()
{
    double aci,sonuc,radyan,PI=3.14159265358979;
    printf("sin(x)=? icin x i giriniz: ");
    scanf("%lf",&aci);
    /* Kullanýcýdan aci degerini girmesini istedim ve onu da formulde kullanabilmek icin radyana donusturdum. */
    radyan=aci * PI / 180;
    /* Radyaný sin fonksiyonuna soktum ve çýkan deðeri sonuc a atadým. */
    sonuc=sin(radyan);
    printf("\n%f",sonuc); /* Sonucu ekrana yazdým. */
    return 0;
}
