
This package contains the templates of decode.v and reg_file.v
for you to get started with your own designs. Please read through
the following guidelines carefully.

1.  First, please copy the file alu.v you have desined for HW#1 to
    this directory.

2.  DO NOT modify the port names and file names of the template decode.v
    and reg_file.v.  Just add your code to them.

3.  There are two data files, input.txt and reg_file.txt. The first one
    contains the input patterns to the input ports of the decode module.
    Each row in the input.txt is the test pattern of one instruction.
    The file reg_file.txt contains the correct register values after the
    processing of all the input instruction signals.

4.  Type "make run" in the command line, the simulation program will be
    compiled and executed.

5.  In the input.txt, we only provide some simple test patterns, you need
    to add your own complex test patterns to make sure your design is
    correct.

6.  If the number of the patterns is too large to simulate in time,
    you should modify the MAX_SIM_TIME in top.cpp.

7.  Please upload ONLY the "decode.v" and "reg_file.v" file to E3
    for the submission of the homework (don't compress it).

8.  Please don't plagiarize other's work, TAs will check your design
    with plagiarism detection system. If we have doubt about your work,
    you will be asked to come to the TA's office to answer some
    technical questions and demonstrate that you can modify your code
    on the spot to add new features.

9.  In "decode.v", the signal "ssel" will select imm when it's 0,
    or it will select rs2 when it's 1.

10. In "reg_file.v", the signal "rst" is a synchronous active high reset.
    So, you should reset your registers when rst is 1 at  positive edge
    of clk. And, "rst" will be given only once at the beginning.

11. TAs will only check "op", "ssel", "imm", "rs1_id", "rs2_id" and
    "rdst_id" at the negative edge of clk and all values in your
    reg_file at the end of the test.

12. Any "/* verilator lint_off XXX */" in design is not allowed, you
    must resolve all warnings
