#include <string>
#include <fstream>
#include <iostream>
#include "mc_testbench.h"
#include <mc_reset.h>
#include <mc_transactors.h>
#include <mc_scverify.h>
#include <mc_stall_ctrl.h>
#include "/mnt/d/Ubuntu/Mgc_home/pkgs/ccs_libs/interfaces/amba/ccs_axi4_slave_mem_trans_rsc.h"
#include "ccs_ioport_trans_rsc_v1.h"
#include <mc_monitor.h>
#include <mc_simulator_extensions.h>
#include "mc_dut_wrapper.h"
#include "ccs_probes.cpp"
#include <mt19937ar.c>
#ifndef TO_QUOTED_STRING
#define TO_QUOTED_STRING(x) TO_QUOTED_STRING1(x)
#define TO_QUOTED_STRING1(x) #x
#endif
#ifndef TOP_HDL_ENTITY
#define TOP_HDL_ENTITY lenet
#endif
// Hold time for the SCVerify testbench to account for the gate delay after downstream synthesis in pico second(s)
// Hold time value is obtained from 'top_gate_constraints.cpp', which is generated at the end of RTL synthesis
#ifdef CCS_DUT_GATE
extern double __scv_hold_time;
extern double __scv_hold_time_RSCID_1;
extern double __scv_hold_time_RSCID_2;
#else
double __scv_hold_time = 0.0; // default for non-gate simulation is zero
double __scv_hold_time_RSCID_1 = 0;
double __scv_hold_time_RSCID_2 = 0;
#endif

