#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAX_LENGTH 10000

void brain_fuck_compiler(int,int);

void main(){
  /*This is the initial thought of my program that I have in my mind before
    reasearching or anything lets hope it is like this.*/
//initilizes 1D memory space with all values initialized with 0.
//reads one line.
//checks for errors in memory,when value in a cell value goes less than 0 or more than 255
//executes operation
//repeat still the end of line.
//exits
	brain_fuck_compiler(1,0);
	return;
	}


void brain_fuck_compiler(int status,int curr_position){


	
	static char instruction_array[MAX_LENGTH];
	static int strip[MAX_LENGTH];

	
	static int instruction_position =0;
	if(status){
	//instructions to implement: + - > < (for now)
	//only opens the file for reading into the instruction array.
		FILE* main_file;
	 	int curr_position=MAX_LENGTH/2 -1;

		memset(strip,0,sizeof(strip));	 
		main_file = fopen("brainfuck_code.bf","r");
		fgets(instruction_array,MAX_LENGTH,main_file);
		printf("The instructions are:\t%s\n",instruction_array);
		}
	
		printf("The instruction position is:%d\tThe instruction is:%c\tThe cell data is:%c\n",instruction_position,instruction_array[instruction_position],strip[curr_position]);
		if(strip[curr_position]<0)strip[curr_position]=255;
		if(strip[curr_position]>255)strip[curr_position]=0;
	
	if(instruction_array[instruction_position]>0){
		//Checks if the values in the memory strip is within the memory bounds
		if(instruction_array[instruction_position]=='>'){
			//shifts the memory pointer by 1 position to the right
			curr_position+=1;	
			instruction_position+=1;
			brain_fuck_compiler(0,curr_position);
	
		}
		else if(instruction_array[instruction_position]=='<'){
			//shifts the memory pointer by 1 position to the left
			curr_position-=1;
			instruction_position+=1;
			brain_fuck_compiler(0,curr_position);
		}
		else if(instruction_array[instruction_position] == '+'){
			//adds to the memory cell by 1
			strip[curr_position]+=1;
			instruction_position+=1;
			printf("Added to cell memory\n");
			brain_fuck_compiler(0,curr_position);	
		}
		else if(instruction_array[instruction_position]=='-'){
			//subtracts from the memory cell from 1
			strip[curr_position] -=1;
			instruction_position +=1;	
			printf("Subtracted from the cell memory\n");
			brain_fuck_compiler(0,curr_position);
		}
	}
	
}
