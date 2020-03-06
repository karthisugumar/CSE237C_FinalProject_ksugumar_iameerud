// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "flatten.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic flatten::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic flatten::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<5> flatten::ap_ST_fsm_state1 = "1";
const sc_lv<5> flatten::ap_ST_fsm_state2 = "10";
const sc_lv<5> flatten::ap_ST_fsm_state3 = "100";
const sc_lv<5> flatten::ap_ST_fsm_state4 = "1000";
const sc_lv<5> flatten::ap_ST_fsm_state5 = "10000";
const sc_lv<32> flatten::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> flatten::ap_const_lv32_1 = "1";
const sc_lv<1> flatten::ap_const_lv1_0 = "0";
const sc_lv<32> flatten::ap_const_lv32_2 = "10";
const sc_lv<32> flatten::ap_const_lv32_3 = "11";
const sc_lv<32> flatten::ap_const_lv32_4 = "100";
const sc_lv<5> flatten::ap_const_lv5_0 = "00000";
const sc_lv<1> flatten::ap_const_lv1_1 = "1";
const sc_lv<9> flatten::ap_const_lv9_0 = "000000000";
const sc_lv<3> flatten::ap_const_lv3_0 = "000";
const sc_lv<5> flatten::ap_const_lv5_10 = "10000";
const sc_lv<5> flatten::ap_const_lv5_1 = "1";
const sc_lv<9> flatten::ap_const_lv9_19 = "11001";
const sc_lv<2> flatten::ap_const_lv2_0 = "00";
const sc_lv<3> flatten::ap_const_lv3_5 = "101";
const sc_lv<3> flatten::ap_const_lv3_1 = "1";
const sc_lv<9> flatten::ap_const_lv9_5 = "101";
const sc_lv<9> flatten::ap_const_lv9_1 = "1";
const bool flatten::ap_const_boolean_1 = true;