class scverify_top : public sc_module
{
public:
  sc_signal<sc_logic>                                                                              rst;
  sc_signal<sc_logic>                                                                              rst_n;
  sc_signal<sc_logic>                                                                              SIG_SC_LOGIC_0;
  sc_signal<sc_logic>                                                                              SIG_SC_LOGIC_1;
  sc_signal<sc_logic>                                                                              TLS_design_is_idle;
  sc_signal<bool>                                                                                  TLS_design_is_idle_reg;
  sc_clock                                                                                         clk;
  mc_programmable_reset                                                                            rst_driver;
  sc_signal<sc_logic>                                                                              TLS_rst;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_s_tdone;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_tr_write_done;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_RREADY;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_RVALID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_RUSER;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_RLAST;
  sc_signal<sc_lv<2> >                                                                             TLS_image_in_rsc_RRESP;
  sc_signal<sc_lv<32> >                                                                            TLS_image_in_rsc_RDATA;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_RID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_ARREADY;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_ARVALID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_ARUSER;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_ARREGION;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_ARQOS;
  sc_signal<sc_lv<3> >                                                                             TLS_image_in_rsc_ARPROT;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_ARCACHE;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_ARLOCK;
  sc_signal<sc_lv<2> >                                                                             TLS_image_in_rsc_ARBURST;
  sc_signal<sc_lv<3> >                                                                             TLS_image_in_rsc_ARSIZE;
  sc_signal<sc_lv<8> >                                                                             TLS_image_in_rsc_ARLEN;
  sc_signal<sc_lv<12> >                                                                            TLS_image_in_rsc_ARADDR;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_ARID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_BREADY;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_BVALID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_BUSER;
  sc_signal<sc_lv<2> >                                                                             TLS_image_in_rsc_BRESP;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_BID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_WREADY;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_WVALID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_WUSER;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_WLAST;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_WSTRB;
  sc_signal<sc_lv<32> >                                                                            TLS_image_in_rsc_WDATA;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_AWREADY;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_AWVALID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_AWUSER;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_AWREGION;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_AWQOS;
  sc_signal<sc_lv<3> >                                                                             TLS_image_in_rsc_AWPROT;
  sc_signal<sc_lv<4> >                                                                             TLS_image_in_rsc_AWCACHE;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_AWLOCK;
  sc_signal<sc_lv<2> >                                                                             TLS_image_in_rsc_AWBURST;
  sc_signal<sc_lv<3> >                                                                             TLS_image_in_rsc_AWSIZE;
  sc_signal<sc_lv<8> >                                                                             TLS_image_in_rsc_AWLEN;
  sc_signal<sc_lv<12> >                                                                            TLS_image_in_rsc_AWADDR;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_AWID;
  sc_signal<sc_logic>                                                                              TLS_image_in_rsc_triosy_lz;
  sc_signal<sc_lv<320> >                                                                           TLS_out_rsc_dat;
  sc_signal<sc_logic>                                                                              TLS_out_rsc_triosy_lz;
  ccs_DUT_wrapper                                                                                  lenet_INST;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_AWID;
  ccs_sc_lv1_to_sc_logic_adapter                                                                   CCS_ADAPTOR_TLS_image_in_rsc_AWID;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_AWUSER;
  ccs_sc_lv1_to_sc_logic_adapter                                                                   CCS_ADAPTOR_TLS_image_in_rsc_AWUSER;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_WUSER;
  ccs_sc_lv1_to_sc_logic_adapter                                                                   CCS_ADAPTOR_TLS_image_in_rsc_WUSER;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_BID;
  ccs_sc_logic_to_sc_lv1_adapter                                                                   CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BID;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_BUSER;
  ccs_sc_logic_to_sc_lv1_adapter                                                                   CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BUSER;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_ARID;
  ccs_sc_lv1_to_sc_logic_adapter                                                                   CCS_ADAPTOR_TLS_image_in_rsc_ARID;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_ARUSER;
  ccs_sc_lv1_to_sc_logic_adapter                                                                   CCS_ADAPTOR_TLS_image_in_rsc_ARUSER;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_RID;
  ccs_sc_logic_to_sc_lv1_adapter                                                                   CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RID;
  sc_signal<sc_lv<1> >                                                                             CCS_ADAPTOR_image_in_rsc_RUSER;
  ccs_sc_logic_to_sc_lv1_adapter                                                                   CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RUSER;
  ccs_axi4_slave_mem_trans_rsc<784,32,32,0,0,12,32,1,1,1,0,0 >                                     image_in_rsc_INST;
  ccs_out_trans_rsc_v1<1,320 >                                                                     out_rsc_INST;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<ac_fixed<32, 16, true, AC_TRN, AC_WRAP >,784> >               TLS_in_fifo_image_in;
  tlm::tlm_fifo<mc_wait_ctrl>                                                                      TLS_in_wait_ctrl_fifo_image_in;
  mc_trios_input_monitor                                                                           trios_monitor_image_in_rsc_triosy_lz_INST;
  mc_input_transactor<mgc_sysc_ver_array1D<ac_fixed<32, 16, true, AC_TRN, AC_WRAP >,784>,32,true>  transactor_image_in;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<ac_fixed<32, 16, true, AC_TRN, AC_WRAP >,10> >                TLS_out_fifo_out;
  tlm::tlm_fifo<mc_wait_ctrl>                                                                      TLS_out_wait_ctrl_fifo_out;
  mc_trios_output_monitor                                                                          trios_monitor_out_rsc_triosy_lz_INST;
  mc_output_transactor<mgc_sysc_ver_array1D<ac_fixed<32, 16, true, AC_TRN, AC_WRAP >,10>,32,true>  transactor_out;
  mc_testbench                                                                                     testbench_INST;
  sc_signal<sc_logic>                                                                              catapult_start;
  sc_signal<sc_logic>                                                                              catapult_done;
  sc_signal<sc_logic>                                                                              catapult_ready;
  sc_signal<sc_logic>                                                                              in_sync;
  sc_signal<sc_logic>                                                                              out_sync;
  sc_signal<sc_logic>                                                                              inout_sync;
  sc_signal<unsigned>                                                                              wait_for_init;
  sync_generator                                                                                   sync_generator_INST;
  catapult_monitor                                                                                 catapult_monitor_INST;
  ccs_probe_monitor                                                                               *ccs_probe_monitor_INST;
  sc_event                                                                                         generate_reset_event;
  sc_event                                                                                         deadlock_event;
  sc_signal<sc_logic>                                                                              deadlocked;
  sc_signal<sc_logic>                                                                              maxsimtime;
  sc_event                                                                                         max_sim_time_event;
  sc_signal<sc_logic>                                                                              OFS_lenet_core_inst_lenet_core_image_in_rsci_inst_lenet_core_image_in_rsci_image_in_rsc_wait_ctrl_inst_image_in_rsci_s_re_core_sct;
  sc_signal<sc_logic>                                                                              OFS_lenet_core_inst_lenet_core_image_in_rsci_inst_lenet_core_image_in_rsci_image_in_rsc_wait_ctrl_inst_image_in_rsci_s_rrdy;
  sc_signal<sc_logic>                                                                              OFS_lenet_core_inst_lenet_core_image_in_rsci_inst_lenet_core_image_in_rsci_image_in_rsc_wait_dp_inst_image_in_rsci_s_raddr_core_sct;
  sc_signal<sc_logic>                                                                              TLS_enable_stalls;
  sc_signal<unsigned short>                                                                        TLS_stall_coverage;

  void TLS_rst_method();
  void max_sim_time_notify();
  void start_of_simulation();
  void setup_debug();
  void debug(const char* varname, int flags, int count);
  void generate_reset();
  void install_observe_foreign_signals();
  void deadlock_watch();
  void deadlock_notify();

