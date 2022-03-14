/*
Huseyin Soylu - 171418012
Marmara Universitesi Bilgisayar Muhendisligi Bolumu
BLM3010-Sistem Programlama Dersi - Odev1

Asagidaki program verilen .txt uzantili dosyalari 40 byte lik parcalar 
halinde okur ve ekrana yazdirir.
Ilk 40 byte direkt olarak yazilir diger tum 40 bytlik parcalar fonksiyon
kullanilarak tersine cevrilir ve o sekilde ekrana yazdirilir.

Kodlama yapilirken macar notasyonu esas alinmis ve tum degiskenler icin asagida 
belirtilen esaslarda kodlama yapilmistir. 
_____________________________________________________________________________________

------For Variable-----------------
variable = v; tip sonrasi eki
-------------------------------

------Use Case-----------------
integer icin = i_v;
char icin =c_v;
double icin = d_v;
float icin = f_v;
-------------------------------
_____________________________________________________________________________________

------For Pointer------------------
pointer = p; tip sonrasi eki
-------------------------------

------Use Case-----------------
int pointer icin = i_p;
char pointer icin = c_p;
-------------------------------
_____________________________________________________________________________________

------ For Array---------------
array = a; tip sonrasi eki
-------------------------------

------Use Case-----------------
int array = i_a;
char array + c_a;
-------------------------------
_____________________________________________________________________________________

------For Function-------------
function = f; tip sonrasi eki
-------------------------------

------Use Case-----------------
int geri donuslu fonksiyon = i_f;
char geri donuslu fonksiyon = c_f;

int pointer geri donuslu fonksiyon = i_p_f;
char pointer geri donuslu fonksiyon = c_p_f;

geri donussuz fonksiyon icin = v_f;
-------------------------------
_____________________________________________________________________________________

------For Function Parameter---
parameter = p;
-------------------------------

------Use Case-----------------
int geri donuslu parametreli fonsiyon = i_f_p;
int pointer donuslu parametreli fonksiyon = i_p_f_p;

Seklinde tanimlanmistir.
-------------------------------
_____________________________________________________________________________________
*/


//-------------------------------------Program Code Area-------------------------

#include<stdio.h>
#include<stdlib.h>

//----------------------------------Function Declare Area-------------------------

//--------------------------------Reverse Array Function-----------------------------
void vfp_reverse_char_array(char* cp_char_array, int iv_char_count){
for(int i=iv_char_count;i>0;i--){
    printf("%c",cp_char_array[i]);
}
printf("\n");
}
//-----------------------------------------------------------------------------------
//___________________________________________________________________________________

//--------------------------------40 Bytes Part out Screen Function-----------------------------
void vfp_40_bytes_puts_screen(char* cp_file_path, FILE * fp_file_pointer, char* cp_40_byte_temp){

    int iv_while_count=0;
    //------------------------------open file control--------------------------------
    if((fp_file_pointer=fopen(cp_file_path,"r"))!=NULL){
    //printf("Dosya basari ile acildi");

    //-------------------------get data only 40 bytes--------------------------------
    while(fread(cp_40_byte_temp,sizeof(char),40,fp_file_pointer)==40){
        iv_while_count++;

        if(iv_while_count == 1){
            printf("%s\n",cp_40_byte_temp);
        }else{
            vfp_reverse_char_array(cp_40_byte_temp,40);
        }

        
    }

    if(iv_while_count == 0){
    printf("File lenght is not 40 bytes!!\n");
    exit(0);
    }


    fclose(fp_file_pointer);
    }
    else{
    printf("File is not opening\n");
    exit(1);
    }


}

//__________________________________MAIN FUNCTIONS______________________________________

int main(int argc, char *argv[])
{


//---------------------------Invalid parameter control---------------------------
if(argc != 1){ 
printf("Program doesn't have a parameter. Please not argument compile.\n");
return 0;
}

//------------------------------char pointer temp--------------------------------
char * cp_40_byte_temp = malloc(sizeof(char)*41);

if(cp_40_byte_temp == NULL){
printf("Memory create failed!!!");
exit(1);
}

//-------------------------------file pointer------------------------------------
FILE *fp_file_pointer = malloc(sizeof(FILE));

if(fp_file_pointer == NULL){
printf("Memory create failed!!!");
exit(1);
}

//-------------------------------file path pointer-------------------------------
char* cp_input_file_path = malloc(sizeof(char)*100);
if(cp_input_file_path == NULL){
printf("Memory create failed!!!");
exit(1);
}


printf("Input file path:");
scanf("%s",cp_input_file_path);

vfp_40_bytes_puts_screen(cp_input_file_path, fp_file_pointer, cp_40_byte_temp);


free(cp_40_byte_temp);
free(fp_file_pointer);

free(cp_input_file_path);


}
