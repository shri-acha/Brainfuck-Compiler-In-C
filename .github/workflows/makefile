all:compile
compile:main.c execute
	@echo "Compiling main file"
	gcc  ../../src/main.c -o ../../src/main.o

execute: main.o
	@read -p "Enter File Directory: " file;
	../../src/main.o $$file 

clean:main.o
	@echo "Removing binaries"
	rm main.o