  // Constructor
  SC_HAS_PROCESS(scverify_top);
  scverify_top(const sc_module_name& name)
    : rst("rst")
    , rst_n("rst_n")
    , SIG_SC_LOGIC_0("SIG_SC_LOGIC_0")
    , SIG_SC_LOGIC_1("SIG_SC_LOGIC_1")
    , TLS_design_is_idle("TLS_design_is_idle")
    , TLS_design_is_idle_reg("TLS_design_is_idle_reg")
    , CCS_CLK_CTOR(clk, "clk", 2, SC_NS, 0.5, 0, SC_NS, false)
    , rst_driver("rst_driver", 4.000000, false)
    , TLS_rst("TLS_rst")
    , TLS_image_in_rsc_s_tdone("TLS_image_in_rsc_s_tdone")
    , TLS_image_in_rsc_tr_write_done("TLS_image_in_rsc_tr_write_done")
    , TLS_image_in_rsc_RREADY("TLS_image_in_rsc_RREADY")
    , TLS_image_in_rsc_RVALID("TLS_image_in_rsc_RVALID")
    , TLS_image_in_rsc_RUSER("TLS_image_in_rsc_RUSER")
    , TLS_image_in_rsc_RLAST("TLS_image_in_rsc_RLAST")
    , TLS_image_in_rsc_RRESP("TLS_image_in_rsc_RRESP")
    , TLS_image_in_rsc_RDATA("TLS_image_in_rsc_RDATA")
    , TLS_image_in_rsc_RID("TLS_image_in_rsc_RID")
    , TLS_image_in_rsc_ARREADY("TLS_image_in_rsc_ARREADY")
    , TLS_image_in_rsc_ARVALID("TLS_image_in_rsc_ARVALID")
    , TLS_image_in_rsc_ARUSER("TLS_image_in_rsc_ARUSER")
    , TLS_image_in_rsc_ARREGION("TLS_image_in_rsc_ARREGION")
    , TLS_image_in_rsc_ARQOS("TLS_image_in_rsc_ARQOS")
    , TLS_image_in_rsc_ARPROT("TLS_image_in_rsc_ARPROT")
    , TLS_image_in_rsc_ARCACHE("TLS_image_in_rsc_ARCACHE")
    , TLS_image_in_rsc_ARLOCK("TLS_image_in_rsc_ARLOCK")
    , TLS_image_in_rsc_ARBURST("TLS_image_in_rsc_ARBURST")
    , TLS_image_in_rsc_ARSIZE("TLS_image_in_rsc_ARSIZE")
    , TLS_image_in_rsc_ARLEN("TLS_image_in_rsc_ARLEN")
    , TLS_image_in_rsc_ARADDR("TLS_image_in_rsc_ARADDR")
    , TLS_image_in_rsc_ARID("TLS_image_in_rsc_ARID")
    , TLS_image_in_rsc_BREADY("TLS_image_in_rsc_BREADY")
    , TLS_image_in_rsc_BVALID("TLS_image_in_rsc_BVALID")
    , TLS_image_in_rsc_BUSER("TLS_image_in_rsc_BUSER")
    , TLS_image_in_rsc_BRESP("TLS_image_in_rsc_BRESP")
    , TLS_image_in_rsc_BID("TLS_image_in_rsc_BID")
    , TLS_image_in_rsc_WREADY("TLS_image_in_rsc_WREADY")
    , TLS_image_in_rsc_WVALID("TLS_image_in_rsc_WVALID")
    , TLS_image_in_rsc_WUSER("TLS_image_in_rsc_WUSER")
    , TLS_image_in_rsc_WLAST("TLS_image_in_rsc_WLAST")
    , TLS_image_in_rsc_WSTRB("TLS_image_in_rsc_WSTRB")
    , TLS_image_in_rsc_WDATA("TLS_image_in_rsc_WDATA")
    , TLS_image_in_rsc_AWREADY("TLS_image_in_rsc_AWREADY")
    , TLS_image_in_rsc_AWVALID("TLS_image_in_rsc_AWVALID")
    , TLS_image_in_rsc_AWUSER("TLS_image_in_rsc_AWUSER")
    , TLS_image_in_rsc_AWREGION("TLS_image_in_rsc_AWREGION")
    , TLS_image_in_rsc_AWQOS("TLS_image_in_rsc_AWQOS")
    , TLS_image_in_rsc_AWPROT("TLS_image_in_rsc_AWPROT")
    , TLS_image_in_rsc_AWCACHE("TLS_image_in_rsc_AWCACHE")
    , TLS_image_in_rsc_AWLOCK("TLS_image_in_rsc_AWLOCK")
    , TLS_image_in_rsc_AWBURST("TLS_image_in_rsc_AWBURST")
    , TLS_image_in_rsc_AWSIZE("TLS_image_in_rsc_AWSIZE")
    , TLS_image_in_rsc_AWLEN("TLS_image_in_rsc_AWLEN")
    , TLS_image_in_rsc_AWADDR("TLS_image_in_rsc_AWADDR")
    , TLS_image_in_rsc_AWID("TLS_image_in_rsc_AWID")
    , TLS_image_in_rsc_triosy_lz("TLS_image_in_rsc_triosy_lz")
    , TLS_out_rsc_dat("TLS_out_rsc_dat")
    , TLS_out_rsc_triosy_lz("TLS_out_rsc_triosy_lz")
    , lenet_INST("rtl", TO_QUOTED_STRING(TOP_HDL_ENTITY))
    , CCS_ADAPTOR_TLS_image_in_rsc_AWID("CCS_ADAPTOR_TLS_image_in_rsc_AWID")
    , CCS_ADAPTOR_TLS_image_in_rsc_AWUSER("CCS_ADAPTOR_TLS_image_in_rsc_AWUSER")
    , CCS_ADAPTOR_TLS_image_in_rsc_WUSER("CCS_ADAPTOR_TLS_image_in_rsc_WUSER")
    , CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BID("CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BID")
    , CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BUSER("CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BUSER")
    , CCS_ADAPTOR_TLS_image_in_rsc_ARID("CCS_ADAPTOR_TLS_image_in_rsc_ARID")
    , CCS_ADAPTOR_TLS_image_in_rsc_ARUSER("CCS_ADAPTOR_TLS_image_in_rsc_ARUSER")
    , CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RID("CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RID")
    , CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RUSER("CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RUSER")
    , image_in_rsc_INST("image_in_rsc", true)
    , out_rsc_INST("out_rsc", true)
    , TLS_in_fifo_image_in("TLS_in_fifo_image_in", -1)
    , TLS_in_wait_ctrl_fifo_image_in("TLS_in_wait_ctrl_fifo_image_in", -1)
    , trios_monitor_image_in_rsc_triosy_lz_INST("trios_monitor_image_in_rsc_triosy_lz_INST")
    , transactor_image_in("transactor_image_in", 0, 32, 0)
    , TLS_out_fifo_out("TLS_out_fifo_out", -1)
    , TLS_out_wait_ctrl_fifo_out("TLS_out_wait_ctrl_fifo_out", -1)
    , trios_monitor_out_rsc_triosy_lz_INST("trios_monitor_out_rsc_triosy_lz_INST")
    , transactor_out("transactor_out", 0, 320, 0)
    , testbench_INST("user_tb")
    , catapult_start("catapult_start")
    , catapult_done("catapult_done")
    , catapult_ready("catapult_ready")
    , in_sync("in_sync")
    , out_sync("out_sync")
    , inout_sync("inout_sync")
    , wait_for_init("wait_for_init")
    , sync_generator_INST("sync_generator", true, false, false, false, 128366, 128366, 0)
    , catapult_monitor_INST("Monitor", clk, true, 128366LL, 128366LL)
    , ccs_probe_monitor_INST(NULL)
    , deadlocked("deadlocked")
    , maxsimtime("maxsimtime")
  {
    rst_driver.reset_out(TLS_rst);

    lenet_INST.clk(clk);
    lenet_INST.rst(TLS_rst);
    lenet_INST.image_in_rsc_s_tdone(TLS_image_in_rsc_s_tdone);
    lenet_INST.image_in_rsc_tr_write_done(TLS_image_in_rsc_tr_write_done);
    lenet_INST.image_in_rsc_RREADY(TLS_image_in_rsc_RREADY);
    lenet_INST.image_in_rsc_RVALID(TLS_image_in_rsc_RVALID);
    lenet_INST.image_in_rsc_RUSER(TLS_image_in_rsc_RUSER);
    lenet_INST.image_in_rsc_RLAST(TLS_image_in_rsc_RLAST);
    lenet_INST.image_in_rsc_RRESP(TLS_image_in_rsc_RRESP);
    lenet_INST.image_in_rsc_RDATA(TLS_image_in_rsc_RDATA);
    lenet_INST.image_in_rsc_RID(TLS_image_in_rsc_RID);
    lenet_INST.image_in_rsc_ARREADY(TLS_image_in_rsc_ARREADY);
    lenet_INST.image_in_rsc_ARVALID(TLS_image_in_rsc_ARVALID);
    lenet_INST.image_in_rsc_ARUSER(TLS_image_in_rsc_ARUSER);
    lenet_INST.image_in_rsc_ARREGION(TLS_image_in_rsc_ARREGION);
    lenet_INST.image_in_rsc_ARQOS(TLS_image_in_rsc_ARQOS);
    lenet_INST.image_in_rsc_ARPROT(TLS_image_in_rsc_ARPROT);
    lenet_INST.image_in_rsc_ARCACHE(TLS_image_in_rsc_ARCACHE);
    lenet_INST.image_in_rsc_ARLOCK(TLS_image_in_rsc_ARLOCK);
    lenet_INST.image_in_rsc_ARBURST(TLS_image_in_rsc_ARBURST);
    lenet_INST.image_in_rsc_ARSIZE(TLS_image_in_rsc_ARSIZE);
    lenet_INST.image_in_rsc_ARLEN(TLS_image_in_rsc_ARLEN);
    lenet_INST.image_in_rsc_ARADDR(TLS_image_in_rsc_ARADDR);
    lenet_INST.image_in_rsc_ARID(TLS_image_in_rsc_ARID);
    lenet_INST.image_in_rsc_BREADY(TLS_image_in_rsc_BREADY);
    lenet_INST.image_in_rsc_BVALID(TLS_image_in_rsc_BVALID);
    lenet_INST.image_in_rsc_BUSER(TLS_image_in_rsc_BUSER);
    lenet_INST.image_in_rsc_BRESP(TLS_image_in_rsc_BRESP);
    lenet_INST.image_in_rsc_BID(TLS_image_in_rsc_BID);
    lenet_INST.image_in_rsc_WREADY(TLS_image_in_rsc_WREADY);
    lenet_INST.image_in_rsc_WVALID(TLS_image_in_rsc_WVALID);
    lenet_INST.image_in_rsc_WUSER(TLS_image_in_rsc_WUSER);
    lenet_INST.image_in_rsc_WLAST(TLS_image_in_rsc_WLAST);
    lenet_INST.image_in_rsc_WSTRB(TLS_image_in_rsc_WSTRB);
    lenet_INST.image_in_rsc_WDATA(TLS_image_in_rsc_WDATA);
    lenet_INST.image_in_rsc_AWREADY(TLS_image_in_rsc_AWREADY);
    lenet_INST.image_in_rsc_AWVALID(TLS_image_in_rsc_AWVALID);
    lenet_INST.image_in_rsc_AWUSER(TLS_image_in_rsc_AWUSER);
    lenet_INST.image_in_rsc_AWREGION(TLS_image_in_rsc_AWREGION);
    lenet_INST.image_in_rsc_AWQOS(TLS_image_in_rsc_AWQOS);
    lenet_INST.image_in_rsc_AWPROT(TLS_image_in_rsc_AWPROT);
    lenet_INST.image_in_rsc_AWCACHE(TLS_image_in_rsc_AWCACHE);
    lenet_INST.image_in_rsc_AWLOCK(TLS_image_in_rsc_AWLOCK);
    lenet_INST.image_in_rsc_AWBURST(TLS_image_in_rsc_AWBURST);
    lenet_INST.image_in_rsc_AWSIZE(TLS_image_in_rsc_AWSIZE);
    lenet_INST.image_in_rsc_AWLEN(TLS_image_in_rsc_AWLEN);
    lenet_INST.image_in_rsc_AWADDR(TLS_image_in_rsc_AWADDR);
    lenet_INST.image_in_rsc_AWID(TLS_image_in_rsc_AWID);
    lenet_INST.image_in_rsc_triosy_lz(TLS_image_in_rsc_triosy_lz);
    lenet_INST.out_rsc_dat(TLS_out_rsc_dat);
    lenet_INST.out_rsc_triosy_lz(TLS_out_rsc_triosy_lz);

    CCS_ADAPTOR_TLS_image_in_rsc_AWID.inVECTOR(CCS_ADAPTOR_image_in_rsc_AWID);
    CCS_ADAPTOR_TLS_image_in_rsc_AWID.outSCALAR(TLS_image_in_rsc_AWID);

    CCS_ADAPTOR_TLS_image_in_rsc_AWUSER.inVECTOR(CCS_ADAPTOR_image_in_rsc_AWUSER);
    CCS_ADAPTOR_TLS_image_in_rsc_AWUSER.outSCALAR(TLS_image_in_rsc_AWUSER);

    CCS_ADAPTOR_TLS_image_in_rsc_WUSER.inVECTOR(CCS_ADAPTOR_image_in_rsc_WUSER);
    CCS_ADAPTOR_TLS_image_in_rsc_WUSER.outSCALAR(TLS_image_in_rsc_WUSER);

    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BID.inSCALAR(TLS_image_in_rsc_BID);
    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BID.outVECTOR(CCS_ADAPTOR_image_in_rsc_BID);

    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BUSER.inSCALAR(TLS_image_in_rsc_BUSER);
    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_BUSER.outVECTOR(CCS_ADAPTOR_image_in_rsc_BUSER);

    CCS_ADAPTOR_TLS_image_in_rsc_ARID.inVECTOR(CCS_ADAPTOR_image_in_rsc_ARID);
    CCS_ADAPTOR_TLS_image_in_rsc_ARID.outSCALAR(TLS_image_in_rsc_ARID);

    CCS_ADAPTOR_TLS_image_in_rsc_ARUSER.inVECTOR(CCS_ADAPTOR_image_in_rsc_ARUSER);
    CCS_ADAPTOR_TLS_image_in_rsc_ARUSER.outSCALAR(TLS_image_in_rsc_ARUSER);

    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RID.inSCALAR(TLS_image_in_rsc_RID);
    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RID.outVECTOR(CCS_ADAPTOR_image_in_rsc_RID);

    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RUSER.inSCALAR(TLS_image_in_rsc_RUSER);
    CCS_ADAPTOR_CCS_ADAPTOR_image_in_rsc_RUSER.outVECTOR(CCS_ADAPTOR_image_in_rsc_RUSER);

    image_in_rsc_INST.ACLK(clk);
    image_in_rsc_INST.ARESETn(rst);
    image_in_rsc_INST.AWID(CCS_ADAPTOR_image_in_rsc_AWID);
    image_in_rsc_INST.AWADDR(TLS_image_in_rsc_AWADDR);
    image_in_rsc_INST.AWLEN(TLS_image_in_rsc_AWLEN);
    image_in_rsc_INST.AWSIZE(TLS_image_in_rsc_AWSIZE);
    image_in_rsc_INST.AWBURST(TLS_image_in_rsc_AWBURST);
    image_in_rsc_INST.AWLOCK(TLS_image_in_rsc_AWLOCK);
    image_in_rsc_INST.AWCACHE(TLS_image_in_rsc_AWCACHE);
    image_in_rsc_INST.AWPROT(TLS_image_in_rsc_AWPROT);
    image_in_rsc_INST.AWQOS(TLS_image_in_rsc_AWQOS);
    image_in_rsc_INST.AWREGION(TLS_image_in_rsc_AWREGION);
    image_in_rsc_INST.AWUSER(CCS_ADAPTOR_image_in_rsc_AWUSER);
    image_in_rsc_INST.AWVALID(TLS_image_in_rsc_AWVALID);
    image_in_rsc_INST.AWREADY(TLS_image_in_rsc_AWREADY);
    image_in_rsc_INST.WDATA(TLS_image_in_rsc_WDATA);
    image_in_rsc_INST.WSTRB(TLS_image_in_rsc_WSTRB);
    image_in_rsc_INST.WLAST(TLS_image_in_rsc_WLAST);
    image_in_rsc_INST.WUSER(CCS_ADAPTOR_image_in_rsc_WUSER);
    image_in_rsc_INST.WVALID(TLS_image_in_rsc_WVALID);
    image_in_rsc_INST.WREADY(TLS_image_in_rsc_WREADY);
    image_in_rsc_INST.BID(CCS_ADAPTOR_image_in_rsc_BID);
    image_in_rsc_INST.BRESP(TLS_image_in_rsc_BRESP);
    image_in_rsc_INST.BUSER(CCS_ADAPTOR_image_in_rsc_BUSER);
    image_in_rsc_INST.BVALID(TLS_image_in_rsc_BVALID);
    image_in_rsc_INST.BREADY(TLS_image_in_rsc_BREADY);
    image_in_rsc_INST.ARID(CCS_ADAPTOR_image_in_rsc_ARID);
    image_in_rsc_INST.ARADDR(TLS_image_in_rsc_ARADDR);
    image_in_rsc_INST.ARLEN(TLS_image_in_rsc_ARLEN);
    image_in_rsc_INST.ARSIZE(TLS_image_in_rsc_ARSIZE);
    image_in_rsc_INST.ARBURST(TLS_image_in_rsc_ARBURST);
    image_in_rsc_INST.ARLOCK(TLS_image_in_rsc_ARLOCK);
    image_in_rsc_INST.ARCACHE(TLS_image_in_rsc_ARCACHE);
    image_in_rsc_INST.ARPROT(TLS_image_in_rsc_ARPROT);
    image_in_rsc_INST.ARQOS(TLS_image_in_rsc_ARQOS);
    image_in_rsc_INST.ARREGION(TLS_image_in_rsc_ARREGION);
    image_in_rsc_INST.ARUSER(CCS_ADAPTOR_image_in_rsc_ARUSER);
    image_in_rsc_INST.ARVALID(TLS_image_in_rsc_ARVALID);
    image_in_rsc_INST.ARREADY(TLS_image_in_rsc_ARREADY);
    image_in_rsc_INST.RID(CCS_ADAPTOR_image_in_rsc_RID);
    image_in_rsc_INST.RDATA(TLS_image_in_rsc_RDATA);
    image_in_rsc_INST.RRESP(TLS_image_in_rsc_RRESP);
    image_in_rsc_INST.RLAST(TLS_image_in_rsc_RLAST);
    image_in_rsc_INST.RUSER(CCS_ADAPTOR_image_in_rsc_RUSER);
    image_in_rsc_INST.RVALID(TLS_image_in_rsc_RVALID);
    image_in_rsc_INST.RREADY(TLS_image_in_rsc_RREADY);
    image_in_rsc_INST.tr_write_done(TLS_image_in_rsc_tr_write_done);
    image_in_rsc_INST.s_tdone(TLS_image_in_rsc_s_tdone);
    image_in_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_1)));

    out_rsc_INST.dat(TLS_out_rsc_dat);
    out_rsc_INST.clk(clk);
    out_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_2)));

    trios_monitor_image_in_rsc_triosy_lz_INST.trios(TLS_image_in_rsc_triosy_lz);
    trios_monitor_image_in_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_image_in.in_fifo(TLS_in_fifo_image_in);
    transactor_image_in.in_wait_ctrl_fifo(TLS_in_wait_ctrl_fifo_image_in);
    transactor_image_in.bind_clk(clk, true, rst);
    transactor_image_in.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_image_in.register_block(&image_in_rsc_INST, image_in_rsc_INST.basename(), TLS_image_in_rsc_triosy_lz,
        0, 783, 1);

    trios_monitor_out_rsc_triosy_lz_INST.trios(TLS_out_rsc_triosy_lz);
    trios_monitor_out_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_out.out_fifo(TLS_out_fifo_out);
    transactor_out.out_wait_ctrl_fifo(TLS_out_wait_ctrl_fifo_out);
    transactor_out.bind_clk(clk, true, rst);
    transactor_out.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_out.register_block(&out_rsc_INST, out_rsc_INST.basename(), TLS_out_rsc_triosy_lz, 0, 0, 1);

    testbench_INST.clk(clk);
    testbench_INST.ccs_image_in(TLS_in_fifo_image_in);
    testbench_INST.ccs_wait_ctrl_image_in(TLS_in_wait_ctrl_fifo_image_in);
    testbench_INST.ccs_out(TLS_out_fifo_out);
    testbench_INST.ccs_wait_ctrl_out(TLS_out_wait_ctrl_fifo_out);
    testbench_INST.design_is_idle(TLS_design_is_idle_reg);
    testbench_INST.enable_stalls(TLS_enable_stalls);
    testbench_INST.stall_coverage(TLS_stall_coverage);

    sync_generator_INST.clk(clk);
    sync_generator_INST.rst(rst);
    sync_generator_INST.in_sync(in_sync);
    sync_generator_INST.out_sync(out_sync);
    sync_generator_INST.inout_sync(inout_sync);
    sync_generator_INST.wait_for_init(wait_for_init);
    sync_generator_INST.catapult_start(catapult_start);
    sync_generator_INST.catapult_ready(catapult_ready);
    sync_generator_INST.catapult_done(catapult_done);

    catapult_monitor_INST.rst(rst);


    SC_METHOD(TLS_rst_method);
      sensitive_pos << TLS_rst;
      dont_initialize();

    SC_METHOD(max_sim_time_notify);
      sensitive << max_sim_time_event;
      dont_initialize();

    SC_METHOD(generate_reset);
      sensitive << generate_reset_event;
      sensitive << testbench_INST.reset_request_event;

    SC_METHOD(deadlock_watch);
      sensitive << clk;
      dont_initialize();

    SC_METHOD(deadlock_notify);
      sensitive << deadlock_event;
      dont_initialize();


    #if defined(CCS_SCVERIFY) && defined(CCS_DUT_RTL) && !defined(CCS_DUT_SYSC) && !defined(CCS_SYSC) && !defined(CCS_DUT_POWER)
        ccs_probe_monitor_INST = new ccs_probe_monitor("ccs_probe_monitor");
    ccs_probe_monitor_INST->clk(clk);
    ccs_probe_monitor_INST->rst(rst);
    #endif
    SIG_SC_LOGIC_0.write(SC_LOGIC_0);
    SIG_SC_LOGIC_1.write(SC_LOGIC_1);
    mt19937_init_genrand(19650218UL);
    install_observe_foreign_signals();
  }
};
void scverify_top::TLS_rst_method() {
  std::ostringstream msg;
  msg << "TLS_rst active @ " << sc_time_stamp();
  SC_REPORT_INFO("HW reset", msg.str().c_str());
  image_in_rsc_INST.clear();
  out_rsc_INST.clear();
}

