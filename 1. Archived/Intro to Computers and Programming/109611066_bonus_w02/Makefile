all: compile run verify
zip:
	zip 109611066_bonus_w02.zip 109611066_hw_01.cpp

compile:
	gcc -o 109611066_hw_01 109611066_hw_01.cpp
run:
	./109611066_hw_01
verify:
	python3 verify.py
clean:
	rm -rf 109611066_hw_01 a.out test.txt 109611066_bonus_w02.zip