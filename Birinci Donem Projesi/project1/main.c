#include <stdio.h>
#include <stdlib.h>

int araclar[10][5],  eklenenAracSayisi = 0; //[x][0] = plaka, [x][1] = tipi, [x][2] = girisSaati, [x][3] = cikisSaati, [z][4] = Ucret

void AracEkle()
{
    int i, plaka, tipi, girisSaati, cikisSaati, girisUcreti = 5, plakaOtoparktaVarMi = 0;

    if(eklenenAracSayisi < 10)
    {
    printf("Lutfen aracin plakasini giriniz: ");
    scanf("%d", &plaka);

    for(i = 0; i < eklenenAracSayisi; i++)//x plakali araci otoparkta ara
    {
        if(plaka == araclar[i][0])
        {
            plakaOtoparktaVarMi = 1;
        }
    }

    if(plakaOtoparktaVarMi == 0) //x plakali arac otoparkta yoksa, x plakali araci ekle.
    {
    do
    {
    printf("Lutfen aracin tipini belirleyiniz [ 1- (Motosiklet) | 2- (Otomobil) | 3- (Kamyon) ]: ");
    scanf("%d", &tipi);
    }
    while(tipi > 3 || tipi < 1);

    do
    {
    printf("Lutfen Aracin otoparka giris saatini giriniz: ");
    scanf("%d", &girisSaati);
    printf("Lutfen Aracin otoparktan cikis saatini giriniz: ");
    scanf("%d", &cikisSaati);
    }
    while(cikisSaati > 24 || girisSaati > 24 || (girisSaati > cikisSaati));

    //araci otoparka ekle.
    araclar[eklenenAracSayisi][0] = plaka;
    araclar[eklenenAracSayisi][1] = tipi;
    araclar[eklenenAracSayisi][2] = girisSaati;
    araclar[eklenenAracSayisi][3] = cikisSaati;
    araclar[eklenenAracSayisi][4] = girisUcreti;
    eklenenAracSayisi++;

    system("cls");//konsolu temizle
    printf("%d plakali araciniz otoparka eklenmistir.", plaka);
    printf("\nOtoparktaki arac sayisi: (%d/10)\n\n", eklenenAracSayisi);
    }
    else
    {
        printf("%d plakali arac zaten otoparkta.\n\n", plaka);
    }
    }
    else
    {
        system("cls");
        printf("Otoparkta zaten %d adet arac bulunmaktadir. Daha fazla ekleyemezsiniz.\n\n", eklenenAracSayisi);
    }

}

void AraclariListele()
{
    system("cls");
    int i;
    printf("|ARAC NO| |PLAKA| |ARAC TIPI| |GIRIS SAATI| |CIKIS SAATI|");
    printf("\n---------------------------------------------------------");
    for(i = 0; i < eklenenAracSayisi; i++)
    {
        printf("\n    %d\t     %d  \t%d\t     %d\t\t  %d",i+1,araclar[i][0],araclar[i][1], araclar[i][2], araclar[i][3]);
    }
    printf("\n---------------------------------------------------------");
    printf("\n\n");
}

void UcretHesapla()
{
    int i, plaka, parkSaati = -1, toplamUcret = 0;
    printf("Lutfen aracinizin plakasini giriniz: ");
    scanf("%d", &plaka);
    system("cls");
    for(i = 0; i < eklenenAracSayisi; i++)
    {
        if(plaka == araclar[i][0])//plaka otoparktaysa
        {
            parkSaati = araclar[i][3] - araclar[i][2];
            if(araclar[i][1] == 1)//motosiklet icin ucreti ekle
            {
                araclar[i][4] += (parkSaati * 1);
            }
            else if(araclar[i][1] == 2)//otomobil icin ucreti ekle
            {
                araclar[i][4] += (parkSaati * 2);
            }
            else//kamyon icin ucreti ekle. (1-2 d���nda sadece 3 se�ilebilir, else if'e gerek yok)
            {
                araclar[i][4] += (parkSaati * 3);
            }
            toplamUcret = araclar[i][4];//odenecek toplam ucret
        }
    }

    if(parkSaati == -1)//plaka otoparkta degilse parksaati -1 olarak gelecektir.
    {
        printf("%d plakali arac otoparkta mevcut degildir.\n\n", plaka);
    }
    else
    {
        printf("%d plakali arac icin toplam ucret: %d TL\n\n",plaka, toplamUcret);
    }
}

void MaksveMinUcretiBul()
{
    int maksUcret, minUcret, i;

    maksUcret = araclar[0][4];
    minUcret = araclar[0][4];
    for(i = 0; i < eklenenAracSayisi; i++)
    {
        if(maksUcret <= araclar[i][4])
        {
            maksUcret = araclar[i][4];
        }
        if(minUcret >= araclar[i][4])
        {
            minUcret = araclar[i][4];
        }
    }
    system("cls");
    printf("Uyari: Otoparktaki tum araclarin ucretleri hesaplanmadan (3) bu fonksiyon dogru sonuc vermez.\n");
    printf("Maksimum odenecek ucret: %d TL\n", maksUcret);
    printf("Minimum odenecek ucret: %d TL\n\n", minUcret);
}

int main()
{
    int menuSecim = 0;

   while(menuSecim != 5)
   {
    printf("-------------------------\n");
    printf("| 1- Arac Ekle          |\n");
    printf("| 2- Araclari Listele   |\n");
    printf("| 3- Ucret Hesapla      |\n");
    printf("| 4- Maks ve Min Ucret  |\n");
    printf("| 5- Guvenli Cikis      |\n");
    printf("-------------------------\n");
    printf("Lutfen yapmak istediginiz islemi seciniz [1,2,3,4,5]: ");
    scanf("%d", &menuSecim);

    if(menuSecim == 1)
    {
        system("cls");
        AracEkle();
    }
    else if(menuSecim == 2)
    {
        system("cls");
        AraclariListele();
    }
    else if(menuSecim == 3)
    {
        system("cls");
        UcretHesapla();
    }
    else if(menuSecim == 4)
    {
        MaksveMinUcretiBul();
    }
    else if(menuSecim == 5)
    {
        break;
    }
    else
    {
    system("cls");
    printf("(Sadece 1, 2, 3, 4 ve 5 olarak secim yapilabilir.)\n\n");
    }
   }


    printf("\n\n");
    return 0;
}
