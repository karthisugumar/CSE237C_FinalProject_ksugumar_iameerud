############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project softmax_cnn
set_top softmax
add_files softmax_Alg.cpp
add_files types.h
add_file expTable.h
add_files -tb softmax_tb.cpp
add_files -tb softmax_in.dat
add_files -tb softmax_out.dat
open_solution "solution1"
set_part  {xc7z020clg400-1}
create_clock -period 10

source "./directives.tcl"
##csynth_design
