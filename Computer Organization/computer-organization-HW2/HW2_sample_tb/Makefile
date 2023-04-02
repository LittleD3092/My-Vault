SRC = decode_tb.v alu.v decode.v reg_file.v
OUT = Vdecode_tb

all:
	verilator $(SRC) -Wno-WIDTH -trace -cc --top-module decode_tb -exe top.cpp
	make -C obj_dir -f Vdecode_tb.mk Vdecode_tb
	cp obj_dir/$(OUT) .

run: clean all
	clear
	./$(OUT)

clean:
	rm -rf $(OUT) *.vcd obj_dir