/*

-----------------------------------------------
|                                             |
|       ERSOY TORAMAN & ENES CELIK            |
|          152804014  & 152804007             |
|                                             |
-----------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char isim[100];
    int kod;
    long int numara;
} Telefon;

FILE *fp, *fp_tmp;

int main()
{
    printf("\t\t\tTELEFON REHBERI");
    printf("\n\t\t\t---------------");

    while(1)
    {
        printf("\n\n\nISLEMLER\n");
        printf("1. Kayit Ekle\n2. Telefonlari Listele\n3. Kaydi Duzenle\n4. Numara ile Kayit Bul\n5. Isim ile Kayit Bul\n6. Kayit Sil\n0. Cikis\n");
        printf("Lutfen seciminizi yapiniz: ");
        int secim;
        scanf("%d", &secim);
        switch(secim)
        {
            case 0: return 0;
            case 1: KayitEkle(); break;
            case 2: TelefonlariListele(); break;
            case 3: KaydiDuzenle(); break;
            case 4: NumaraIleKayitBul(); break;
            case 5: IsimIleKayitBul(); break;
            case 6: KayitSil(); break;
            default: system("cls"); break;
        }
    }

    printf("\n");
    return 0;
}

void KayitEkle()
{
    if((fp = fopen("telefon-rehberi.txt", "ab")) == NULL) return 0;

    system("cls");
    Telefon tel;
    printf("Lutfen bir isim belirleyiniz: ");
    scanf("%s", &tel.isim);
    printf("Lutfen bir musteri kodu belirleyiniz: ");
    scanf("%d",  &tel.kod);
    printf("Lutfen bir telefon numarasi giriniz: ");
    scanf("%ld",  &tel.numara);

    if((fwrite(&tel, sizeof(tel), 1, fp)) == 1)
         printf("\nYeni kayit basariyla eklendi.\n");
    else printf("\nYeni kayit eklenirken bir sorun olustu.\n");

    fclose(fp);
}

void TelefonlariListele()
{
    if((fp = fopen("telefon-rehberi.txt", "rb")) == NULL) return 0;

    system("cls");
    Telefon tel;
    while(fread(&tel, sizeof(tel), 1, fp))
    {
        printf("\n--------------------------------");
        printf("\nMusteri Ismi: %s", tel.isim);
        printf("\nMusteri Kodu: %d", tel.kod);
        printf("\nMusteri Telefonu: %ld", tel.numara);
        printf("\n--------------------------------");
    }

    fclose(fp);
}

void KaydiDuzenle()
{
    if((fp = fopen("telefon-rehberi.txt", "rb+")) == NULL) return 0;

    system("cls");
    fflush(stdin);
    printf("Lutfen musterinin adini giriniz: ");
    char isim[100];
    gets(isim);

    Telefon tel;
    while ((fread(&tel, sizeof(tel), 1, fp) == 1) && (strcmp(tel.isim, isim)) != 0);
    if(strcmp(tel.isim, isim) == 0)
    {
        printf("\n--------------------------------");
        printf("\nMevcut Musteri Ismi: %s", tel.isim);
        printf("\nMevcut Musteri Kodu: %d", tel.kod);
        printf("\nMevcut Musteri Telefonu: %ld", tel.numara);
        printf("\n--------------------------------");
        printf("\nLutfen yeni bir isim belirleyiniz: ");
        scanf("%s", &tel.isim);
        printf("Lutfen yeni bir musteri kodu belirleyiniz: ");
        scanf("%d",  &tel.kod);
        printf("Lutfen yeni bir telefon numarasi giriniz: ");
        scanf("%ld",  &tel.numara);

        fseek(fp, -1 * sizeof(tel), SEEK_CUR); //okuma yaptığımız için bir blok geriye giderek üzerine yazma yapıyoruz.
        if((fwrite(&tel, sizeof(tel), 1, fp)) == 1)
            printf("\nMevcut kayit basariyla guncellendi.\n");
        else printf("\nMevcut kayit guncellenirken bir sorun olustu.\n");

        printf("--------------------------------");
        printf("\nYeni Musteri Ismi: %s", tel.isim);
        printf("\nYeni Musteri Kodu: %d", tel.kod);
        printf("\nYeni Musteri Telefonu: %ld", tel.numara);
        printf("\n--------------------------------");
    }
    else
    {
        printf("Musteri Bulunamadi.\n");
        printf("Yeniden arama yapmak ister misiniz? (E/H): ");
        if(toupper(getche()) == 'E')
        {
            KaydiDuzenle();
            return 0;
        }
    }

    fclose(fp);
}

void NumaraIleKayitBul()
{
    if((fp = fopen("telefon-rehberi.txt", "rb")) == NULL) return 0;

    system("cls");
    printf("Lutfen bir telefon numarasi giriniz: ");
    long int numara;
    scanf("%ld", &numara);

    Telefon tel;
    while ((fread(&tel, sizeof(tel), 1, fp) == 1) && (tel.numara != numara));
    if(tel.numara == numara)
    {
        printf("\n--------------------------------");
        printf("\nMusteri Ismi: %s", tel.isim);
        printf("\nMusteri Kodu: %d", tel.kod);
        printf("\nMusteri Telefonu: %ld", tel.numara);
        printf("\n--------------------------------");
    }
    else printf("Musteri Bulunamadi.");

    fclose(fp);
}

void IsimIleKayitBul()
{
    if((fp = fopen("telefon-rehberi.txt", "rb")) == NULL) return 0;

    system("cls");
    fflush(stdin);
    printf("Lutfen musterinin adini giriniz: ");
    char isim[100];
    gets(isim);

    Telefon tel;
    while ((fread(&tel, sizeof(tel), 1, fp) == 1) && (strcmp(tel.isim, isim)) != 0);

    if(strcmp(tel.isim, isim) == 0)
    {
        printf("\n--------------------------------");
        printf("\nMusteri Ismi: %s", tel.isim);
        printf("\nMusteri Kodu: %d", tel.kod);
        printf("\nMusteri Telefonu: %ld", tel.numara);
        printf("\n--------------------------------");
    }
    else printf("Musteri Bulunamadi.");

    fclose(fp);
}

void KayitSil() //temp dosyası oluşturup bilgileri tempe yazıp belirlenen kaydı eliyoruz.
{
    if((fp = fopen("telefon-rehberi.txt", "rb")) == NULL) return 0;
    if((fp_tmp = fopen("telefon-rehberi.temp", "wb")) == NULL) return 0;

    system("cls");
    fflush(stdin);
    int basarili = 0;

    printf("Lutfen musterinin kodunu giriniz: ");
    int kod;
    scanf("%d", &kod);

    Telefon tel;
    while ((fread(&tel, sizeof(tel), 1, fp) == 1))
    {
        if(tel.kod != kod)
        {
            fwrite(&tel, sizeof(tel), 1, fp_tmp);
        }
        else
        {
            printf("%d nolu musteri basari ile silindi.\n", tel.kod);
            basarili = 1;
        }
    }

    if(basarili == 0)
    {
        printf("Musteri Bulunamadi.\n");
        printf("Yeniden arama yapmak ister misiniz? (E/H): ");
        if(toupper(getche()) == 'E')
        {
            fclose(fp);
            fclose(fp_tmp);
            remove("telefon-rehberi.txt");
            rename("telefon-rehberi.temp", "telefon-rehberi.txt");
            KayitSil();
            return 0;
        }
    }

    fclose(fp);
    fclose(fp_tmp);
    remove("telefon-rehberi.txt");
    rename("telefon-rehberi.temp", "telefon-rehberi.txt");

}
