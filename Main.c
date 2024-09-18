#include <stdio.h>
#include <string.h>
#define BATAS_PLAYER 100
#define MAX_NAME_LENGTH 15
char player[BATAS_PLAYER][MAX_NAME_LENGTH];
int noPlayers = 0;
int atribut[100][25] ;

void inputPlayerData() {
char lanjut;
do {
if (noPlayers >= BATAS_PLAYER) {
printf("Maaf, jumlah pemain sudah mencapai batas maksimal yaitu 100 pemain.\n");
return;
}
char namaPlayer[MAX_NAME_LENGTH];
printf("Masukkan nama pemain (maksimal 15 karakter): ");
scanf("%s", namaPlayer);
if (strlen(namaPlayer) > MAX_NAME_LENGTH) {
printf("Maaf, nama pemain melebihi batas karakter maksimal (15 karakter).\n");
return;
}
strcpy(player[noPlayers], namaPlayer);
printf("Data pemain %s berhasil dimasukkan.\n", namaPlayer);
noPlayers++;
printf("Apakah Anda ingin memasukkan nama pemain lagi? (y/n): ");

scanf(" %c", &lanjut);
} while (lanjut == 'y' || lanjut == 'Y');
}
void inputAtributData() {
for (int i = 0; i < noPlayers; i++) {
printf("Masukkan nilai untuk %s:\n", player[i]);
for (int j = 0; j < 3; j++) {
printf("Masukkan data atribut-%s [%d][%d] :", player[i], i , j );
scanf("%d", &atribut[i][j]);
}
}
printf("Data atribut berhasil dimasukkan.\n");
}
void playerList() {
if (noPlayers == 0) {
printf("Data pemain masih kosong. Masukkan data terlebih dahulu.\n");
} else {
printf("Daftar Pemain:\n");
printf("Jumlah pemain saat ini: %d\n", noPlayers);
printf("-----------------------------\n");
printf("| No | %-20s |\n", "Nama");
printf("-----------------------------\n");
for (int i = 0; i < noPlayers; i++) {
printf("| %-2d | %-20s |\n", i + 1, player[i]);
printf("-----------------------------\n");
}
}
}
void tampilAtributData() {
if (noPlayers == 0) {
printf("Data atribut. Masukkan data terlebih dahulu.\n");
} else {
printf("\nDAFTAR PLAYER:\n");
printf("+------------------+------------------+------------------+\n");
printf("| %-15s | %10s | %10s | %10s |\n", "Nama","Coldown","Attack","Deffense");
printf("+------------------+------------------+------------------+\n");
for (int i = 0; i < noPlayers; i++) {
printf("| %-15s | %10d | %10d | %10d |\n", player[i], atribut[i][0], atribut[i][1], atribut[i][2]);

}

}
}
void menu() {
printf("-------------------------\n");
printf(" Selamat Datang \n");
printf("-------------------------\n");
printf("Daftar Menu:\n");
printf("1. Input Data Player\n");
printf("2. Tampil Daftar Player\n");
printf("3. Input Data Atribut\n");
printf("4. Tampilkan Data Atribut\n");
printf("5. Keluar\n");
}
int main() {
int pilihan;
while (1) {
menu();
printf("Pilih menu 1, 2,3,4,5: \n");
scanf("%d", &pilihan);
switch (pilihan) {
case 1:
inputPlayerData();
break;
case 2:
playerList();
break;
case 3:
inputAtributData();
break;
case 4:
tampilAtributData();
break;
case 5:
printf("Keluar dari program");

return 0;
default:
printf("Pilihan tidak valid. Silakan pilih lagi.\n");
}
}
return 0;
}
