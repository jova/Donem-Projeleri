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
    char harf;
    int adet;
} Harf;

void harfleriTanimla(Harf dizi[])
{
    dizi[0].harf = 'A';
    dizi[0].adet = 0;
    dizi[1].harf = 'B';
    dizi[1].adet = 0;
    dizi[2].harf = 'C';
    dizi[2].adet = 0;
    dizi[3].harf = 'D';
    dizi[3].adet = 0;
    dizi[4].harf = 'E';
    dizi[4].adet = 0;
    dizi[5].harf = 'F';
    dizi[5].adet = 0;
    dizi[6].harf = 'G';
    dizi[6].adet = 0;
    dizi[7].harf = 'H';
    dizi[7].adet = 0;
    dizi[8].harf = 'I';
    dizi[8].adet = 0;
    dizi[9].harf = 'J';
    dizi[9].adet = 0;
    dizi[10].harf = 'K';
    dizi[10].adet = 0;
    dizi[11].harf = 'L';
    dizi[11].adet = 0;
    dizi[12].harf = 'M';
    dizi[12].adet = 0;
    dizi[13].harf = 'N';
    dizi[13].adet = 0;
    dizi[14].harf = 'O';
    dizi[14].adet = 0;
    dizi[15].harf = 'P';
    dizi[15].adet = 0;
    dizi[16].harf = 'R';
    dizi[16].adet = 0;
    dizi[17].harf = 'S';
    dizi[17].adet = 0;
    dizi[18].harf = 'T';
    dizi[18].adet = 0;
    dizi[19].harf = 'U';
    dizi[19].adet = 0;
    dizi[20].harf = 'V';
    dizi[20].adet = 0;
    dizi[21].harf = 'Y';
    dizi[21].adet = 0;
    dizi[22].harf = 'Z';
    dizi[22].adet = 0;
}


int main()
{
    Harf dizi[23], *pDizi;//türkçe harfler dışında kalan harfler 23 adet
    harfleriTanimla(dizi);
    pDizi = dizi;//gösterimleri pointer aracılığı ile yapacağız.
    FILE *fp;
    fp = fopen("text.txt", "r");

    int i = 0,j;
    char tempOkunan;

    printf("------------------------------------------------\n");
    while(1)
    {
        if((tempOkunan = fgetc(fp)) != EOF)
        {
            tempOkunan = toupper(tempOkunan);
            printf("%c", tempOkunan);
            for(j = 0; j < 23; j++)
            {
                if(tempOkunan == (pDizi+j)->harf)//okunan karakteri listemizde arayıp bulduğunda sayısını arttıralım.
                    ((pDizi+j)->adet)++;
            }
            i++;
        }
        else break;
    }
    printf("\n------------------------------------------------\n");
    fclose(fp);

    printf("\n------------------------------");
    printf("\nOkunan Toplam Karakter Sayisi: %d", i);
    printf("\n------------------------------\n");

    //BUBBLE SORT!
    int k,z, tempAdet;
    char tempHarf;
    for(k = 1; k < 23; k++)
    {
        for(z = 0; z < 23-k; z++)
        {
            if((pDizi+z)->adet < (pDizi+(z+1))->adet)
            {
                tempAdet = (pDizi+z)->adet;
                tempHarf = (pDizi+z)->harf;

                (pDizi+z)->adet = (pDizi+(z+1))->adet;
                (pDizi+z)->harf = (pDizi+(z+1))->harf;

                (pDizi+(z+1))->adet = tempAdet;
                (pDizi+(z+1))->harf = tempHarf;
            }
        }
    }

    //Ekrana yazdıralım.
    for(z = 0; z < 23; z++)
    {
            printf("\n%c --> %d", (pDizi+z)->harf, (pDizi+z)->adet);
    }
    printf("\n");
    return 0;
}