flatten::flatten(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln12_1_fu_261_p2);
    sensitive << ( idx_2_reg_128 );

    SC_METHOD(thread_add_ln12_3_fu_184_p2);
    sensitive << ( zext_ln12_fu_168_p1 );
    sensitive << ( zext_ln12_1_fu_180_p1 );

    SC_METHOD(thread_add_ln12_4_fu_212_p2);
    sensitive << ( add_ln12_3_reg_285 );
    sensitive << ( zext_ln12_2_fu_208_p1 );

    SC_METHOD(thread_add_ln12_5_fu_229_p2);
    sensitive << ( zext_ln12_4_fu_217_p1 );
    sensitive << ( p_shl1_cast_fu_221_p3 );

    SC_METHOD(thread_add_ln12_6_fu_251_p2);
    sensitive << ( add_ln12_5_reg_303 );
    sensitive << ( zext_ln12_5_fu_247_p1 );

    SC_METHOD(thread_add_ln12_fu_202_p2);
    sensitive << ( idx_1_reg_106 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state4);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state5);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln9_fu_150_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln9_fu_150_p2 );

    SC_METHOD(thread_c_fu_241_p2);
    sensitive << ( c_0_reg_139 );

    SC_METHOD(thread_icmp_ln10_fu_190_p2);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( r_0_reg_117 );

    SC_METHOD(thread_icmp_ln11_fu_235_p2);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( c_0_reg_139 );

    SC_METHOD(thread_icmp_ln9_fu_150_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ifm_0_reg_83 );

    SC_METHOD(thread_idx_fu_162_p2);
    sensitive << ( idx_0_reg_94 );

    SC_METHOD(thread_ifm_fu_156_p2);
    sensitive << ( ifm_0_reg_83 );

    SC_METHOD(thread_in_r_address0);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( zext_ln12_6_fu_256_p1 );

    SC_METHOD(thread_in_r_ce0);
    sensitive << ( ap_CS_fsm_state4 );

    SC_METHOD(thread_out_r_address0);
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( zext_ln12_3_fu_267_p1 );

    SC_METHOD(thread_out_r_ce0);
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_out_r_d0);
    sensitive << ( in_r_q0 );
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_out_r_we0);
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_p_shl1_cast_fu_221_p3);
    sensitive << ( add_ln12_4_fu_212_p2 );

    SC_METHOD(thread_r_fu_196_p2);
    sensitive << ( r_0_reg_117 );

    SC_METHOD(thread_tmp_2_fu_172_p3);
    sensitive << ( ifm_0_reg_83 );

    SC_METHOD(thread_zext_ln12_1_fu_180_p1);
    sensitive << ( tmp_2_fu_172_p3 );

    SC_METHOD(thread_zext_ln12_2_fu_208_p1);
    sensitive << ( r_0_reg_117 );

    SC_METHOD(thread_zext_ln12_3_fu_267_p1);
    sensitive << ( idx_2_reg_128 );

    SC_METHOD(thread_zext_ln12_4_fu_217_p1);
    sensitive << ( add_ln12_4_fu_212_p2 );

    SC_METHOD(thread_zext_ln12_5_fu_247_p1);
    sensitive << ( c_0_reg_139 );

    SC_METHOD(thread_zext_ln12_6_fu_256_p1);
    sensitive << ( add_ln12_6_fu_251_p2 );

    SC_METHOD(thread_zext_ln12_fu_168_p1);
    sensitive << ( ifm_0_reg_83 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln9_fu_150_p2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln10_fu_190_p2 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln11_fu_235_p2 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    ap_CS_fsm = "00001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "flatten_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, in_r_address0, "(port)in_r_address0");
    sc_trace(mVcdFile, in_r_ce0, "(port)in_r_ce0");
    sc_trace(mVcdFile, in_r_q0, "(port)in_r_q0");
    sc_trace(mVcdFile, out_r_address0, "(port)out_r_address0");
    sc_trace(mVcdFile, out_r_ce0, "(port)out_r_ce0");
    sc_trace(mVcdFile, out_r_we0, "(port)out_r_we0");
    sc_trace(mVcdFile, out_r_d0, "(port)out_r_d0");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, ifm_fu_156_p2, "ifm_fu_156_p2");
    sc_trace(mVcdFile, ifm_reg_275, "ifm_reg_275");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, idx_fu_162_p2, "idx_fu_162_p2");
    sc_trace(mVcdFile, idx_reg_280, "idx_reg_280");
    sc_trace(mVcdFile, icmp_ln9_fu_150_p2, "icmp_ln9_fu_150_p2");
    sc_trace(mVcdFile, add_ln12_3_fu_184_p2, "add_ln12_3_fu_184_p2");
    sc_trace(mVcdFile, add_ln12_3_reg_285, "add_ln12_3_reg_285");
    sc_trace(mVcdFile, r_fu_196_p2, "r_fu_196_p2");
    sc_trace(mVcdFile, r_reg_293, "r_reg_293");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, add_ln12_fu_202_p2, "add_ln12_fu_202_p2");
    sc_trace(mVcdFile, add_ln12_reg_298, "add_ln12_reg_298");
    sc_trace(mVcdFile, icmp_ln10_fu_190_p2, "icmp_ln10_fu_190_p2");
    sc_trace(mVcdFile, add_ln12_5_fu_229_p2, "add_ln12_5_fu_229_p2");
    sc_trace(mVcdFile, add_ln12_5_reg_303, "add_ln12_5_reg_303");
    sc_trace(mVcdFile, c_fu_241_p2, "c_fu_241_p2");
    sc_trace(mVcdFile, c_reg_311, "c_reg_311");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, icmp_ln11_fu_235_p2, "icmp_ln11_fu_235_p2");
    sc_trace(mVcdFile, add_ln12_1_fu_261_p2, "add_ln12_1_fu_261_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, ifm_0_reg_83, "ifm_0_reg_83");
    sc_trace(mVcdFile, idx_0_reg_94, "idx_0_reg_94");
    sc_trace(mVcdFile, idx_1_reg_106, "idx_1_reg_106");
    sc_trace(mVcdFile, r_0_reg_117, "r_0_reg_117");
    sc_trace(mVcdFile, idx_2_reg_128, "idx_2_reg_128");
    sc_trace(mVcdFile, c_0_reg_139, "c_0_reg_139");
    sc_trace(mVcdFile, zext_ln12_6_fu_256_p1, "zext_ln12_6_fu_256_p1");
    sc_trace(mVcdFile, zext_ln12_3_fu_267_p1, "zext_ln12_3_fu_267_p1");
    sc_trace(mVcdFile, tmp_2_fu_172_p3, "tmp_2_fu_172_p3");
    sc_trace(mVcdFile, zext_ln12_fu_168_p1, "zext_ln12_fu_168_p1");
    sc_trace(mVcdFile, zext_ln12_1_fu_180_p1, "zext_ln12_1_fu_180_p1");
    sc_trace(mVcdFile, zext_ln12_2_fu_208_p1, "zext_ln12_2_fu_208_p1");
    sc_trace(mVcdFile, add_ln12_4_fu_212_p2, "add_ln12_4_fu_212_p2");
    sc_trace(mVcdFile, zext_ln12_4_fu_217_p1, "zext_ln12_4_fu_217_p1");
    sc_trace(mVcdFile, p_shl1_cast_fu_221_p3, "p_shl1_cast_fu_221_p3");
    sc_trace(mVcdFile, zext_ln12_5_fu_247_p1, "zext_ln12_5_fu_247_p1");
    sc_trace(mVcdFile, add_ln12_6_fu_251_p2, "add_ln12_6_fu_251_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("flatten.hdltvin.dat");
    mHdltvoutHandle.open("flatten.hdltvout.dat");
}

flatten::~flatten() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
}

