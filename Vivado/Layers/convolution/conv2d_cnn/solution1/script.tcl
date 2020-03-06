############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project conv2d_cnn
set_top conv2d
add_files conv2d_Alg_pad.cpp
add_files types.h
add_files -tb MNIST_in_7.dat
add_files -tb conv1_bias.dat
add_files -tb conv1_kernel.dat
add_files -tb conv1_out_7.dat
add_files -tb conv2d_tb.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
#source "./conv2d_cnn/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