void scverify_top::max_sim_time_notify() {
  testbench_INST.set_failed(true);
  testbench_INST.check_results();
  SC_REPORT_ERROR("System", "Specified maximum simulation time reached");
  sc_stop();
}

void scverify_top::start_of_simulation() {
  char *SCVerify_AUTOWAIT = getenv("SCVerify_AUTOWAIT");
  if (SCVerify_AUTOWAIT) {
    int l = atoi(SCVerify_AUTOWAIT);
    transactor_image_in.set_auto_wait_limit(l);
    transactor_out.set_auto_wait_limit(l);
  }
}

void scverify_top::setup_debug() {
#ifdef MC_DEFAULT_TRANSACTOR_LOG
  static int transactor_image_in_flags = MC_DEFAULT_TRANSACTOR_LOG;
  static int transactor_out_flags = MC_DEFAULT_TRANSACTOR_LOG;
#else
  static int transactor_image_in_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
  static int transactor_out_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
#endif
  static int transactor_image_in_count = -1;
  static int transactor_out_count = -1;

  // At the breakpoint, modify the local variables
  // above to turn on/off different levels of transaction
  // logging for each variable. Available flags are:
  //   MC_TRANSACTOR_EMPTY       - log empty FIFOs (on by default)
  //   MC_TRANSACTOR_UNDERFLOW   - log FIFOs that run empty and then are loaded again (off)
  //   MC_TRANSACTOR_READ        - log all read events
  //   MC_TRANSACTOR_WRITE       - log all write events
  //   MC_TRANSACTOR_LOAD        - log all FIFO load events
  //   MC_TRANSACTOR_DUMP        - log all FIFO dump events
  //   MC_TRANSACTOR_STREAMCNT   - log all streamed port index counter events
  //   MC_TRANSACTOR_WAIT        - log user specified handshake waits
  //   MC_TRANSACTOR_SIZE        - log input FIFO size updates

  std::ifstream debug_cmds;
  debug_cmds.open("scverify.cmd",std::fstream::in);
  if (debug_cmds.is_open()) {
    std::cout << "Reading SCVerify debug commands from file 'scverify.cmd'" << std::endl;
    std::string line;
    while (getline(debug_cmds,line)) {
      std::size_t pos1 = line.find(" ");
      if (pos1 == std::string::npos) continue;
      std::size_t pos2 = line.find(" ", pos1+1);
      std::string varname = line.substr(0,pos1);
      std::string flags = line.substr(pos1+1,pos2-pos1-1);
      std::string count = line.substr(pos2+1);
      debug(varname.c_str(),std::atoi(flags.c_str()),std::atoi(count.c_str()));
    }
    debug_cmds.close();
  } else {
    debug("transactor_image_in",transactor_image_in_flags,transactor_image_in_count);
    debug("transactor_out",transactor_out_flags,transactor_out_count);
  }
}

