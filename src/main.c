#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "lexer.h"

#define MAX_LENGTH 10000

void brain_fuck_compiler(int,int);


void main(int argv,char* argc[]){
  /*This is the initial thought of my program that I have in my mind before
    reasearching or anything lets hope it is like this.*/
//initilizes 1D memory space with all values initialized with 0.
//reads one line.
//checks for errors in memory,when value in a cell value goes less than 0 or more than 255
//executes operation
//repeat still the end of line.
//exits
	brain_fuck_compiler(1,0);
  tokenizer("Hello World!",(size_t)strlen("Hello World!"));
	return;
	}


void brain_fuck_compiler(int status,int curr_position){

//To implement: [ ] loops
	
	 static char instruction_array[MAX_LENGTH];
	static int strip[MAX_LENGTH];
	static int start_loop_memory_position =0;
	static int start_loop_instruction_position=0;
	static int instruction_position =0;
	if(status){


	FILE* main_file;
	main_file = fopen("brainfuck_code.bf","r");
	if(main_file==NULL){
			printf("Error while opening file/directories.\n");
			return;
	}
		int curr_position=MAX_LENGTH/2 -1;
		memset(strip,0,sizeof(strip));	 
		fgets(instruction_array,MAX_LENGTH,main_file);
		printf("The instructions are:\t%s\n",instruction_array);
	}
	
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
			brain_fuck_compiler(0,curr_position);	
		}
		else if(instruction_array[instruction_position]=='-'){
			//subtracts from the memory cell from 1
			strip[curr_position] -=1;
			instruction_position +=1;	
			brain_fuck_compiler(0,curr_position);
		}

		else if(instruction_array[instruction_position]=='.'){
			printf("%c",strip[curr_position]);
			instruction_position++;
			brain_fuck_compiler(0,curr_position);
		}
		else if(instruction_array[instruction_position]==','){
			scanf("%d",&strip[curr_position]);
			instruction_position++;
			brain_fuck_compiler(0,curr_position);
		}
		else if(instruction_array[instruction_position]=='['){
			start_loop_memory_position=curr_position;
			start_loop_instruction_position=instruction_position;
			instruction_position++;		
			brain_fuck_compiler(0,curr_position);
		
		}


		else if( instruction_array[instruction_position] == ']'){


		if(!strip[start_loop_memory_position]){
			instruction_position++;
			brain_fuck_compiler(0,curr_position);
		}	
			else
			{
				instruction_position = start_loop_instruction_position;
				brain_fuck_compiler(0,curr_position);
			}
		}

	}
	
}

