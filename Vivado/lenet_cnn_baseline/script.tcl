############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project lenet_cnn
set_top lenet

add_files lenet.cpp
add_files weights.h
add_files bias.h
add_files convolution.h
add_files pooling.h
add_files relu.h
add_files fc.h
add_files expTable.h
add_files softmax.h

add_files -tb lenet_tb.cpp
add_files -tb image_7_in.dat
add_files -tb image_7_out.dat

open_solution "solution1"
set_part  {xc7z020clg400-1}
create_clock -period 10

#source "./directives.tcl"
##csynth_design
