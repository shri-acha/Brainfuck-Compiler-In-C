all:compile
compile:main.c execute
	@echo "Compiling main file"
	gcc  main.c -o Brainfuck.o 

execute: main.o
	@read -p "Enter File Directory: " file;
	./Brainfuck.o $$file 

clean:main.o
	@echo "Removing binaries"
	rm main.o
