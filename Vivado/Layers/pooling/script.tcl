############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project maxpool_cnn
set_top maxpool
add_files maxpool_Alg.cpp
add_files types.h
add_files -tb maxpool_tb.cpp
add_files -tb pool_in.dat
add_files -tb pool_out.dat
open_solution "solution1"
set_part  {xc7z020clg400-1}
create_clock -period 10

source "./directives.tcl"
##csynth_design
