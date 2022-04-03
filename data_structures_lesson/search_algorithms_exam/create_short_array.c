#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void bubble_short_array(int arr[], int num){

    int x, y, temp;   

    for(x = 0; x < num - 1; x++){

        for(y = 0; y < num - x - 1; y++){    

            if(arr[y] > arr[y + 1]){

                temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;

            }

        }

    }

}

void print_array(int array[],int num){

	for(int i=0;i<num;i++){
		printf("%6d,",array[i]);
	} 
	printf("\n");

}

void print_randoms_array(int array[], int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        array[i] = num;    
    }
}

int main(int argc,char*argv[]){

	int array[1000];
	print_randoms_array(array,0,5000,1000);
	bubble_short_array(array,1000);
	print_array(array,1000);





}
