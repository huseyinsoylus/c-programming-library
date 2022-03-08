#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node 
{
    int number;                        //Data of the node
    struct node *nextptr;           //Address of the next node
}*root;

//Functions Area

int getFirst(struct node * root){
	
	struct node *tmp;
	tmp=root;
	
	if(tmp->number != NULL){
		printf("True");
	}
	else{
		printf("False");
	}
	
	
}
void contains(struct node * root, int aranan_eleman){
	
	struct node *tmp;
	tmp=root;
	int index=0;
	while(tmp != NULL){
		
		if(tmp->number == aranan_eleman){
			printf("%d True",index);
		}
		tmp=tmp->nextptr;
		
		index++;
	}
	
}

void set(struct node * root, int aranan_index,int item){
	int index=0;
	while(root != NULL){
		
		if(index==aranan_index){
			root->number=item;
		}
	index++;	
	root=root->nextptr;
	}

}
void yazdir(struct node * root){
	struct node *tmp;
	tmp=root;
	while(tmp != NULL){
		printf("%d\n",tmp->number);
		tmp=tmp->nextptr;
	}
}


//Functions Area

int main(int argc, char *argv[]) {
	
	
	root = (struct node *)malloc(sizeof(struct node)); //bagli liste ilk eleman ekleme
	
	if(root==NULL){//bellek alan oluþturma baþarýlý mý?
		printf("Gerekli alan ayrilamadi");
	}
	root->number = 1; //ilk eleman deger atama;
	
	//ikinci elamaný oluþturma
	struct node *node_2;
	node_2=(struct node *)malloc(sizeof(struct node)); //node_2 bellek ayýrma
	root->nextptr=node_2;//root 2. elemaný gösterir
	node_2->number=2;//node2 eleman ekleme
	
	//ucuncu elamaný oluþturma
	struct node *node_3;
	node_3=(struct node *)malloc(sizeof(struct node)); //node_2 bellek ayýrma
	node_2->nextptr=node_3;//root 2. elemaný gösterir
	node_3->number=3;//node2 eleman ekleme
	node_3->nextptr=NULL;
	
	printf("ilk eleman %d ikinci eleman %d ucuncu eleman %d\n",root->number,node_2->number,node_3->number);
	
	printf("Ilk eleman kontrol:");
	getFirst(root);//ilk eleman var mý?
	printf("\n");
	contains(root,3);//aranan eleman

	
	set(root,2,15);
	printf("\n");
	yazdir(root);
	return 0;
}
