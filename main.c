#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10000

void main(){
  /*This is the initial thought of my program that I have in my mind before
    reasearching or anything lets hope it is like this.*/
//initilizes 1D memory space with all values initialized with 0.
//reads one line.
//checks for errors in memory,when value in a cell value goes less than 0 or more than 255
//executes operation
//repeat still the end of line.
//exits

	int* strip =(int*) malloc(MAX_LENGTH*sizeof(int));

//intrstructions to implement: + - > < (for now)
	int st_position = MAX_LENGTH /2-1;
	printf("%d",st_position);

}

