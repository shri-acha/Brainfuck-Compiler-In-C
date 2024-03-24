#include<stdio.h>

void main(){
	int i=0;
	char strBuff[1000];
	FILE* main_file;
	main_file = fopen("brainfuck_code.bf","r");
	fgets(strBuff,1000,main_file);
		while(strBuff[i]!='\0'){
		printf("%c",strBuff[i]);
		i++;
	}
		fclose(main_file);
		return;
}
