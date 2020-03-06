// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="conv2d,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020-clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.024000,HLS_SYN_LAT=252619,HLS_SYN_TPT=none,HLS_SYN_MEM=2,HLS_SYN_DSP=5,HLS_SYN_FF=721,HLS_SYN_LUT=1333,HLS_VERSION=2019_1}" *)

module conv2d (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        in_r_address0,
        in_r_ce0,
        in_r_q0,
        filt_address0,
        filt_ce0,
        filt_q0,
        out_r_address0,
        out_r_ce0,
        out_r_we0,
        out_r_d0
);

parameter    ap_ST_fsm_state1 = 28'd1;
parameter    ap_ST_fsm_state2 = 28'd2;
parameter    ap_ST_fsm_state3 = 28'd4;
parameter    ap_ST_fsm_state4 = 28'd8;
parameter    ap_ST_fsm_state5 = 28'd16;
parameter    ap_ST_fsm_state6 = 28'd32;
parameter    ap_ST_fsm_state7 = 28'd64;
parameter    ap_ST_fsm_state8 = 28'd128;
parameter    ap_ST_fsm_state9 = 28'd256;
parameter    ap_ST_fsm_state10 = 28'd512;
parameter    ap_ST_fsm_state11 = 28'd1024;
parameter    ap_ST_fsm_state12 = 28'd2048;
parameter    ap_ST_fsm_state13 = 28'd4096;
parameter    ap_ST_fsm_state14 = 28'd8192;
parameter    ap_ST_fsm_state15 = 28'd16384;
parameter    ap_ST_fsm_state16 = 28'd32768;
parameter    ap_ST_fsm_state17 = 28'd65536;
parameter    ap_ST_fsm_state18 = 28'd131072;
parameter    ap_ST_fsm_state19 = 28'd262144;
parameter    ap_ST_fsm_state20 = 28'd524288;
parameter    ap_ST_fsm_state21 = 28'd1048576;
parameter    ap_ST_fsm_state22 = 28'd2097152;
parameter    ap_ST_fsm_state23 = 28'd4194304;
parameter    ap_ST_fsm_state24 = 28'd8388608;
parameter    ap_ST_fsm_state25 = 28'd16777216;
parameter    ap_ST_fsm_state26 = 28'd33554432;
parameter    ap_ST_fsm_state27 = 28'd67108864;
parameter    ap_ST_fsm_state28 = 28'd134217728;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [9:0] in_r_address0;
output   in_r_ce0;
input  [31:0] in_r_q0;
output  [4:0] filt_address0;
output   filt_ce0;
input  [31:0] filt_q0;
output  [9:0] out_r_address0;
output   out_r_ce0;
output   out_r_we0;
output  [31:0] out_r_d0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg in_r_ce0;
reg filt_ce0;
reg out_r_ce0;
reg out_r_we0;