void flatten::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        c_0_reg_139 = c_reg_311.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln10_fu_190_p2.read()))) {
        c_0_reg_139 = ap_const_lv3_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(icmp_ln10_fu_190_p2.read(), ap_const_lv1_1))) {
        idx_0_reg_94 = idx_reg_280.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        idx_0_reg_94 = ap_const_lv9_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln11_fu_235_p2.read(), ap_const_lv1_1))) {
        idx_1_reg_106 = add_ln12_reg_298.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(icmp_ln9_fu_150_p2.read(), ap_const_lv1_0))) {
        idx_1_reg_106 = idx_0_reg_94.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        idx_2_reg_128 = add_ln12_1_fu_261_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln10_fu_190_p2.read()))) {
        idx_2_reg_128 = idx_1_reg_106.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(icmp_ln10_fu_190_p2.read(), ap_const_lv1_1))) {
        ifm_0_reg_83 = ifm_reg_275.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        ifm_0_reg_83 = ap_const_lv5_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln11_fu_235_p2.read(), ap_const_lv1_1))) {
        r_0_reg_117 = r_reg_293.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(icmp_ln9_fu_150_p2.read(), ap_const_lv1_0))) {
        r_0_reg_117 = ap_const_lv3_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln9_fu_150_p2.read(), ap_const_lv1_0))) {
        add_ln12_3_reg_285 = add_ln12_3_fu_184_p2.read();
        idx_reg_280 = idx_fu_162_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln10_fu_190_p2.read()))) {
        add_ln12_5_reg_303 = add_ln12_5_fu_229_p2.read();
        add_ln12_reg_298 = add_ln12_fu_202_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        c_reg_311 = c_fu_241_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ifm_reg_275 = ifm_fu_156_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        r_reg_293 = r_fu_196_p2.read();
    }
}

void flatten::thread_add_ln12_1_fu_261_p2() {
    add_ln12_1_fu_261_p2 = (!idx_2_reg_128.read().is_01() || !ap_const_lv9_1.is_01())? sc_lv<9>(): (sc_biguint<9>(idx_2_reg_128.read()) + sc_biguint<9>(ap_const_lv9_1));
}

void flatten::thread_add_ln12_3_fu_184_p2() {
    add_ln12_3_fu_184_p2 = (!zext_ln12_fu_168_p1.read().is_01() || !zext_ln12_1_fu_180_p1.read().is_01())? sc_lv<8>(): (sc_biguint<8>(zext_ln12_fu_168_p1.read()) + sc_biguint<8>(zext_ln12_1_fu_180_p1.read()));
}

void flatten::thread_add_ln12_4_fu_212_p2() {
    add_ln12_4_fu_212_p2 = (!add_ln12_3_reg_285.read().is_01() || !zext_ln12_2_fu_208_p1.read().is_01())? sc_lv<8>(): (sc_biguint<8>(add_ln12_3_reg_285.read()) + sc_biguint<8>(zext_ln12_2_fu_208_p1.read()));
}

void flatten::thread_add_ln12_5_fu_229_p2() {
    add_ln12_5_fu_229_p2 = (!zext_ln12_4_fu_217_p1.read().is_01() || !p_shl1_cast_fu_221_p3.read().is_01())? sc_lv<10>(): (sc_biguint<10>(zext_ln12_4_fu_217_p1.read()) + sc_biguint<10>(p_shl1_cast_fu_221_p3.read()));
}

void flatten::thread_add_ln12_6_fu_251_p2() {
    add_ln12_6_fu_251_p2 = (!add_ln12_5_reg_303.read().is_01() || !zext_ln12_5_fu_247_p1.read().is_01())? sc_lv<10>(): (sc_biguint<10>(add_ln12_5_reg_303.read()) + sc_biguint<10>(zext_ln12_5_fu_247_p1.read()));
}

void flatten::thread_add_ln12_fu_202_p2() {
    add_ln12_fu_202_p2 = (!idx_1_reg_106.read().is_01() || !ap_const_lv9_5.is_01())? sc_lv<9>(): (sc_biguint<9>(idx_1_reg_106.read()) + sc_biguint<9>(ap_const_lv9_5));
}

