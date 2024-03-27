all:compile
compile:main.c execute
	@echo "Compiling main file"
	gcc  main.c -o main.o

execute: main.o
	./main.o

clean:main.o
	@echo "Removing binaries"
	rm main.o
