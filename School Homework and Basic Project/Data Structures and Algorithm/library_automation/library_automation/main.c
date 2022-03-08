#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Structer field*/
/*Struct kullnaırken ilk değer ataması yapılamaz.*/
struct kullanici{
	int * kullanici_id;
	char * kullanici_adi;
	char * sifre;
	int * odunc_durumu;
	char * alinan_tarih;
	int * alinan_kitap_id;
};

struct gorevli{
	int gorevli_id;
	char* gorevli_kullanici_adi;
	char* gorevli_sifre;
};

struct kutuphane{
	int kitap_id;
	char* kitap_adi;
	int kitap_odunc_durumu;
	char*kitap_odunc_alan;
	char*kitap_odunc_tarih;
};
/*Structer field*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*gorevli functions*/
int kitap_odunc_ver(int kitap_id,int kullanici_id){
	//Dosya yazma konusunda hata almadığım halde dosyaya yazmıyor.
}
int kitap_geri_al(int kitap_id,int kullanici_id){
	
}
void kullanicilari_goster(FILE * kullanici_dosyasi,char * dosya_adi){ //Herhangi bir dosyanın içinde ne varsa satır satır gösterir.
	
	if(kullanici_dosyasi=fopen(dosya_adi,"r")){
		while(! feof(kullanici_dosyasi) ){
    		putchar(fgetc(kullanici_dosyasi));
  		}
		
	}
	
}

void kitaplari_goster(FILE * kutuphane_dosyasi,char * dosya_adi){ //Herhangi bir dosyanın içinde ne varsa satır satır gösterir.
	
	if(kutuphane_dosyasi=fopen(dosya_adi,"r")){
		while(! feof(kutuphane_dosyasi) ){
    		putchar(fgetc(kutuphane_dosyasi));
  		}
		
	}
	
}

void kullanici_kaydet(char* kayit_adi, char * kayit_sifre, FILE * kullanici_dosyasi,char * dosya_adi){
	/*
	Fonksiyon parça olarak başka bir programa konulduğunda çalışmaktadır
	ancak programda stream ile alakalı hatalı kodlamalar yapmış olma 
	ihtimalim yüksek. Program aktif bir şekilde çalışmakta ancak dosya
	içerisine değeri yazdırmamaktadır.
	*/
	char kodlanmis_kullanici_adi [50] = "*ch085ch*";
	strcat(kodlanmis_kullanici_adi,kayit_adi);	
	char kodlanmis_sifre [50]= "*ch083ch*";
	strcat(kodlanmis_sifre,kayit_sifre);
	strcat(kodlanmis_kullanici_adi,kodlanmis_sifre);
	
	printf("%s",kodlanmis_kullanici_adi);
	
	if(kullanici_dosyasi=fopen(dosya_adi,"a")){//Dosya ekleme modunda açıldı.
		fputs(kodlanmis_kullanici_adi,kullanici_dosyasi);
	}
	else{
		
	}
}

