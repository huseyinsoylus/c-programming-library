#include <stdio.h>


void print_array(int array[],int num){

	for(int i=0;i<num;i++){
		printf("%6d,",array[i]);
	} 
	printf("\n");

}

void print_distubuted_array(int array[], int beginning, int distubuted_ratio, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        array[i] = i*distubuted_ratio;    
    }
}

int main(int argc,char*argv[]){

	int array[1000];
	print_distubuted_array(array,0,5,1000);
	print_array(array,1000);

}