(* fsm_encoding = "none" *) reg   [27:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire    ap_CS_fsm_state13;
wire    ap_CS_fsm_state20;
wire   [31:0] grp_fu_237_p2;
reg   [31:0] reg_257;
wire    ap_CS_fsm_state17;
wire    ap_CS_fsm_state24;
wire   [4:0] add_ln36_fu_268_p2;
reg   [4:0] add_ln36_reg_570;
wire    ap_CS_fsm_state2;
wire   [10:0] sub_ln38_fu_298_p2;
reg   [10:0] sub_ln38_reg_575;
wire   [0:0] icmp_ln36_fu_262_p2;
wire   [4:0] add_ln37_fu_315_p2;
wire    ap_CS_fsm_state3;
wire   [4:0] add_ln43_fu_341_p2;
reg   [4:0] add_ln43_reg_598;
wire    ap_CS_fsm_state4;
wire   [10:0] sub_ln52_fu_371_p2;
reg   [10:0] sub_ln52_reg_603;
wire   [0:0] icmp_ln43_fu_335_p2;
wire   [4:0] add_ln44_fu_383_p2;
reg   [4:0] add_ln44_reg_611;
wire    ap_CS_fsm_state5;
wire   [2:0] add_ln46_fu_399_p2;
reg   [2:0] add_ln46_reg_619;
wire    ap_CS_fsm_state6;
wire   [5:0] add_ln48_2_fu_421_p2;
reg   [5:0] add_ln48_2_reg_624;
wire   [0:0] icmp_ln46_fu_393_p2;
wire   [4:0] add_ln48_fu_427_p2;
reg   [4:0] add_ln48_reg_629;
reg   [9:0] acc_buf_addr_2_reg_634;
wire   [2:0] add_ln47_fu_457_p2;
reg   [2:0] add_ln47_reg_642;
wire    ap_CS_fsm_state7;
wire   [5:0] add_ln48_3_fu_467_p2;
reg   [5:0] add_ln48_3_reg_647;
wire   [0:0] icmp_ln47_fu_451_p2;
wire    ap_CS_fsm_state8;
reg   [31:0] in_load_reg_662;
wire    ap_CS_fsm_state9;
wire   [31:0] grp_fu_241_p2;
reg   [31:0] tmp_s_reg_672;
wire    ap_CS_fsm_state12;
wire   [31:0] acc_buf_q0;
reg   [31:0] acc_buf_load_1_reg_677;
wire    ap_CS_fsm_state19;
wire   [4:0] add_ln58_fu_505_p2;
reg   [4:0] add_ln58_reg_685;
wire    ap_CS_fsm_state26;
wire   [10:0] sub_ln60_fu_535_p2;
reg   [10:0] sub_ln60_reg_690;
wire   [0:0] icmp_ln58_fu_499_p2;
wire   [4:0] add_ln59_fu_547_p2;
reg   [4:0] add_ln59_reg_698;
wire    ap_CS_fsm_state27;
wire  signed [63:0] sext_ln60_fu_562_p1;
reg  signed [63:0] sext_ln60_reg_703;
wire   [0:0] icmp_ln59_fu_541_p2;
reg   [9:0] acc_buf_address0;
reg    acc_buf_ce0;
reg    acc_buf_we0;
reg   [31:0] acc_buf_d0;
reg   [4:0] r_0_0_reg_147;
wire   [0:0] icmp_ln37_fu_309_p2;
reg   [4:0] c_0_0_reg_158;
reg   [4:0] r1_0_0_0_reg_169;
wire   [0:0] icmp_ln44_fu_377_p2;
reg   [4:0] c2_0_0_0_reg_181;
wire    ap_CS_fsm_state25;
reg   [2:0] k_r_0_0_0_reg_193;
reg   [2:0] k_c_0_0_0_reg_204;
wire    ap_CS_fsm_state18;
reg   [4:0] r3_0_0_reg_215;
reg   [4:0] c4_0_0_reg_226;
wire    ap_CS_fsm_state28;
wire  signed [63:0] sext_ln38_fu_330_p1;
wire  signed [63:0] sext_ln52_fu_442_p1;
wire   [63:0] zext_ln48_3_fu_485_p1;
wire   [63:0] zext_ln48_4_fu_490_p1;
reg   [31:0] acc_2_0_0_fu_76;
reg   [31:0] grp_fu_237_p0;
reg   [31:0] grp_fu_237_p1;
wire   [9:0] tmp_7_fu_274_p3;
wire   [6:0] tmp_8_fu_286_p3;
wire   [10:0] zext_ln38_fu_282_p1;
wire   [10:0] zext_ln38_1_fu_294_p1;
wire   [10:0] zext_ln38_2_fu_321_p1;
wire   [10:0] add_ln38_fu_325_p2;
wire   [9:0] tmp_9_fu_347_p3;
wire   [6:0] tmp_10_fu_359_p3;
wire   [10:0] zext_ln52_fu_355_p1;
wire   [10:0] zext_ln52_1_fu_367_p1;
wire   [4:0] tmp_13_fu_409_p3;
wire   [5:0] zext_ln48_fu_405_p1;
wire   [5:0] zext_ln48_1_fu_417_p1;
wire   [4:0] zext_ln46_fu_389_p1;
wire   [10:0] zext_ln52_2_fu_433_p1;
wire   [10:0] add_ln52_fu_437_p2;
wire   [5:0] zext_ln48_2_fu_463_p1;
wire   [4:0] zext_ln47_fu_447_p1;
wire   [4:0] add_ln48_1_fu_472_p2;
wire   [9:0] tmp_14_fu_478_p3;
wire   [9:0] tmp_11_fu_511_p3;
wire   [6:0] tmp_12_fu_523_p3;
wire   [10:0] zext_ln60_fu_519_p1;
wire   [10:0] zext_ln60_1_fu_531_p1;
wire   [10:0] zext_ln60_2_fu_553_p1;
wire   [10:0] add_ln60_fu_557_p2;
reg   [27:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 28'd1;
end

conv2d_acc_buf #(
    .DataWidth( 32 ),
    .AddressRange( 784 ),
    .AddressWidth( 10 ))
acc_buf_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(acc_buf_address0),
    .ce0(acc_buf_ce0),
    .we0(acc_buf_we0),
    .d0(acc_buf_d0),
    .q0(acc_buf_q0)
);

