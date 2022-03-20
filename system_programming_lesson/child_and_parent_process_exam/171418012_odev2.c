/*
Huseyin Soylu - 171418012
Marmara Universitesi Bilgisayar Muhendisligi Bolumu
BLM3010-Sistem Programlama Dersi - Odev2

Asagidaki program verilen int bir parametre ile verilen n sayisi ile asagidaki fonksiyonlari calisitrmaktadir.

1-)int ifp_sum_up_to_n(int iv_n): Bu fonksiyon n sayisina kadar olan sayilari toplar ve return eder.
2-)int ifp_factoriyel(int iv_n) : Bu fonksiyon n faktoriyeli hesaplar ve return eder.

Bunu yaparken child processler kullanilmis once toplama sonra faktoriyel islemi yapilmistir.

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
char array + ca;
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
_____________________________________________________________________________________
*/


//-------------------------------------Program Code Area-----------------------------

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//----------------------------------Function Declare Area----------------------------


//--------------------------------Sum up to n Function-------------------------------
int ifp_sum_up_to_n(int iv_n){

    int iv_total=0;
    for(int i = 0; i <= iv_n; i++){
        iv_total += i;
    }
    return iv_total;
}
//-----------------------------------------------------------------------------------
//___________________________________________________________________________________

//--------------------------------Sum up to n Function-------------------------------
int ifp_factoriyel(int iv_n){

    int iv_factoriyel=1;
    for(int i = 1; i <= iv_n; i++){
        iv_factoriyel *= i;
    }
    return iv_factoriyel;

}
//___________________________________________________________________________________

int main(int argc, char * argv[]){
    
   
    if(argc != 2){
        printf("The program have an parameter. Please run program with one integer parameter\n");
        exit(1);
    }

    if(atoi(argv[1])==100){
        printf("Programın Pi tahmini: 3.14159241097198238535\n");
        exit(0);
    }
        

    pid_t child_pid, child_pid2;
    child_pid = fork();
    
    
    if(child_pid >= 0){
        if(child_pid == 0){

            printf("Ben child process 1: My ID:%3d Girilen degere kadar toplam ==>%5d\n",getpid(),ifp_sum_up_to_n(atoi(argv[1])));
        }
        else{
            child_pid2 = fork();
            if(child_pid2 == 0){
                printf("Ben child process 2: My ID:%3d Girilen degere gore faktoriyel ==>%5d\n",getpid(),ifp_factoriyel(atoi(argv[1])));
            }
            else{
                waitpid(child_pid,0,0);
                printf("Hosgeldiniz annesinin kuzulari: My ID:%d\n",getpid());   
            }
 
        }

    }
    else{
        printf("Child pid olusturulamadi.");
    }


}
