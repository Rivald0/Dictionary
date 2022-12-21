// Ronaldo Julius Siregar_13322030
// Aldo Bonis Halawa_13322011
// Kezia Cicilia_13322013

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// deklarasi fungsi
void input();
int terjemahkan1();
int terjemahkan2();

// input data kedalam file
int main()
{
    int pilihan;
    do
    {
        printf("========================================MENU====================================\n");
        printf("1. Input Data\n");
        printf("2. Terjemahkan Batak ke Inggris\n");
        printf("3. Terjemahkan Inggris ke Batak\n");
        printf("4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            input();
            getchar();
            break;
        case 2:
            terjemahkan1();
            getchar();
            break;
        case 3:
            terjemahkan2();
            getchar();
            break;
        case 4:
            printf("Terima Kasih\n");
            getchar();
            break;
        default:
            printf("Pilihan tidak ada\n");
            getchar();
            break;
        }
    } while (pilihan != 4);
    return 0;
}

void input()
{
    FILE *fp;
    char kata[MAX];
    char arti[MAX];
    char pilihan;
    fp = fopen("Kamus.txt", "a");
    do
    {
        printf("Masukkan kata : ");
        scanf("%s", kata);
        printf("Masukkan arti : ");
        scanf("%s", arti);
        fprintf(fp, "%s\n%s\n", kata, arti);
        printf("Apakah anda ingin menginput kata lagi? (y/n) : ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y');
    fclose(fp);
}

int terjemahkan1()
{
    FILE *fp;
    char kata[MAX];
    char arti[MAX];
    char pilihan;
    char kata2[MAX];
    char arti2[MAX];
    fp = fopen("Kamus.txt", "r");
    do
    {
        printf("Masukkan kata : ");
        scanf("%s", kata);
        while (fscanf(fp, "%s\n%s", kata2, arti2) != EOF)
        {
            if (strcmp(kata, kata2) == 0)
            {
                printf("Arti : %s\n", arti2);
            }
        }
        printf("Apakah anda ingin menerjemahkan kata lagi? (y/n) : ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y');
    return 0;
    fclose(fp);
}
int terjemahkan2()
{
    FILE *fp;
    char kata[MAX];
    char arti[MAX];
    char pilihan;
    char kata2[MAX];
    char arti2[MAX];
    fp = fopen("Kamus.txt", "r");
    do
    {
        printf("Masukkan kata : ");
        scanf("%s", kata);
        while (fscanf(fp, "%s\n%s", kata2, arti2) != EOF)
        {
            if (strcmp(kata, arti2) == 0)
            {
                printf("Arti : %s\n", kata2);
            }
        }
        printf("Apakah anda ingin menerjemahkan kata lagi? (y/n) : ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y');
    return 0;
    fclose(fp);
}