conv2d_fadd_32ns_bkb #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
conv2d_fadd_32ns_bkb_U1(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_237_p0),
    .din1(grp_fu_237_p1),
    .ce(1'b1),
    .dout(grp_fu_237_p2)
);

conv2d_fmul_32ns_cud #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
conv2d_fmul_32ns_cud_U2(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(filt_q0),
    .din1(in_load_reg_662),
    .ce(1'b1),
    .dout(grp_fu_241_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state18)) begin
        acc_2_0_0_fu_76 <= reg_257;
    end else if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln36_fu_262_p2 == 1'd1))) begin
        acc_2_0_0_fu_76 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state25)) begin
        c2_0_0_0_reg_181 <= add_ln44_reg_611;
    end else if (((1'b1 == ap_CS_fsm_state4) & (icmp_ln43_fu_335_p2 == 1'd0))) begin
        c2_0_0_0_reg_181 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state28)) begin
        c4_0_0_reg_226 <= add_ln59_reg_698;
    end else if (((1'b1 == ap_CS_fsm_state26) & (icmp_ln58_fu_499_p2 == 1'd0))) begin
        c4_0_0_reg_226 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state3) & (icmp_ln37_fu_309_p2 == 1'd0))) begin
        c_0_0_reg_158 <= add_ln37_fu_315_p2;
    end else if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln36_fu_262_p2 == 1'd0))) begin
        c_0_0_reg_158 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state18)) begin
        k_c_0_0_0_reg_204 <= add_ln47_reg_642;
    end else if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln46_fu_393_p2 == 1'd0))) begin
        k_c_0_0_0_reg_204 <= 3'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln47_fu_451_p2 == 1'd1))) begin
        k_r_0_0_0_reg_193 <= add_ln46_reg_619;
    end else if (((1'b1 == ap_CS_fsm_state5) & (icmp_ln44_fu_377_p2 == 1'd0))) begin
        k_r_0_0_0_reg_193 <= 3'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state5) & (icmp_ln44_fu_377_p2 == 1'd1))) begin
        r1_0_0_0_reg_169 <= add_ln43_reg_598;
    end else if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln36_fu_262_p2 == 1'd1))) begin
        r1_0_0_0_reg_169 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state4) & (icmp_ln43_fu_335_p2 == 1'd1))) begin
        r3_0_0_reg_215 <= 5'd0;
    end else if (((1'b1 == ap_CS_fsm_state27) & (icmp_ln59_fu_541_p2 == 1'd1))) begin
        r3_0_0_reg_215 <= add_ln58_reg_685;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state3) & (icmp_ln37_fu_309_p2 == 1'd1))) begin
        r_0_0_reg_147 <= add_ln36_reg_570;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        r_0_0_reg_147 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln46_fu_393_p2 == 1'd1))) begin
        acc_buf_addr_2_reg_634 <= sext_ln52_fu_442_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state19)) begin
        acc_buf_load_1_reg_677 <= acc_buf_q0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        add_ln36_reg_570 <= add_ln36_fu_268_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        add_ln43_reg_598 <= add_ln43_fu_341_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        add_ln44_reg_611 <= add_ln44_fu_383_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        add_ln46_reg_619 <= add_ln46_fu_399_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        add_ln47_reg_642 <= add_ln47_fu_457_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln46_fu_393_p2 == 1'd0))) begin
        add_ln48_2_reg_624 <= add_ln48_2_fu_421_p2;
        add_ln48_reg_629 <= add_ln48_fu_427_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln47_fu_451_p2 == 1'd0))) begin
        add_ln48_3_reg_647 <= add_ln48_3_fu_467_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state26)) begin
        add_ln58_reg_685 <= add_ln58_fu_505_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state27)) begin
        add_ln59_reg_698 <= add_ln59_fu_547_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        in_load_reg_662 <= in_r_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state24) | (1'b1 == ap_CS_fsm_state17))) begin
        reg_257 <= grp_fu_237_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state27) & (icmp_ln59_fu_541_p2 == 1'd0))) begin
        sext_ln60_reg_703 <= sext_ln60_fu_562_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln36_fu_262_p2 == 1'd0))) begin
        sub_ln38_reg_575[10 : 2] <= sub_ln38_fu_298_p2[10 : 2];
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state4) & (icmp_ln43_fu_335_p2 == 1'd0))) begin
        sub_ln52_reg_603[10 : 2] <= sub_ln52_fu_371_p2[10 : 2];
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state26) & (icmp_ln58_fu_499_p2 == 1'd0))) begin
        sub_ln60_reg_690[10 : 2] <= sub_ln60_fu_535_p2[10 : 2];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        tmp_s_reg_672 <= grp_fu_241_p2;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state27)) begin
        acc_buf_address0 = sext_ln60_fu_562_p1;
    end else if ((1'b1 == ap_CS_fsm_state25)) begin
        acc_buf_address0 = acc_buf_addr_2_reg_634;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        acc_buf_address0 = sext_ln52_fu_442_p1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        acc_buf_address0 = sext_ln38_fu_330_p1;
    end else begin
        acc_buf_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state25) | (1'b1 == ap_CS_fsm_state27) | (1'b1 == ap_CS_fsm_state6) | (1'b1 == ap_CS_fsm_state3))) begin
        acc_buf_ce0 = 1'b1;
    end else begin
        acc_buf_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state25)) begin
        acc_buf_d0 = reg_257;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        acc_buf_d0 = 32'd0;
    end else begin
        acc_buf_d0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state25) | ((1'b1 == ap_CS_fsm_state3) & (icmp_ln37_fu_309_p2 == 1'd0)))) begin
        acc_buf_we0 = 1'b1;
    end else begin
        acc_buf_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state26) & (icmp_ln58_fu_499_p2 == 1'd1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state26) & (icmp_ln58_fu_499_p2 == 1'd1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        filt_ce0 = 1'b1;
    end else begin
        filt_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state20)) begin
        grp_fu_237_p0 = acc_buf_load_1_reg_677;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_237_p0 = acc_2_0_0_fu_76;
    end else begin
        grp_fu_237_p0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state20)) begin
        grp_fu_237_p1 = acc_2_0_0_fu_76;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_237_p1 = tmp_s_reg_672;
    end else begin
        grp_fu_237_p1 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        in_r_ce0 = 1'b1;
    end else begin
        in_r_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state28)) begin
        out_r_ce0 = 1'b1;
    end else begin
        out_r_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state28)) begin
        out_r_we0 = 1'b1;
    end else begin
        out_r_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln36_fu_262_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            if (((1'b1 == ap_CS_fsm_state3) & (icmp_ln37_fu_309_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state4 : begin
            if (((1'b1 == ap_CS_fsm_state4) & (icmp_ln43_fu_335_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state26;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end
        end
        ap_ST_fsm_state5 : begin
            if (((1'b1 == ap_CS_fsm_state5) & (icmp_ln44_fu_377_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        ap_ST_fsm_state6 : begin
            if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln46_fu_393_p2 == 1'd0))) begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state19;
            end
        end
        ap_ST_fsm_state7 : begin
            if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln47_fu_451_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state8;
            end
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        ap_ST_fsm_state10 : begin
            ap_NS_fsm = ap_ST_fsm_state11;
        end
        ap_ST_fsm_state11 : begin
            ap_NS_fsm = ap_ST_fsm_state12;
        end
        ap_ST_fsm_state12 : begin
            ap_NS_fsm = ap_ST_fsm_state13;
        end
        ap_ST_fsm_state13 : begin
            ap_NS_fsm = ap_ST_fsm_state14;
        end
        ap_ST_fsm_state14 : begin
            ap_NS_fsm = ap_ST_fsm_state15;
        end
        ap_ST_fsm_state15 : begin
            ap_NS_fsm = ap_ST_fsm_state16;
        end
        ap_ST_fsm_state16 : begin
            ap_NS_fsm = ap_ST_fsm_state17;
        end
        ap_ST_fsm_state17 : begin
            ap_NS_fsm = ap_ST_fsm_state18;
        end
        ap_ST_fsm_state18 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state19 : begin
            ap_NS_fsm = ap_ST_fsm_state20;
        end
        ap_ST_fsm_state20 : begin
            ap_NS_fsm = ap_ST_fsm_state21;
        end
        ap_ST_fsm_state21 : begin
            ap_NS_fsm = ap_ST_fsm_state22;
        end
        ap_ST_fsm_state22 : begin
            ap_NS_fsm = ap_ST_fsm_state23;
        end
        ap_ST_fsm_state23 : begin
            ap_NS_fsm = ap_ST_fsm_state24;
        end
        ap_ST_fsm_state24 : begin
            ap_NS_fsm = ap_ST_fsm_state25;
        end
        ap_ST_fsm_state25 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state26 : begin
            if (((1'b1 == ap_CS_fsm_state26) & (icmp_ln58_fu_499_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state27;
            end
        end
        ap_ST_fsm_state27 : begin
            if (((1'b1 == ap_CS_fsm_state27) & (icmp_ln59_fu_541_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state26;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state28;
            end
        end
        ap_ST_fsm_state28 : begin
            ap_NS_fsm = ap_ST_fsm_state27;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln36_fu_268_p2 = (r_0_0_reg_147 + 5'd1);

assign add_ln37_fu_315_p2 = (c_0_0_reg_158 + 5'd1);

assign add_ln38_fu_325_p2 = (sub_ln38_reg_575 + zext_ln38_2_fu_321_p1);

assign add_ln43_fu_341_p2 = (r1_0_0_0_reg_169 + 5'd1);

assign add_ln44_fu_383_p2 = (c2_0_0_0_reg_181 + 5'd1);

assign add_ln46_fu_399_p2 = (k_r_0_0_0_reg_193 + 3'd1);

assign add_ln47_fu_457_p2 = (k_c_0_0_0_reg_204 + 3'd1);

assign add_ln48_1_fu_472_p2 = (zext_ln47_fu_447_p1 + c2_0_0_0_reg_181);

assign add_ln48_2_fu_421_p2 = (zext_ln48_fu_405_p1 + zext_ln48_1_fu_417_p1);

assign add_ln48_3_fu_467_p2 = (add_ln48_2_reg_624 + zext_ln48_2_fu_463_p1);

assign add_ln48_fu_427_p2 = (zext_ln46_fu_389_p1 + r1_0_0_0_reg_169);

assign add_ln52_fu_437_p2 = (sub_ln52_reg_603 + zext_ln52_2_fu_433_p1);

assign add_ln58_fu_505_p2 = (r3_0_0_reg_215 + 5'd1);

assign add_ln59_fu_547_p2 = (c4_0_0_reg_226 + 5'd1);

assign add_ln60_fu_557_p2 = (sub_ln60_reg_690 + zext_ln60_2_fu_553_p1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state12 = ap_CS_fsm[32'd11];

assign ap_CS_fsm_state13 = ap_CS_fsm[32'd12];

assign ap_CS_fsm_state17 = ap_CS_fsm[32'd16];

assign ap_CS_fsm_state18 = ap_CS_fsm[32'd17];

assign ap_CS_fsm_state19 = ap_CS_fsm[32'd18];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state20 = ap_CS_fsm[32'd19];

assign ap_CS_fsm_state24 = ap_CS_fsm[32'd23];

assign ap_CS_fsm_state25 = ap_CS_fsm[32'd24];

assign ap_CS_fsm_state26 = ap_CS_fsm[32'd25];

assign ap_CS_fsm_state27 = ap_CS_fsm[32'd26];

assign ap_CS_fsm_state28 = ap_CS_fsm[32'd27];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state9 = ap_CS_fsm[32'd8];

assign filt_address0 = zext_ln48_4_fu_490_p1;

assign icmp_ln36_fu_262_p2 = ((r_0_0_reg_147 == 5'd28) ? 1'b1 : 1'b0);

assign icmp_ln37_fu_309_p2 = ((c_0_0_reg_158 == 5'd28) ? 1'b1 : 1'b0);

assign icmp_ln43_fu_335_p2 = ((r1_0_0_0_reg_169 == 5'd28) ? 1'b1 : 1'b0);

assign icmp_ln44_fu_377_p2 = ((c2_0_0_0_reg_181 == 5'd28) ? 1'b1 : 1'b0);

assign icmp_ln46_fu_393_p2 = ((k_r_0_0_0_reg_193 == 3'd5) ? 1'b1 : 1'b0);

assign icmp_ln47_fu_451_p2 = ((k_c_0_0_0_reg_204 == 3'd5) ? 1'b1 : 1'b0);

assign icmp_ln58_fu_499_p2 = ((r3_0_0_reg_215 == 5'd28) ? 1'b1 : 1'b0);

assign icmp_ln59_fu_541_p2 = ((c4_0_0_reg_226 == 5'd28) ? 1'b1 : 1'b0);

assign in_r_address0 = zext_ln48_3_fu_485_p1;

assign out_r_address0 = sext_ln60_reg_703;

assign out_r_d0 = acc_buf_q0;

assign sext_ln38_fu_330_p1 = $signed(add_ln38_fu_325_p2);

assign sext_ln52_fu_442_p1 = $signed(add_ln52_fu_437_p2);

assign sext_ln60_fu_562_p1 = $signed(add_ln60_fu_557_p2);

assign sub_ln38_fu_298_p2 = (zext_ln38_fu_282_p1 - zext_ln38_1_fu_294_p1);

assign sub_ln52_fu_371_p2 = (zext_ln52_fu_355_p1 - zext_ln52_1_fu_367_p1);

assign sub_ln60_fu_535_p2 = (zext_ln60_fu_519_p1 - zext_ln60_1_fu_531_p1);

assign tmp_10_fu_359_p3 = {{r1_0_0_0_reg_169}, {2'd0}};

assign tmp_11_fu_511_p3 = {{r3_0_0_reg_215}, {5'd0}};

assign tmp_12_fu_523_p3 = {{r3_0_0_reg_215}, {2'd0}};

assign tmp_13_fu_409_p3 = {{k_r_0_0_0_reg_193}, {2'd0}};

assign tmp_14_fu_478_p3 = {{add_ln48_reg_629}, {add_ln48_1_fu_472_p2}};

assign tmp_7_fu_274_p3 = {{r_0_0_reg_147}, {5'd0}};

assign tmp_8_fu_286_p3 = {{r_0_0_reg_147}, {2'd0}};

assign tmp_9_fu_347_p3 = {{r1_0_0_0_reg_169}, {5'd0}};

assign zext_ln38_1_fu_294_p1 = tmp_8_fu_286_p3;

assign zext_ln38_2_fu_321_p1 = c_0_0_reg_158;

assign zext_ln38_fu_282_p1 = tmp_7_fu_274_p3;

assign zext_ln46_fu_389_p1 = k_r_0_0_0_reg_193;

assign zext_ln47_fu_447_p1 = k_c_0_0_0_reg_204;

assign zext_ln48_1_fu_417_p1 = tmp_13_fu_409_p3;

assign zext_ln48_2_fu_463_p1 = k_c_0_0_0_reg_204;

assign zext_ln48_3_fu_485_p1 = tmp_14_fu_478_p3;

assign zext_ln48_4_fu_490_p1 = add_ln48_3_reg_647;

assign zext_ln48_fu_405_p1 = k_r_0_0_0_reg_193;

assign zext_ln52_1_fu_367_p1 = tmp_10_fu_359_p3;

assign zext_ln52_2_fu_433_p1 = c2_0_0_0_reg_181;

assign zext_ln52_fu_355_p1 = tmp_9_fu_347_p3;

assign zext_ln60_1_fu_531_p1 = tmp_12_fu_523_p3;

assign zext_ln60_2_fu_553_p1 = c4_0_0_reg_226;

assign zext_ln60_fu_519_p1 = tmp_11_fu_511_p3;

always @ (posedge ap_clk) begin
    sub_ln38_reg_575[1:0] <= 2'b00;
    sub_ln52_reg_603[1:0] <= 2'b00;
    sub_ln60_reg_690[1:0] <= 2'b00;
end

endmodule //conv2d
