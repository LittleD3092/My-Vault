module core_top #(
    parameter DWIDTH = 32
)(
    input                 clk,
    input                 rst
);

    // Jump type
    localparam [2:0] J_TYPE_NOP = 3'b000,
                     J_TYPE_BEQ = 3'b001,
                     J_TYPE_JAL = 3'b010,
                     J_TYPE_JR  = 3'b011,
                     J_TYPE_J   = 3'b100;

    // Program Counter signals
    reg  [DWIDTH-1:0] pc;
    wire [DWIDTH-1:0] pc_increment;
    wire              pc_write;

    // Decode signals
    reg  [DWIDTH-1:0] instr;
    wire [3:0]        op;
    wire              ssel;
    wire [1:0]        wbsel;
    wire              we_regfile;
    wire              we_dmem;
    wire [2:0]        jump_type;
    wire [25:0]       jump_addr;
    wire [DWIDTH-1:0] imm;
    wire [4:0]        rs1_id;
    wire [4:0]        rs2_id;
    wire [4:0]        rdst_id;
    
    // Regfile signals
    reg  [DWIDTH-1:0] rd;
    wire [DWIDTH-1:0] rs1_out;
    wire [DWIDTH-1:0] rs2_out;

    // ALU signals
    reg  [DWIDTH-1:0] alu_rs1;
    reg  [DWIDTH-1:0] alu_rs2;
    wire [DWIDTH-1:0] alu_out;
    wire              zero;
    wire              overflow;

    // Dmem signals
    wire [DWIDTH-1:0] dmem_out;

    // pipeline registers
    // IF/ID
    reg  [DWIDTH-1:0] if_id_addr;
    reg  [DWIDTH-1:0] if_id_instr;
    // ID/EX
    reg  [DWIDTH-1:0] id_ex_addr;
    reg  [DWIDTH-1:0] id_ex_jump_type;
    reg  [DWIDTH-1:0] id_ex_jump_addr;
    reg  [DWIDTH-1:0] id_ex_op;
    reg  [DWIDTH-1:0] id_ex_imm;
    reg  [DWIDTH-1:0] id_ex_rs1_out;
    reg  [DWIDTH-1:0] id_ex_rs2_out;
    reg  [DWIDTH-1:0] id_ex_rdst_id;
    reg               id_ex_we_regfile;
    reg               id_ex_we_dmem;
    reg  [1       :0] id_ex_wbsel;
    reg               id_ex_ssel;
    // EX/MEM
    reg  [DWIDTH-1:0] ex_mem_addr;
    reg  [DWIDTH-1:0] ex_mem_alu_out;
    reg  [DWIDTH-1:0] ex_mem_rs2_out;
    reg  [DWIDTH-1:0] ex_mem_rdst_id;
    reg               ex_mem_we_regfile;
    reg               ex_mem_we_dmem;
    reg  [1       :0] ex_mem_wbsel;
    // MEM/WB
    reg  [DWIDTH-1:0] mem_wb_addr;
    reg  [DWIDTH-1:0] mem_wb_rd;
    reg  [DWIDTH-1:0] mem_wb_rdst_id;
    reg               mem_wb_we_regfile;

    // hazard control
    wire              data_hazard;
    wire              control_hazard;

    always @(posedge clk) begin
        if (rst) begin
            // IF/ID
            if_id_addr <= 0;
            if_id_instr <= 0;
            // ID/EX
            id_ex_addr <= 0;
            id_ex_jump_type <= 0;
            id_ex_jump_addr <= 0;
            id_ex_op <= 0;
            id_ex_imm <= 0;
            id_ex_rs1_out <= 0;
            id_ex_rs2_out <= 0;
            id_ex_rdst_id <= 0;
            id_ex_we_regfile <= 0;
            id_ex_we_dmem <= 0;
            id_ex_wbsel <= 0;
            id_ex_ssel <= 0;
            //EX/MEM
            ex_mem_addr <= 0;
            ex_mem_alu_out <= 0;
            ex_mem_rs2_out <= 0;
            ex_mem_rdst_id <= 0;
            ex_mem_we_regfile <= 0;
            ex_mem_we_dmem <= 0;
            ex_mem_wbsel <= 0;
            // MEM/WB
            mem_wb_addr <= 0;
            mem_wb_rd <= 0;
            mem_wb_rdst_id <= 0;
            mem_wb_we_regfile <= 0;
        end else begin
            // IF/ID
            if (pc_write) begin
                if_id_addr <= pc;
                if_id_instr <= instr;
            end else if (control_hazard) begin
                if_id_addr <= 0;
                if_id_instr <= 0;
            end
            // ID/EX
            if (control_hazard) begin
                id_ex_addr <= 0;
                id_ex_jump_type <= 0;
                id_ex_jump_addr <= 0;
                id_ex_op <= 0;
                id_ex_imm <= 0;
                id_ex_rs1_out <= 0;
                id_ex_rs2_out <= 0;
                id_ex_rdst_id <= 0;
                id_ex_we_regfile <= 0;
                id_ex_we_dmem <= 0;
                id_ex_wbsel <= 0;
                id_ex_ssel <= 0;
            end
            else begin
                id_ex_addr <= if_id_addr;
                id_ex_jump_type <= jump_type;
                id_ex_jump_addr <= jump_addr;
                id_ex_op <= op;
                id_ex_imm <= imm;
                id_ex_rs1_out <= rs1_out;
                id_ex_rs2_out <= rs2_out;
                id_ex_rdst_id <= rdst_id;
                id_ex_we_regfile <= we_regfile;
                id_ex_we_dmem <= we_dmem;
                id_ex_wbsel <= wbsel;
                id_ex_ssel <= ssel;
            end
            // EX/MEM
            ex_mem_addr <= id_ex_addr;
            ex_mem_alu_out <= alu_out;
            ex_mem_rs2_out <= id_ex_rs2_out;
            ex_mem_rdst_id <= id_ex_rdst_id;
            ex_mem_we_regfile <= id_ex_we_regfile;
            ex_mem_we_dmem <= id_ex_we_dmem;
            ex_mem_wbsel <= id_ex_wbsel;
            // MEM/WB
            mem_wb_addr <= ex_mem_addr;
            mem_wb_rd <= rd;
            mem_wb_rdst_id <= ex_mem_rdst_id;
            mem_wb_we_regfile <= ex_mem_we_regfile;
        end
    end

    // Program counter
    assign pc_increment = pc + 4;

    always @(posedge clk) begin
        if (pc_write)
            if (rst)
                pc <= 0;
            else if (id_ex_jump_type == J_TYPE_BEQ && zero) 
                pc <= pc + {id_ex_imm[29:0], 2'b00};
            else if (id_ex_jump_type == J_TYPE_JR) 
                pc <= id_ex_rs1_out;
            else if (id_ex_jump_type == J_TYPE_JAL || id_ex_jump_type == J_TYPE_J) 
                pc <= {pc[31:28], id_ex_jump_addr, 2'b00};
            else
                pc <= pc_increment;
    end
    
    imem imem_inst(
        .addr(pc),
        .rdata(instr)
    );

    // hazard control
    assign data_hazard = (
        (id_ex_we_regfile && (id_ex_rdst_id == rs1_id || id_ex_rdst_id == rs2_id) && id_ex_addr != if_id_addr) ||
        (ex_mem_we_regfile && (ex_mem_rdst_id == rs1_id || ex_mem_rdst_id == rs2_id) && ex_mem_addr != if_id_addr) ||
        (mem_wb_we_regfile && (mem_wb_rdst_id == rs1_id || mem_wb_rdst_id == rs2_id) && mem_wb_addr != if_id_addr)
    );
    assign control_hazard = (
        id_ex_jump_type == J_TYPE_JR || id_ex_jump_type == J_TYPE_JAL || id_ex_jump_type == J_TYPE_J || 
        (id_ex_jump_type == J_TYPE_BEQ && zero)
    );
    assign pc_write = ~data_hazard && ~control_hazard;

    decode decode_inst (
        // input
        .instr(if_id_instr),

        // output  
        .op(op),
        .ssel(ssel),
        .wbsel(wbsel),
        .we_regfile(we_regfile),
        .we_dmem(we_dmem),
        .jump_type(jump_type),
        .jump_addr(jump_addr),
        .imm(imm),
        .rs1_id(rs1_id),
        .rs2_id(rs2_id),
        .rdst_id(rdst_id)
    );

    // Regfile
    always @(*) begin
        case (ex_mem_wbsel)
            2'b00:   rd = ex_mem_alu_out;
            2'b01:   rd = dmem_out;
            2'b10:   rd = ex_mem_addr + 4;
            default: rd = 0;
        endcase
    end

    reg_file reg_file_inst (
        // input
        .clk(clk),
        .rst(rst),

        .rs1_id(rs1_id),
        .rs2_id(rs2_id),

        .we(mem_wb_we_regfile),
        .rdst_id(mem_wb_rdst_id),
        .rdst(mem_wb_rd),

        // output 
        .rs1(rs1_out), // rs
        .rs2(rs2_out)  // rt
    );

    // ALU
    always @(*) begin
        alu_rs1 = id_ex_rs1_out;
    end

    always @(*) begin
        alu_rs2 = id_ex_ssel ? id_ex_rs2_out : id_ex_imm;
    end

    alu alu_inst (
        // input
        .op(id_ex_op),
        .rs1(alu_rs1),
        .rs2(alu_rs2),

        // output
        .rd(alu_out),
        .zero(zero),
        .overflow(overflow)
    );

    // Dmem
    dmem dmem_inst (
        .clk(clk),
        .addr(ex_mem_alu_out),
        .we(ex_mem_we_dmem),
        .wdata(ex_mem_rs2_out),
        .rdata(dmem_out)
    );

endmodule