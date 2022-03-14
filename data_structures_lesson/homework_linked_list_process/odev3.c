/*
Huseyin Soylu - 171418012
Marmara Universitesi Bilgisayar Muhendisligi Bolumu
BLM2002-Veri Yapilari ve Algoritmalar Dersi - Odev3

Asagidaki program bagli listeler ile alakali gelistirilmis fonksiyonlari kapsar

1-) 1. fonksiyon iki adet baglantili listeyi birbirine baglamakta.
2-) 2. fonksiyon sirali bir baglantili listeye eleman ekleme ve eklenen elemana gore tekrar siralama
3-) 3. fonksiyon sirali bir liste parametresi alip medyan donduruyor.
4-) 4. Fonksiyon baglantili bir listedeki dugumleri tersine ceviriyor.

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
________________________________________________________________________________________
*/

//-------------------------------Program Code Area--------------------------------------

#include <stdio.h>
#include <stdlib.h>


//-------------------------------Struct Declaration--------------------------------------
struct node 
{
    int value;                     //Data of the node
    struct node *nextptr;           //Address of the next node
}*root;
//_________________________________________________________________________________________

//-------------------------------Functions Declaration-----------------------------------

void vfp_create_linked_list(struct node *root, int iv_list_lenght){

    if(root == NULL){
        printf("Olusuturulacak bagli liste icin bellek ayrilmamis");
        exit(1);
    }  

    struct node * tmp = malloc(sizeof(struct node *));
    if(tmp == NULL){
        printf("tmp degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }

    tmp = root;
    
    if(root != NULL && root->nextptr == NULL){

        for(int i = 1;i<=iv_list_lenght;i++){
    
        struct node * sp_new_node = malloc(sizeof(struct node *));
        tmp->nextptr = sp_new_node;
        sp_new_node->value = i*5;
        tmp = sp_new_node; 
        }

    }
    else{
    
        printf("Root pointeri bos ya da root bir liste su anda ici bos degil!!");
    }   
}
//_________________________________________________________________________________________

void vfp_print_linked_list(struct node * root){

    if(root == NULL){
        printf("Ekrana basilacak liste bos!!");
        exit(1);
    }  

	struct node * tmp = malloc(sizeof(struct node *));
    if(tmp == NULL){
        printf("tmp degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    tmp = root;
    int i=1;
	while(tmp != NULL){
	    printf("%d. Deger = %5d\n",i,tmp->value);
	    tmp=tmp->nextptr;
        i++;

	}

}

//__________________________________________________________________________________________

void vf_concatenate_linked_list(struct node * list1, struct node * list2){

    if(list1 == NULL || list2 == NULL){
        printf("Birlestirme icin gonderilen listelerde bos var!!");
        exit(1);
    }  

    struct node *tmp_list1 = malloc(sizeof(struct node*));
    if(tmp_list1 == NULL){
        printf("tmp_list1 degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }

	tmp_list1=list1;

	while(tmp_list1->nextptr != NULL){
		tmp_list1=tmp_list1->nextptr;
	}
    tmp_list1->nextptr = list2;
}
//_________________________________________________________________________________________

void vf_add_short_linked_list(struct node * list, int add_value){

    if(list == NULL){
        printf("Siralama icin gonderilen liste bos!!");
        exit(1);
    }  

    struct node *tmp_list = malloc(sizeof(struct node*));
    struct node *add_node = malloc(sizeof(struct node*));
    if(tmp_list == NULL || add_node == NULL){
        printf("tmp_list1 ya da add_node degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    add_node->value = add_value;
	tmp_list=list;

    struct node *first = malloc(sizeof(struct node*));
    struct node *end = malloc(sizeof(struct node*));
    if(first == NULL || end == NULL){
        printf("first ya da end degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }

    //Oncelikle ekleme nereye yapilacak onu belirliyorum.
    int * ip_begin_mid_end= malloc(sizeof(int)); 

    //Eklenecek deger eger tum degerlerden kucukse bunu dongunun ilk donusunde belirlemem lazim.
    int iv_while_count=1;

	while(tmp_list->nextptr != NULL){
        
        //(1)Eger ekleyecegim degisken listenin ilk elemanindan kucukse ve dongu 1 kez calistiysa
        //(2)Ekleyecegim degerin nextptr si listenin ilk elemanidir. 
        if(add_value < tmp_list->value && iv_while_count == 1){
            first = tmp_list; //(1) 
            *ip_begin_mid_end = 1; //(2) 
        }

        else if((tmp_list->value) <= add_value &&  add_value <=(tmp_list->nextptr->value) ){ //Arasina yerlestirme
            first = tmp_list;
            end = tmp_list->nextptr;
            *ip_begin_mid_end = 2;
        }

              
		tmp_list=tmp_list->nextptr;
        iv_while_count++;
	}

    if(*ip_begin_mid_end == 2){
        first->nextptr = add_node;
        add_node->nextptr = end;
        vfp_print_linked_list(list);
    }
    else if(*ip_begin_mid_end == 1){
        add_node->nextptr = first;
        vfp_print_linked_list(add_node);
    }
    else{
        tmp_list->nextptr = add_node;
        vfp_print_linked_list(list);
    }
}

//_________________________________________________________________________________________

double dfp_list_median_calculate(struct node * short_list){
    
    if(short_list == NULL){
        printf("Medyan hesaplamasi icin gonderilen liste bos!!");
        exit(1);
    }    
    
    struct node * tmp = malloc(sizeof(struct node *));
    if(tmp == NULL){
        printf("tmp degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    tmp = short_list;
    int iv_list_count=0;
	while(tmp != NULL){
	    tmp=tmp->nextptr;
        iv_list_count++;
	}
    
    struct node * tmp2 = malloc(sizeof(struct node *));
    if(tmp2== NULL){
        printf("tmp2 degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    tmp2 = short_list;
    
    if(iv_list_count % 2 ==0){
        int j=1;
	    while(tmp2 != NULL){
            if(j == (iv_list_count/2)){
                return (((double)tmp2->value + (double)tmp2->nextptr->value) / 2);
            }
	        tmp2=tmp2->nextptr;
            j++;

	    }
    }
    else{
        int j=1;
	    while(tmp2 != NULL){
            if(j == (iv_list_count/2)){
                return ((double)tmp2->nextptr->value);
            }
	        tmp2=tmp2->nextptr;
            j++;

	    }
    }
}

//_________________________________________________________________________________________

//_________________________________________________________________________________________

void vfp_reverse_linked_list(struct node * list){

    if(list == NULL){
        printf("Tersine dondurulmesi icin gonderilen liste bos!!");
        exit(0);
    }    
    
    struct node * tmp = malloc(sizeof(struct node *));
    if(tmp == NULL){
        printf("(reverse_linked_list)tmp degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }

    struct node * sp_temporary1 = malloc(sizeof(struct node *));
    if(sp_temporary1 == NULL){
        printf("(reverse_linked_list)sp_temporary1 degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    struct node * sp_temporary2 = malloc(sizeof(struct node *));
    if(sp_temporary2 == NULL){
        printf("(reverse_linked_list)sp_temporary2 degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    tmp = list;
    sp_temporary1 = NULL;

	while(tmp != NULL){
        sp_temporary2 = tmp;
	    tmp=tmp->nextptr;
        sp_temporary2->nextptr = sp_temporary1;
        sp_temporary1=sp_temporary2;
	}
    list = sp_temporary1;

    vfp_print_linked_list(list);
}




//_________________________________________________________________________________________

int main(int argc, char *argv[]){

    /*
    root = malloc(sizeof(struct node*));            //Ilk baslangicin bellekte olusturulmasi. -- Bunu struct tanimi yaparken olusturdum havadan gelmedi.
    root->value = 0;                               //Root baslangic verisi
    vfp_create_linked_list(root,5);
    vfp_print_linked_list(root);
    printf("-----------------1. Liste-----------------\n");
    */

    if(argc != 1){
        printf("The Program have not parameter. Please not parameters run!\n");
        exit(1);
    }


//_________________________________________________________________________________________________________________

    //--Liste 1 Olusturulmasi ve ekrana basilmasi
    struct node * sp_list1 = malloc(sizeof(struct node*));
    if(sp_list1 == NULL){
        printf("tmp_list1 degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }

    vfp_create_linked_list(sp_list1,3);
    printf("-----------------1. Liste-----------------\n");
    vfp_print_linked_list(sp_list1);


    //--Liste 2 Olusturulmasi ve ekrana basilmasi
    struct node * sp_list2 = malloc(sizeof(struct node*));
    if(sp_list2 == NULL){
        printf("sp_list2 degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }

    vfp_create_linked_list(sp_list2,2);
    printf("-----------------2. Liste-----------------\n");
    vfp_print_linked_list(sp_list2);

    //--Birlestirme fonksiyonunun kullanilmasi ve ekrana basilmasi

    vf_concatenate_linked_list(sp_list1, sp_list2);

    printf("-----------------Birlestitilmis 1. Liste-----------------\n");
    vfp_print_linked_list(sp_list1);
//_________________________________________________________________________________________________________________

    //--Sirali liste olusturulmasi ve ekrana basilmasi
    struct node * sp_shorted_list = malloc(sizeof(struct node*));
    if(sp_shorted_list == NULL){
        printf("sp_shorted_list degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    sp_shorted_list->value = 2;//Root eleman atamasi

    vfp_create_linked_list(sp_shorted_list,4);
    printf("-----------------Sirali Liste-----------------\n");
    vfp_print_linked_list(sp_shorted_list);


    printf("-----------------Ekleme yapilmis Sirali Liste-----------------\n");
    vf_add_short_linked_list(sp_shorted_list,21);

//_________________________________________________________________________________________________________________

    //--Liste olusturulmasi ve ekrana medyaninin bastirilmasi

    struct node * sp_shorted_list_median = malloc(sizeof(struct node*));
    if(sp_shorted_list_median == NULL){
        printf("sp_shorted_list_median degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    sp_shorted_list_median->value = 2;//Root eleman atamasi

    vfp_create_linked_list(sp_shorted_list_median,9);



    printf("-----------------Sirali Liste-----------------\n");
    vfp_print_linked_list(sp_shorted_list_median);   
    printf("\nMedyan = %f\n",dfp_list_median_calculate(sp_shorted_list_median));
 
//_________________________________________________________________________________________________________________

//_________________________________________________________________________________________________________________

    //--Liste olusturulmasi ve tersine cevrilip ekrana bastirilmasi

    struct node * sp_list_reverse = malloc(sizeof(struct node*));
    if(sp_list_reverse == NULL){
        printf("sp_list_reverse degiskeni icin bellek olusturma hatasi\n"); //Bellek olusturma kontrolu.
        exit(1);
    }
    sp_list_reverse->value = 2;//Root eleman atamasi

    vfp_create_linked_list(sp_list_reverse,10);



    printf("-----------------Sirali Liste-----------------\n");
    vfp_print_linked_list(sp_list_reverse);   
    printf("-----------------Tersten Sirali Liste-----------------\n");
    vfp_reverse_linked_list(sp_list_reverse);
//_________________________________________________________________________________________________________________

}


