/*gorevli functions*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Kullanıcı functions



//Kullanıcı functions

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//system functions
int kullanici_login(char * kullanici_adi, char * kullanici_sifre,FILE * kullanici_bilgileri, char * dosya_adi){
	
		/*
		Kullanicilar kullanicilar.txt dosyasında kayıtlıdırlar.
		Kullanici adlarının önünde *ch085ch* ön eki bulunmaktadır ve kullanıcı isimleri buna göre aranmaktadır.
		Kullanici şifrelerinin önünde *ch083ch* ön eki bulunmaktadır ve buna göre şifreler aranmaktadır.
		*/
	
		int sifre_dogru_yanlis=0;
	
		char kodlanmis_kullanici_adi [30] = "*ch085ch*";
		strcat(kodlanmis_kullanici_adi,kullanici_adi);//Kullanıcının girdiği kullanıcı adına özel kod parametresini ekledim		
		char kodlanmis_sifre [30]= "*ch083ch*";
		strcat(kodlanmis_sifre,kullanici_sifre);//Kullanıcının girdiği şifreye özel kod parametresini ekledim
				
		strcat(kodlanmis_kullanici_adi,kodlanmis_sifre);//Sonra kullanıcı adı ve parolayı birleştirdim.
		
		
        //printf("%s",kodlanmis_kullanici_adi);	//Kodlanmış şifrenin kontolü için ekrana basma	
		
		
		char * kullanici_sifresi_txt=malloc(sizeof(char)*50);
		
		
		if (kullanici_bilgileri = fopen(dosya_adi,"r")) {
			
        	rewind(kullanici_bilgileri);//Dosyanın başına gel.
        	
        	while(!feof(kullanici_bilgileri)){
        		
        		
        		int okunan=0;
        		okunan = fread(kullanici_sifresi_txt,sizeof(char),(sizeof(char)*strlen(kodlanmis_kullanici_adi)),kullanici_bilgileri);
        		fseek(kullanici_bilgileri,(1-okunan), SEEK_CUR );
        		if(okunan>0){
					if(kullanici_sifresi_txt[okunan]!=0){
					kullanici_sifresi_txt[okunan]=0;
					}
				}
				else if(okunan<(strlen(kodlanmis_kullanici_adi))){
					break;
				}      		
        		//printf("\n%s && %d",yonetici_sifresi_txt,okunan); //Dosya içerisinde gezinmeyi kontrol etmek için
        		
        		if(strcmp(kullanici_sifresi_txt,kodlanmis_kullanici_adi)==0){
        			sifre_dogru_yanlis =1;
				}
        		
			}
    	}
    	
		else{
    		printf("Dosya acilirken bir sorunla karsilasildi");
		}
    	
    	fclose(kullanici_bilgileri);//Kullanici şifrelerinin olduğu dosyayı kapatır.
		free(kullanici_sifresi_txt);//Pointer belleğe geri ver.
		
		if(sifre_dogru_yanlis==1){
			return 1;
		}
		else{
			return 0;
		}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int yonetici_login(char * yonetici_adi, char * yonetici_sifre,FILE * yonetici_bilgileri, char * dosya_adi){
	
		/*
		Yöneticiler yoneticiler.txt dosyasında kayıtlıdırlar.
		Yönetici adlarının önünde *ch085ch* ön eki bulunmaktadır ve kullanıcı isimleri buna göre aranmaktadır.
		Yönetici şifrelerinin önünde *ch083ch* ön eki bulunmaktadır ve buna göre şifreler aranmaktadır.
		*/
	
		int sifre_dogru_yanlis=0;
	
		char kodlanmis_kullanici_adi [30] = "*ch085ch*";
		strcat(kodlanmis_kullanici_adi,yonetici_adi);//Kullanıcının girdiği kullanıcı adına özel kod parametresini ekledim		
		char kodlanmis_sifre [30]= "*ch083ch*";
		strcat(kodlanmis_sifre,yonetici_sifre);//Kullanıcının girdiği şifreye özel kod parametresini ekledim
				
		strcat(kodlanmis_kullanici_adi,kodlanmis_sifre);//Sonra kullanıcı adı ve parolayı birleştirdim.
		
		
        //printf("%s",kodlanmis_kullanici_adi);	//Kodlanmış şifrenin kontolü için ekrana basma	
		
		
		char * yonetici_sifresi_txt=malloc(sizeof(char)*50);
		
		
		if (yonetici_bilgileri = fopen(dosya_adi,"r")) { //Dosya açılırken bir sorunla karşılaştı mı ?
			
        	rewind(yonetici_bilgileri);//Dosyanın başına gel.
        	
        	while(!feof(yonetici_bilgileri)){
        		
        		
        		int okunan=0;
        		okunan = fread(yonetici_sifresi_txt,sizeof(char),(sizeof(char)*strlen(kodlanmis_kullanici_adi)),yonetici_bilgileri);
        		fseek(yonetici_bilgileri,(1-okunan), SEEK_CUR );
        		if(okunan>0){
					if(yonetici_sifresi_txt[okunan]!=0){
					yonetici_sifresi_txt[okunan]=0;
					}
				}
				else if(okunan<(strlen(kodlanmis_kullanici_adi))){
					break;
				}      		
        		//printf("\n%s && %d",yonetici_sifresi_txt,okunan); //Dosya içerisinde gezinmeyi kontrol etmek için
        		
        		if(strcmp(yonetici_sifresi_txt,kodlanmis_kullanici_adi)==0){
        			sifre_dogru_yanlis =1;
				}
        		
			}
        
    	}
    	else{
    		printf("Dosya acilirken bir sorunla karsilasildi");
		}
    	
    	fclose(yonetici_bilgileri);//Yönetici şifrelerinin olduğu dosyayı kapatır.
		free(yonetici_sifresi_txt);//Pointer belleğe geri ver.
		
		if(sifre_dogru_yanlis==1){
			return 1;
		}
		else{
			return 0;
		}
}
//system functions
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
	
	char *cikis = malloc(sizeof(char)*6);//Kullanıcı programın herhangi bir anında çıkış yapabilir.
	*cikis="";
	while(strcmp(cikis,"cikis")!=0){//Kullanıcı çıkmadığı sürece program sonsuza kadar çalışacaktır.

	//char *giris_mi_kayit_mi="0";  
	char *kullanici_tipi = malloc(sizeof(char)*15);
	
	//Gelen kullanıcının yönetici mi yoksa kütüphane kullanıcısı mı olduğunu belirliyoruz.
	printf("--------------------------------------------------------------\n");
	printf("Kullanici olarak giris islemi icin: 1\nYonetici olarak giris yapmak icin: 2\nProgrami sonlandirmak icin 'cikis' yazin.");
	printf("\n--------------------------------------------------------------\nDegeri girin:");
	scanf("%s",kullanici_tipi);
	cikis=kullanici_tipi;
	
	//------------------------------------------------------------------------------------------Kullanıcı İşlemleri---------------------------------------------------------------------------------------------------------
	if(strcmp(kullanici_tipi,"1")==0){ //Kullanıcı olarak giriş yapmak isteyenler için yapılacak işlemler.
		
		char * kullanici_adi = malloc(sizeof(char)*30);
		char * kullanici_sifre = malloc(sizeof(char)*30);
		
		printf("Hosgeldin Yonetici lutfen kullanici adini gir:");
		scanf("%s",kullanici_adi);
		printf("\nHosgeldin %s\nSifreninizi girin:",kullanici_adi);
		scanf("%s",kullanici_sifre);
		
		
		FILE * kullanici_bilgileri; //FILE tipinde bir dosya pointeri
		if(kullanici_login(kullanici_adi,kullanici_sifre,kullanici_bilgileri,"kullanici.txt")==1){
			printf("\nParola Dogru\n");
		}
		else{
			printf("\nParola Yanlis\n");
		}
			
	}	
	//------------------------------------------------------------------------------------------Yönetici İşlemleri---------------------------------------------------------------------------------------------------------		
			
	else if(strcmp(kullanici_tipi,"2")==0){//Yönetici olarak giriş yapmak isteyenler için yapılacak işlemler.
	
		char * yonetici_adi = malloc(sizeof(char)*30);
		char * yonetici_sifre = malloc(sizeof(char)*30);
		printf("--------------------------------------------------------------\n");
		printf("Hosgeldin Yonetici lutfen kullanici adini gir:");
		scanf("%s",yonetici_adi);
		printf("Hosgeldin %s Sifreninizi girin:",yonetici_adi);
		scanf("%s",yonetici_sifre);
		printf("--------------------------------------------------------------\n");
		
		//Yonetici adı ve şifresi kontrolü
		FILE * yonetici_bilgileri; //FILE tipinde bir dosya pointeri
		if(yonetici_login(yonetici_adi,yonetici_sifre,yonetici_bilgileri,"yonetici.txt")==1){
			
			printf("Parola Dogru\n");
			
			
			int yonetici_menusu_secim = 0;
			
			while(yonetici_menusu_secim!=6){
				printf("--------------------------------------------------------------\n");
				printf("Yeni kullanici kaydetmek icin:1\nKullanicilarin bilgilerini gormek icin:2\nYeni kitap kaydi icin:3\nKitap silmek icin:4\nKitap odunc vermek icin:5\nKitaplari listelemek icin:6\nMenuden cikmak icin:7.");
				printf("\n--------------------------------------------------------------\nDegeri girin:");
				scanf("%d",&yonetici_menusu_secim);
				
				//Yoneticinin girdisine göre seçimler ve işlemler
				if(yonetici_menusu_secim == 1){
					FILE * dosya;
					char *kayit_adi=malloc(sizeof(char)*15);
					char * kayit_sifre= malloc(sizeof(char)*15);
					printf("Kaydetmek istediginiz kullanici adi ve sifreyi arada bir karakter bosluk olacak sekilde yan yana giriniz:\n");
					scanf("%s",kayit_adi);
					kullanici_kaydet(kayit_adi,kayit_sifre,dosya,"kullanici.txt");
					printf("Kullanicilar basari ile kaydedildi.\n");
				}
				else if(yonetici_menusu_secim == 2){
					FILE * kullanici_dosyasi;	
					kullanicilari_goster(kullanici_dosyasi,"kullanici.txt");
					printf("\nTum kullanici gosterildi.\n");
				}
				else if(yonetici_menusu_secim == 3){
					printf("Yeni kitaplar kaydedildi.\n");
				}
				else if(yonetici_menusu_secim == 4){
					printf("Kitap silindi.\n");
				}
				else if(yonetici_menusu_secim == 5){
					printf("Kitap odunc verildi.\n");
				}
				else if(yonetici_menusu_secim == 6){
					FILE * kutuphane_dosyasi;
					kitaplari_goster(kutuphane_dosyasi,"kutuphane.txt");
					printf("\nKitaplar listelendi.\n")
				}
				else if(yonetici_menusu_secim == 7){
					printf("Gorusuruz tekrar bekleriz bro.\n");
				}
				else{
					printf("Seciminiz yanlis.\n");
				}			
			}	
		}
		else{
			printf("\nParola yanlis\n");
		}
		//-------------------------------
		
		
		
		
		
	}
	else if(strcmp(cikis,"cikis")==0){
		printf("\nGorusuruz Bro tekrar bekleriz");
	}
	else{
		printf("Girdiginiz Deger --> %s \nGirdiginiz degerler gecersizdir.\n",cikis);
		printf("--------------------------------------------------------------\n");
	}
	
	
	}
	
}

