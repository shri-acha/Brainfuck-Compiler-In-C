#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10000

void brain_fuck_compiler(int,int,int);

void main(){
  /*This is the initial thought of my program that I have in my mind before
    reasearching or anything lets hope it is like this.*/
//initilizes 1D memory space with all values initialized with 0.
//reads one line.
//checks for errors in memory,when value in a cell value goes less than 0 or more than 255
//executes operation
//repeat still the end of line.
//exits
	brain_fuck_compiler(0,0,1);
	return;
	}


void brain_fuck_compiler(int curr_position,int instruction_position,int status){

	char instruction_array[MAX_LENGTH];
	int* strip =(int*) malloc(MAX_LENGTH*sizeof(int));
	FILE* main_file;
	main_file = fopen("brainfuck_code.bf","r");
	
	//instructions to implement: + - > < (for now)
	int st_position = MAX_LENGTH/2-1;

	if(status){
		printf("HOORAY");
		int curr_position=st_position,instruction_position=0;
		fgets(instruction_array,MAX_LENGTH,main_file);
		printf("Instructions Read!\n");
			printf("\t\t.\t");
			printf(".\t");
			printf(".\t\n");
			printf("%d\t%c",instruction_position,instruction_array[instruction_position]);
	}

	
	if(instruction_array[instruction_position]!='\0'){

		//Checks if the values in the memory strip is within the memory bounds
		if(! strip[curr_position]<=255 && ! strip[curr_position]>=0){
			strip[curr_position] = 0;
		}
		if(instruction_array[instruction_position]=='>'){
			curr_position++;	
			instruction_position++;
			brain_fuck_compiler(curr_position,instruction_position,0);
	
		}
		else if(instruction_array[instruction_position]=='<'){
			curr_position--;
			instruction_position++;
			brain_fuck_compiler(curr_position,instruction_position,0);
		}
		else if(instruction_array[instruction_position]=='+'){
			strip[curr_position]++;
			instruction_position++;
			brain_fuck_compiler(curr_position,instruction_position,0);
		}
		else if(instruction_array[instruction_position=='-']){
			strip[curr_position]--;
			instruction_position++;
			brain_fuck_compiler(curr_position,instruction_position,0);
		}
	}
	else{
		return;
	}
		int i=0;
		while(i< 10000){
			if(strip[i]>=0 && strip[i]<=255)
		printf("%c\n",strip[i]);
		}

}
