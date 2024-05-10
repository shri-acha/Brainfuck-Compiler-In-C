all:compile
compile:../../src/main.c execute
	@echo "Compiling main file"
	gcc  ../../src/main.c -o ../../src/main.o

execute: ../../src/main.o
	../../src/main.o ../../src/main.c 

clean:../../src/main.o
	@echo "Removing binaries"
	rm main.o
