############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project softmax_cnn
set_top softmax
add_files expTable.h
add_files softmax_Alg.cpp
add_files types.h
add_files -tb softmax_in.dat
add_files -tb softmax_out.dat
add_files -tb softmax_tb.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
#source "./softmax_cnn/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
