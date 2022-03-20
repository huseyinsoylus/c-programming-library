/*
Huseyin Soylu - 171418012
Marmara Universitesi Bilgisayar Muhendisligi Bolumu
BLM2002-Veri Yapilari ve Algoritmalar Dersi - Odev4

Asagidaki program stack ve dosya islemleri ile alakali gelistirilmis fonksiyonlari kapsar

Program main fonksiyonuna bir adet .txt uzantili arguman almaktadir. Almis oldugu bu dosyayi 
satir satir okuyarak satirlarin polindrom cumle, kelime, sayi ya da harf olup olmadigini kontrol eder.

Kodlama yapilirken macar notasyonu esas alinmis ve tum degiskenler icin asagida 
belirtilen esaslarda kodlama yapilmistir. 
_____________________________________________________________________________________

------For Variable-----------------
variable = v; tip sonrasi eki
-------------------------------

------Use Case-----------------
integer icin = iv;
char icin =cv;
double icin = dv;
float icin = fv;
-------------------------------
_____________________________________________________________________________________

------For Pointer------------------
pointer = p; tip sonrasi eki
-------------------------------

------Use Case-----------------
int pointer icin = ip;
char pointer icin = cp;
-------------------------------
_____________________________________________________________________________________

------ For Array---------------
array = a; tip sonrasi eki
-------------------------------

------Use Case-----------------
int array = ia;
char array = ca;
-------------------------------
_____________________________________________________________________________________

------For Function-------------
function = f; tip sonrasi eki
-------------------------------

------Use Case-----------------
int geri donuslu fonksiyon = if;
char geri donuslu fonksiyon = cf;

int pointer geri donuslu fonksiyon = ipf;
char pointer geri donuslu fonksiyon = cpf;

geri donussuz fonksiyon icin = vf;
-------------------------------
_____________________________________________________________________________________

------For Function Parameter---
parameter = p;
-------------------------------

------Use Case-----------------
int geri donuslu parametreli fonsiyon = ifp;
int pointer donuslu parametreli fonksiyon = ipfp;

Seklinde tanimlanmistir.
-------------------------------
________________________________________________________________________________________
*/
//--------------------------------------Program Area--------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include <sys/stat.h>

//-------------------------------------Stack Declare--------------------------------------
char* stack;
int top = -1;
//________________________________________________________________________________________

//--------------------------------Stack Functinon Declare---------------------------------
// push function
void push(char value)
{
    stack[++top] = value;
}
 
// pop function
char pop()
{
    return stack[top--];
}
//________________________________________________________________________________________

//--------------------------------Program Functinon Declare-------------------------------

int ifp_is_polindrom(char array[]){

    int length = strlen(array);
 
    // Allocating the memory for the global stack pointer
    stack = (char*)malloc(length * sizeof(char));
 
    // Finding the mid
    int i;
    int iv_array_mid = length / 2;
 
    for (i = 0; i < iv_array_mid; i++) {
        push(array[i]);
    }
 
    // Verilen dizi uzunlugu ikiye tam bolunmuyor ise i ye bir ekle .
    if (length % 2 != 0) {
        i++;
    }

    //Pop function variable
    char cv_stack_pop;

    //while loop: element by element move in array
    while (array[i] != '\0') {

        if(top != -1){
            cv_stack_pop = pop();
        }
        else{
            printf("Stack Overflow - polindrom function failed!\n");
        }

 
        //One character diffirent: Function end
        if (cv_stack_pop != array[i])
            return 0;
        i++;
    }
 
    return 1;
}
//________________________________________________________________________________________

char * cpfp_remove_array_spaces(char *cp_array)
{
    if(cp_array == NULL){
        printf("(!)Pointer: cp_array \n(X)Error: Pointer is not created.\n");
        exit(1);
    }
	int i = 0, j = 0;
	while (cp_array[i])
	{   
        //32 ==> Space Ascii Code
		if (cp_array[i] < 32 && cp_array[i] > 45){
            cp_array[j++] = cp_array[i];
        }
          
		i++;
	}
	cp_array[j] = '\0';
	return cp_array;
}
//________________________________________________________________________________________
void vfp_read_file_line(const char * ccp_file_path, FILE * fp){

    if(ccp_file_path == NULL){
        printf("(!)Pointer: ccp_file_path \n(X)Error: Pointer is not created.\n");
        exit(1);
    }
    if(fp == NULL){
        printf("(!)Pointer: fp \n(X)Error: Pointer is not created.\n");
        exit(1);
    }

    if((fp = fopen(ccp_file_path, "r")) != NULL){

        struct stat sb;
        stat(ccp_file_path, &sb); 

        //sb.st_size --> Size of file
        //printf("%ld",sb.st_size);

        char *cp_file_contents = malloc(sb.st_size);
        if(cp_file_contents == NULL){
            printf("(!)Function: vfp_read_file_line \n(X)Error: cp_file_contents pointer is not created\n");
            exit(1);
        }

        while (fscanf(fp, "%[^\n] ", cp_file_contents) != EOF) {
            printf(">Is -%s-  Polindrom ==> ", cp_file_contents);
            
            //Function: Remove space in array
            cp_file_contents = cpfp_remove_array_spaces(cp_file_contents);
            
            //Polindrom control function
            if (ifp_is_polindrom(cp_file_contents)) {
                printf("Yes");
            }
            else {
                printf("No");
            }
            printf("\n");

        }

        fclose(fp);
    }
    else{
        printf("(!)Function: vfp_read_file_line \n(X)Error: File not found or open file error.\n");
    }
}


//-----------------------------------Main Area-------------------------------------------

int main(int argc, char*argv[]){

    if(argc != 2){
        printf("The program have an parameter. The parameter is file path.\n");
        exit(1);
    }
    const char * ccp_file_path = argv[1];
    FILE * fp = malloc(sizeof(FILE*));

    if(fp == NULL){
        printf("(!)Pointer: fp \n(X)Error: Pointer is not created.\n");
        exit(1);
    }

    vfp_read_file_line(ccp_file_path, fp);
    
    printf("\n__________________________________________________________________________\n\n");
    printf("Program kucuk buyuk harf duyarli ve noktalama isaretlerini yok saymaktadir.");
    printf("\n__________________________________________________________________________\n");
    return 0;

}

