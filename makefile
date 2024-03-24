all:final

final: main.o execute clean

main.o: main.c
	@echo "Compiling main file"
	gcc  main.c -o main.o
execute: main.o
	@echo "Compiling main file"
	./main.o
clean:
	@echo "removing files"
	rm main.o
