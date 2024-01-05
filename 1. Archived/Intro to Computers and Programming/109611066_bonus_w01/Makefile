all: compile run zip

compile:
	gcc -c main.cpp -o main.o
	gcc -c 109611066_bonus_01.cpp -o bonus.o
	gcc main.o bonus.o -o my_program

run:
	./my_program

zip:
	zip 109611066_bonus_w01.zip my_string.h 109611066_bonus_01.cpp

clean:
	rm -rf *.o my_program *.zip