void scverify_top::debug(const char* varname, int flags, int count) {
  sc_module *xlator_p = 0;
  sc_attr_base *debug_attr_p = 0;
  if (strcmp(varname,"transactor_image_in") == 0)
    xlator_p = &transactor_image_in;
  if (strcmp(varname,"transactor_out") == 0)
    xlator_p = &transactor_out;
  if (xlator_p) {
    debug_attr_p = xlator_p->get_attribute("MC_TRANSACTOR_EVENT");
    if (!debug_attr_p) {
      debug_attr_p = new sc_attribute<int>("MC_TRANSACTOR_EVENT",flags);
      xlator_p->add_attribute(*debug_attr_p);
    }
    ((sc_attribute<int>*)debug_attr_p)->value = flags;
  }

  if (count>=0) {
    debug_attr_p = xlator_p->get_attribute("MC_TRANSACTOR_COUNT");
    if (!debug_attr_p) {
      debug_attr_p = new sc_attribute<int>("MC_TRANSACTOR_COUNT",count);
      xlator_p->add_attribute(*debug_attr_p);
    }
    ((sc_attribute<int>*)debug_attr_p)->value = count;
  }
}

// Process: SC_METHOD generate_reset
void scverify_top::generate_reset() {
  static bool activate_reset = true;
  static bool toggle_hw_reset = false;
  if (activate_reset || sc_time_stamp() == SC_ZERO_TIME) {
    setup_debug();
    activate_reset = false;
    rst.write(SC_LOGIC_1);
    rst_driver.reset_driver();
    generate_reset_event.notify(4.000000 , SC_NS);
  } else {
    if (toggle_hw_reset) {
      toggle_hw_reset = false;
      generate_reset_event.notify(4.000000 , SC_NS);
    } else {
      transactor_image_in.reset_streams();
      transactor_out.reset_streams();
      rst.write(SC_LOGIC_0);
    }
    activate_reset = true;
  }
}

