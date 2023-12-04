all: compile run
test: compile make-test run-test clean

compile:
	gcc -o 109611066_hw_01 109611066_hw_01.cpp

make-test:
	python3 make_test.py

run-test:
	./109611066_hw_01 < input_1.txt > output_1.txt
	./109611066_hw_01 < input_2.txt > output_2.txt
	diff output_1.txt output_ans_1.txt
	diff output_2.txt output_ans_2.txt

zip:
	zip 109611066_hw_w12.zip 109611066_hw_01.cpp

clean:
	rm -f 109611066_hw_01 input_1.txt input_2.txt output_1.txt output_2.txt output_ans_1.txt output_ans_2.txt 109611066_hw_w12.zip

run:
	./109611066_hw_01
