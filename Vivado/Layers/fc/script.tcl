############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project fc_cnn
set_top fc
add_files fc_Alg.cpp
add_files fc.h
add_files -tb fc_tb.cpp
add_files -tb fc_kernel_in.dat
add_files -tb fc_bias_in.dat
add_files -tb fc_in.dat
add_files -tb fc_out.dat
# add_files -tb fc_in.dat
# add_files -tb fc_out.dat
open_solution "solution1"
set_part  {xc7z020clg400-1}
create_clock -period 10

source "./directives.tcl"
##csynth_design
