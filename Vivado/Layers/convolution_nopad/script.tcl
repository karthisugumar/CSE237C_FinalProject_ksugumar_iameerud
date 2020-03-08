############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project conv2d_cnn
set_top conv2d
add_files conv2d_Alg.cpp
add_files types.h
add_files -tb conv2d_tb.cpp
open_solution "solution1"
set_part  {xc7z020clg400-1}
create_clock -period 10

source "./directives.tcl"
##csynth_design
