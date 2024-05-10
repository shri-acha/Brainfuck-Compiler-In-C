all:compile
compile:main.c execute
	@echo "Compiling main file"
	gcc  main.c -o main.o

execute: main.o
	@read -p "Enter File Directory: " file;
	./main.o $$file 

clean:main.o
	@echo "Removing binaries"
	rm main.o