void scverify_top::install_observe_foreign_signals() {
#if !defined(CCS_DUT_SYSC) && defined(DEADLOCK_DETECTION)
#if defined(CCS_DUT_CYCLE) || defined(CCS_DUT_RTL)
  OBSERVE_FOREIGN_SIGNAL(OFS_lenet_core_inst_lenet_core_image_in_rsci_inst_lenet_core_image_in_rsci_image_in_rsc_wait_ctrl_inst_image_in_rsci_s_re_core_sct,
      /scverify_top/rtl/lenet_core_inst/lenet_core_image_in_rsci_inst/lenet_core_image_in_rsci_image_in_rsc_wait_ctrl_inst/image_in_rsci_s_re_core_sct);
  OBSERVE_FOREIGN_SIGNAL(OFS_lenet_core_inst_lenet_core_image_in_rsci_inst_lenet_core_image_in_rsci_image_in_rsc_wait_ctrl_inst_image_in_rsci_s_rrdy,
      /scverify_top/rtl/lenet_core_inst/lenet_core_image_in_rsci_inst/lenet_core_image_in_rsci_image_in_rsc_wait_ctrl_inst/image_in_rsci_s_rrdy);
  OBSERVE_FOREIGN_SIGNAL(OFS_lenet_core_inst_lenet_core_image_in_rsci_inst_lenet_core_image_in_rsci_image_in_rsc_wait_dp_inst_image_in_rsci_s_raddr_core_sct,
      /scverify_top/rtl/lenet_core_inst/lenet_core_image_in_rsci_inst/lenet_core_image_in_rsci_image_in_rsc_wait_dp_inst/image_in_rsci_s_raddr_core_sct);
#endif
#endif
}

void scverify_top::deadlock_watch() {
#if !defined(CCS_DUT_SYSC) && defined(DEADLOCK_DETECTION)
#if defined(CCS_DUT_CYCLE) || defined(CCS_DUT_RTL)
#if defined(MTI_SYSTEMC) || defined(NCSC) || defined(VCS_SYSTEMC)
#endif
#endif
#endif
}

void scverify_top::deadlock_notify() {
  if (deadlocked.read() == SC_LOGIC_1) {
    testbench_INST.check_results();
    SC_REPORT_ERROR("System", "Simulation deadlock detected");
    sc_stop();
  }
}

#if defined(MC_SIMULATOR_OSCI) || defined(MC_SIMULATOR_VCS)
int sc_main(int argc, char *argv[]) {
  sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);
  scverify_top scverify_top("scverify_top");
  sc_start();
  return scverify_top.testbench_INST.failed();
}
#else
MC_MODULE_EXPORT(scverify_top);
#endif
