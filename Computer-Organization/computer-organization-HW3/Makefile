SRC = hw3_tb.v alu.v decode.v dmem.v imem.v reg_file.v
OUT = Vhw3_tb

all:
	verilator $(SRC) -Wno-WIDTH -trace -cc --top-module hw3_tb -exe top.cpp
	make -C obj_dir -f Vhw3_tb.mk Vhw3_tb
	cp obj_dir/$(OUT) .

run: clean all
	clear
	./$(OUT)

clean:
	rm -rf $(OUT) *.vcd obj_dir