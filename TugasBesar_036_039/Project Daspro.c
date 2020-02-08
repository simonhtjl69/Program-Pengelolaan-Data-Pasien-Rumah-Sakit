#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tambahData (FILE *fp);
void lihatData (FILE *fp);
void bayarData (FILE *frs);

char nama [100];
char alamat [100];
char golonganDarah [100];
char status [100];
char penyakit[100];
char jenisKamar[100];

int kamar;
int total;
int vvip=3, vip=2, gen=1;
int hari;
char setuju;

int main(){
	int option;

	FILE *fp;
	FILE *frs;
	
	if((fp = fopen("project.txt", "r+"))==NULL){
		puts("========================");
		puts("||	FATAL ERROR!	||");
		puts("========================");
		puts("\nUnable to open File");
		return 0;
	}

	if((frs = fopen("bayar.txt", "r+"))==NULL){
		puts("========================");
		puts("||	FATAL ERROR!	||");
		puts("========================");
		puts("\nUnable to open File");
		return 0;
	}	
	while(1){
		system("cls");
		printf("=====================================\n");
		printf("||   Welcome To RSUD HKBP Balige   ||\n");
		printf("=====================================\n");
		printf("||Pilihan:                         ||\n");                      
		printf("||1. Tambah Pasien                 ||\n");
		printf("||2. Daftar Pasien                 ||\n");
		printf("||3. Biaya Kamar                   ||\n");
		printf("||4. Keluar                        ||\n");
		printf("=====================================\n\n");

		printf("Pilihan Anda : ");
		scanf("%d", &option);
		
		if(option == 1){
			tambahData(fp);
			fclose(fp);
			fp = fopen ("Project.txt", "r+");
		}
		
		if(option == 2){
			lihatData(fp);
			fclose(fp);
			fp = fopen ("Project.txt", "r+");
		}
		if(option == 3){
			bayarData(frs);
			fclose(frs);
			frs = fopen ("bayar.txt", "r+");
		}
		
		if(option == 4){
			system("cls");
			printf("=====================================\n");
			printf("||         terima kasih :)         ||\n");
			printf("=====================================\n");
			fclose(fp);
			
		}
	}
	return 0;
}

void tambahData(FILE *fp){
	system("cls");
	printf("=====================================\n");
	printf("||Tambah Pasien                    ||\n");
	printf("=====================================\n");			
	while (getc(fp) !=EOF);
		printf("Nama Pasien	: ");
		scanf("%s", nama);
		printf("Alamat Pasien	: ");
		scanf("%s", alamat);
		printf("Golongan Darah	: ");
		scanf("%s", golonganDarah);
		printf("Status Pasien	: ");
		scanf("%s", status);
		printf("Penyakit Pasien	: ");
		scanf("%s", penyakit);
		printf("Status Kamar	: ");
		scanf("%s", jenisKamar);

	fprintf(fp, "%s%10s%10s%10s%10s%10s\n", nama,alamat,golonganDarah,status,penyakit,jenisKamar);
	printf("Data Telah Tersimpan!\n");  
	printf("\nPress Any Key To Continue!\n");
	getch();
}

void lihatData(FILE *fp){
	system("cls");
	printf("=====================================\n");
	printf("||Daftar Pasien                    ||\n");
	printf("=====================================\n");			
	do{
		fscanf(fp, "%s%s%s%s%s%s\n",nama,alamat,golonganDarah,status,penyakit,jenisKamar);
		printf("Nama Pasien	: %s\n", nama);
		printf("Alamat Pasien	: %s\n", alamat);
		printf("Golongan Darah	: %s\n", golonganDarah);
		printf("Status Pasien	: %s\n", status);
		printf("Penyakit Pasien	: %s\n", penyakit);
		printf("Status Kamar	: %s\n\n", jenisKamar);
	}while (!feof(fp));
		printf("\nPress Any Key To Continue!\n");
		getch();
}

void bayarData(FILE *frs){
	system("cls");
	printf("=====================================\n");
	printf("||Pembayaran Kamar                 ||\n");
	printf("=====================================\n");			
	printf("Jenis kamar apa yang digunakan pasien : \n");
	printf("\n1. Kamar VVIP\n2. Kamar VIP\n3. General\n\n");
	printf("Masukkan pilihan Anda : ");
	kamar = getch();

switch (kamar){ 
	case '1':
		printf("Harga sewa kamar Rp 3.000.000,00 @hari\n");
		printf("Bayar sekarang? (Y/N)\n");
		setuju = getch();
		
			switch (setuju){
				case 'y':
					frs = fopen("bayar.txt","a+");
					printf("\nBerapa hari hari Pasien dirawat : \n");
					scanf("%d",&hari);
					total=hari*vvip;
					printf("\nTotal Biaya Yang Pasien Bayar : %d juta",total);
					fprintf(frs,"Harga sewa kamar pasien selama %d hari = %d juta rupiah\n",hari,total);
					fclose (frs);
					getch();
				break;
			
				case 'n':
				printf("Maaf ya..");
				break;
			}break;
		
	case '2':
		printf("Harga sewa kamar Rp 2.000.000,00 @hari\n");
		printf("Lanjut pembayaran? (Y/N)\n");
		setuju = getch();
		
			switch (setuju){
				case 'y':
					frs = fopen("bayar.txt","a+");
					printf("\nBerapa hari hari Pasien dirawat : \n");
					scanf("%d",&hari);
					total=hari*vip;
					printf("\nTotal Biaya Yang Pasien Bayar : %d juta",total);
					fprintf(frs,"\nAnda telah memilih kamar VIP\nHarga sewa kamar Rp 2.000.000,00 @hari\nselama %d hari\ndengan biaya %d juta rupiah\n",hari,total);
					fclose (frs);
					getch();
				break;
			
				case 'n':
				printf("Maaf ya..");
				break;
			}break;
		
	case '3':
		printf("Harga sewa kamar Rp 1.000.000,00 @hari\n");
		printf("Lanjut pembayaran? (Y/N)\n");
		setuju = getch();
		
			switch (setuju){
				case 'y':
					frs = fopen("bayar.txt","a+");
					printf("\nBerapa hari Pasien dirawat : ");
					scanf("%d",&hari);
					total =hari*gen;
					printf("\nTotal Biaya Yang Pasien Bayar : %d juta",total);
					fprintf(frs,"\nAnda telah memilih kamar VIP\nHarga sewa kamar Rp 1.000.000,00 @hari\nselama %d hari\ndengan biaya %d juta rupiah\n",hari,total);
					getch();
					fclose (frs);
				break;
				
				case 'n':
				printf("Maaf Silahkan Anda Keluar..");
				break;
			}break;
			getch();
	}
}