void flatten::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void flatten::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void flatten::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void flatten::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void flatten::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void flatten::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln9_fu_150_p2.read(), ap_const_lv1_1))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void flatten::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void flatten::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln9_fu_150_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void flatten::thread_c_fu_241_p2() {
    c_fu_241_p2 = (!c_0_reg_139.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(c_0_reg_139.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void flatten::thread_icmp_ln10_fu_190_p2() {
    icmp_ln10_fu_190_p2 = (!r_0_reg_117.read().is_01() || !ap_const_lv3_5.is_01())? sc_lv<1>(): sc_lv<1>(r_0_reg_117.read() == ap_const_lv3_5);
}

void flatten::thread_icmp_ln11_fu_235_p2() {
    icmp_ln11_fu_235_p2 = (!c_0_reg_139.read().is_01() || !ap_const_lv3_5.is_01())? sc_lv<1>(): sc_lv<1>(c_0_reg_139.read() == ap_const_lv3_5);
}

void flatten::thread_icmp_ln9_fu_150_p2() {
    icmp_ln9_fu_150_p2 = (!ifm_0_reg_83.read().is_01() || !ap_const_lv5_10.is_01())? sc_lv<1>(): sc_lv<1>(ifm_0_reg_83.read() == ap_const_lv5_10);
}

void flatten::thread_idx_fu_162_p2() {
    idx_fu_162_p2 = (!idx_0_reg_94.read().is_01() || !ap_const_lv9_19.is_01())? sc_lv<9>(): (sc_biguint<9>(idx_0_reg_94.read()) + sc_biguint<9>(ap_const_lv9_19));
}

void flatten::thread_ifm_fu_156_p2() {
    ifm_fu_156_p2 = (!ifm_0_reg_83.read().is_01() || !ap_const_lv5_1.is_01())? sc_lv<5>(): (sc_biguint<5>(ifm_0_reg_83.read()) + sc_biguint<5>(ap_const_lv5_1));
}

void flatten::thread_in_r_address0() {
    in_r_address0 =  (sc_lv<9>) (zext_ln12_6_fu_256_p1.read());
}

void flatten::thread_in_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        in_r_ce0 = ap_const_logic_1;
    } else {
        in_r_ce0 = ap_const_logic_0;
    }
}

void flatten::thread_out_r_address0() {
    out_r_address0 =  (sc_lv<9>) (zext_ln12_3_fu_267_p1.read());
}

void flatten::thread_out_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        out_r_ce0 = ap_const_logic_1;
    } else {
        out_r_ce0 = ap_const_logic_0;
    }
}

void flatten::thread_out_r_d0() {
    out_r_d0 = in_r_q0.read();
}

void flatten::thread_out_r_we0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        out_r_we0 = ap_const_logic_1;
    } else {
        out_r_we0 = ap_const_logic_0;
    }
}

void flatten::thread_p_shl1_cast_fu_221_p3() {
    p_shl1_cast_fu_221_p3 = esl_concat<8,2>(add_ln12_4_fu_212_p2.read(), ap_const_lv2_0);
}

void flatten::thread_r_fu_196_p2() {
    r_fu_196_p2 = (!r_0_reg_117.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(r_0_reg_117.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void flatten::thread_tmp_2_fu_172_p3() {
    tmp_2_fu_172_p3 = esl_concat<5,2>(ifm_0_reg_83.read(), ap_const_lv2_0);
}

void flatten::thread_zext_ln12_1_fu_180_p1() {
    zext_ln12_1_fu_180_p1 = esl_zext<8,7>(tmp_2_fu_172_p3.read());
}

void flatten::thread_zext_ln12_2_fu_208_p1() {
    zext_ln12_2_fu_208_p1 = esl_zext<8,3>(r_0_reg_117.read());
}

void flatten::thread_zext_ln12_3_fu_267_p1() {
    zext_ln12_3_fu_267_p1 = esl_zext<64,9>(idx_2_reg_128.read());
}

void flatten::thread_zext_ln12_4_fu_217_p1() {
    zext_ln12_4_fu_217_p1 = esl_zext<10,8>(add_ln12_4_fu_212_p2.read());
}

void flatten::thread_zext_ln12_5_fu_247_p1() {
    zext_ln12_5_fu_247_p1 = esl_zext<10,3>(c_0_reg_139.read());
}

void flatten::thread_zext_ln12_6_fu_256_p1() {
    zext_ln12_6_fu_256_p1 = esl_zext<64,10>(add_ln12_6_fu_251_p2.read());
}

void flatten::thread_zext_ln12_fu_168_p1() {
    zext_ln12_fu_168_p1 = esl_zext<8,5>(ifm_0_reg_83.read());
}

void flatten::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln9_fu_150_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(icmp_ln10_fu_190_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state4;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(icmp_ln11_fu_235_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        default : 
            ap_NS_fsm = "XXXXX";
            break;
    }
}

void flatten::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"in_r_address0\" :  \"" << in_r_address0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"in_r_ce0\" :  \"" << in_r_ce0.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"in_r_q0\" :  \"" << in_r_q0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_address0\" :  \"" << out_r_address0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_ce0\" :  \"" << out_r_ce0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_we0\" :  \"" << out_r_we0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"out_r_d0\" :  \"" << out_r_d0.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}
