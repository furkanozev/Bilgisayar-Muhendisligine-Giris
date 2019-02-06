;DEÐERLERÝ A1 VE A2 YE HEXADECÝMAL OLARAK GÝRÝNÝZ SONUÇ HEXADECÝMAL OLARAK A2'YE YAZILACAKTIR.

Pozitif:
LOAD R0,[0xA1]
LOAD R1,[0xA0]
jmpEQ R1=R0,Next ; Eðer eþitlik varsa mod iþlemini uygula;
jmpLE R1<=R0,finish2 ;Eðer Mod u alýnacak deðer mod dan küçükse finish2'e atla.
Next:LOAD R0,[0xA0] ; A0'daki Mod'u alýnacak deðeri R0'a yükle.
LOAD R1,[0xA1] ; A1'deki A0'a göre alýnacak modun deðerini R1'e yükle.
LOAD R2,255    ; 11111111 'in hexadecimal karþýlýðýný R2'e yükle.
; MOD iþlemi ilk deðerin ikinci deðer e bölümünden kalan ý bulmak için kullanýlýr.
; Bu simulator 'de bölme çarpma çýkarma iþlemi yapamayacaðýmýzý biliyoruz.
; Bu yüzden 2. sayýyýnýn Two's complement Notation'a göre negatif ini alýp,
; Ýlk sayý ikinci sayýdan küçük olana kadar çýkarýyoruz ve iþlemi sonlandýrýyoruz.
; R0'daki son deðer bizim iþlemimiin sonucunu verir.
XOR R3,R1,R2 ; R1 ile R2 i XOR yapýp R3'e yaz
LOAD R4,1    ; R4'e 1 deðerini yükle
ADDI R2,R3,R4 ; R3 ile R4 ü topla R2'e yaz
; Üstteki 3 iþlem sonucu R2 deðerimiz artýk negatif.
Return:ADDI R0,R2,R0 ; 1. deðerle 2. deðerin negatif halini topla.
jmpLE R1<=R0,Return ; Eðer R0 R1 den büyük ve eþitse Return iþlemine devam et.
STORE R0,[0xA2] ; R0 daki son deðeri (yani mod iþleminin sonucunu) A2'e yaz.
LOAD R4,48
ADDI R4,R0,R4
MOVE RF,R4
finish:halt
finish2:
LOAD R0,[0xA0]
STORE R0,[0xA2]
LOAD R4,48
ADDI R4,R0,R4
MOVE RF,R4
halt