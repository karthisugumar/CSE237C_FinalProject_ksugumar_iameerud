############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
solution options defaults
flow package require /SCVerify
solution options set /Flows/SCVerify/USE_CCS_BLOCK true
solution options set /Input/CppStandard c++11
solution options set /Output/GenerateCycleNetlist false

solution file add ./lenet_tb.cpp -type C++

go new
solution design set {lenet} -top
#Constraints for non-pow2 array/memory dimensions
directive set -SCHED_USE_MULTICYCLE true
directive set -ARRAY_INDEX_OPTIMIZATION true
directive set -ASSUME_ARRAY_INDEX_IN_RANGE true
go analyze

solution library add nangate-45nm_beh -- -rtlsyntool OasysRTL -vendor Nangate -technology 045nm
solution library add ccs_sample_mem
solution library add amba
go libraries

directive set -CLOCKS {clk {-CLOCK_PERIOD 10.0 -CLOCK_EDGE rising -CLOCK_UNCERTAINTY 1.25 -CLOCK_HIGH_TIME 5.0 -RESET_SYNC_NAME rst -RESET_ASYNC_NAME arst_n -RESET_KIND sync -RESET_SYNC_ACTIVE high -RESET_ASYNC_ACTIVE low -ENABLE_ACTIVE high}}

go assembly
go alloc
go extract
