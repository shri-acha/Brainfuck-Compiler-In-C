#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "lexer.h"
#include "stack.h"

#define MAX_LENGTH 10000
#define MAX_FILE_SIZE 4096

void brain_fuck_compiler(int,int);
long _sread_file(char* file_content,char* _file_name);

void main(int argv,char* argc[]){ 

  if (argv<2){
    fprintf(stderr,"[ERROR] Too few arguments\n\r[USAGE] ./compile [FILENAME].bf\n");
    exit(-1);
  } 
  
  char* file_contents = malloc(MAX_FILE_SIZE);
  long _f_size;

  _f_size = _sread_file(file_contents,argc[1]);

  TOKEN* token_arr = tokenizer(file_contents,(size_t)_f_size);  // tokenizes the result and returns an array of TOKENS
  
  for (int i=0;i<_f_size-1;i++){
      printf("Token Type:%d Token Val:%c\n",token_arr[i].tok_t,token_arr[i].tok_val);
  }
   // Tokenization block

  { 
    parser(token_arr,_f_size);
  } // Parsing block

  free(token_arr); 
	return;
	}

long _sread_file(char* file_content,char* _file_name){
 
  FILE* _file = fopen(_file_name,"r");
  if ( _file == NULL ) return -1;
  fseek(_file,0,SEEK_END);
  long _f_size = ftell(_file);
  fseek(_file,0,SEEK_SET);

  fread(file_content,_f_size,1,_file);
  if (strlen(file_content)<0){
    fprintf(stderr,"[ERROR] Source can't be empty!");
    exit(-1);
  }
  fclose(_file);
  return _f_size;
}

void brain_fuck_compiler(int status,int curr_position){
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
