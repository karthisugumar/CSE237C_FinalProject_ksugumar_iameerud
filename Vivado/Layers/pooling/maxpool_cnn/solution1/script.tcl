############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project maxpool_cnn
set_top maxpool
add_files types.h
add_files maxpool_Alg.cpp
add_files -tb conv1_out_7.dat
add_files -tb maxpool_tb.cpp -cflags "-Wno-unknown-pragmas"
add_files -tb pool1_out_7.dat
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
#source "./maxpool_cnn/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
