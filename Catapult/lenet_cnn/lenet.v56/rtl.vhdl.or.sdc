# written for flow package OasysRTL 
set sdc_version 1.7 

set_operating_conditions typical
set_load 2.0 [all_outputs]
## driver/slew constraints on inputs
set data_inputs [list image_in_rsc_AWID {image_in_rsc_AWADDR[*]} {image_in_rsc_AWLEN[*]} {image_in_rsc_AWSIZE[*]} {image_in_rsc_AWBURST[*]} image_in_rsc_AWLOCK {image_in_rsc_AWCACHE[*]} {image_in_rsc_AWPROT[*]} {image_in_rsc_AWQOS[*]} {image_in_rsc_AWREGION[*]} image_in_rsc_AWUSER image_in_rsc_AWVALID {image_in_rsc_WDATA[*]} {image_in_rsc_WSTRB[*]} image_in_rsc_WLAST image_in_rsc_WUSER image_in_rsc_WVALID image_in_rsc_BREADY image_in_rsc_ARID {image_in_rsc_ARADDR[*]} {image_in_rsc_ARLEN[*]} {image_in_rsc_ARSIZE[*]} {image_in_rsc_ARBURST[*]} image_in_rsc_ARLOCK {image_in_rsc_ARCACHE[*]} {image_in_rsc_ARPROT[*]} {image_in_rsc_ARQOS[*]} {image_in_rsc_ARREGION[*]} image_in_rsc_ARUSER image_in_rsc_ARVALID image_in_rsc_RREADY image_in_rsc_tr_write_done image_in_rsc_s_tdone]
set_driving_cell -no_design_rule -library NangateOpenCellLibrary -lib_cell BUF_X2 -pin Z $data_inputs
set_units -time ns
# time_factor: 1.0

create_clock -name clk -period 2.0 -waveform { 0.0 1.0 } [get_ports {clk}]
set_clock_uncertainty 0.0 [get_clocks {clk}]

create_clock -name virtual_io_clk -period 2.0
## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp/a[*]} {lenet_core_inst/OUT_div_19_cmp/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_1) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_1/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_1/a[*]} {lenet_core_inst/OUT_div_19_cmp_1/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_1/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_2) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_2/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_2/a[*]} {lenet_core_inst/OUT_div_19_cmp_2/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_2/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_3) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_3/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_3/a[*]} {lenet_core_inst/OUT_div_19_cmp_3/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_3/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_4) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_4/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_4/a[*]} {lenet_core_inst/OUT_div_19_cmp_4/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_4/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_5) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_5/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_5/a[*]} {lenet_core_inst/OUT_div_19_cmp_5/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_5/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_6) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_6/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_6/a[*]} {lenet_core_inst/OUT_div_19_cmp_6/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_6/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_7) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_7/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_7/a[*]} {lenet_core_inst/OUT_div_19_cmp_7/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_7/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_8) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_8/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_8/a[*]} {lenet_core_inst/OUT_div_19_cmp_8/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_8/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_9) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_9/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_9/a[*]} {lenet_core_inst/OUT_div_19_cmp_9/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_9/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_10) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_10/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_10/a[*]} {lenet_core_inst/OUT_div_19_cmp_10/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_10/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_11) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_11/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_11/a[*]} {lenet_core_inst/OUT_div_19_cmp_11/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_11/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_12) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_12/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_12/a[*]} {lenet_core_inst/OUT_div_19_cmp_12/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_12/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_13) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_13/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_13/a[*]} {lenet_core_inst/OUT_div_19_cmp_13/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_13/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_14) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_14/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_14/a[*]} {lenet_core_inst/OUT_div_19_cmp_14/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_14/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_15) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_15/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_15/a[*]} {lenet_core_inst/OUT_div_19_cmp_15/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_15/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_16) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_16/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_16/a[*]} {lenet_core_inst/OUT_div_19_cmp_16/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_16/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_17) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_17/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_17/a[*]} {lenet_core_inst/OUT_div_19_cmp_17/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_17/z[*]}}]

## Multi-cycle component nangate-45nm_beh.mgc_div (OUT_div_19_cmp_18) [cycles: 19]
set_multicycle_path 19 -through [get_pins {{lenet_core_inst/OUT_div_19_cmp_18/z[*]}}]
set_min_delay 0 -from [get_pins {{lenet_core_inst/OUT_div_19_cmp_18/a[*]} {lenet_core_inst/OUT_div_19_cmp_18/b[*]}}] -to [get_pins {{lenet_core_inst/OUT_div_19_cmp_18/z[*]}}]

## IO TIMING CONSTRAINTS
set_input_delay -clock [get_clocks {clk}] 0.0 [get_ports {rst}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_s_tdone}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_tr_write_done}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_RREADY}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_RVALID}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_RUSER}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_RLAST}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_RRESP[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_RDATA[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_RID}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_ARREADY}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARVALID}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARUSER}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARREGION[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARQOS[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARPROT[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARCACHE[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARLOCK}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARBURST[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARSIZE[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARLEN[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARADDR[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_ARID}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_BREADY}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_BVALID}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_BUSER}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_BRESP[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_BID}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_WREADY}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_WVALID}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_WUSER}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_WLAST}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_WSTRB[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_WDATA[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_AWREADY}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWVALID}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWUSER}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWREGION[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWQOS[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWPROT[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWCACHE[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWLOCK}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWBURST[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWSIZE[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWLEN[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWADDR[*]}]
set_input_delay -clock [get_clocks {clk}] 0.19392 [get_ports {image_in_rsc_AWID}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_triosy_lz}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {out_rsc_dat[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {out_rsc_triosy_lz}]

