//  Catapult HLS Synthesis 10.5/858548 (Beta Release) Sun Feb 16 19:01:19 PST 2020
//  
//  Copyright (c) Mentor Graphics Corporation, 1996-2020, All Rights Reserved.
//                        UNPUBLISHED, LICENSED SOFTWARE.
//             CONFIDENTIAL AND PROPRIETARY INFORMATION WHICH IS THE
//                 PROPERTY OF MENTOR GRAPHICS OR ITS LICENSORS
//  
//  Running on Linux karthi@Karthi 4.4.0-18362-Microsoft x86_64 aol
//  
//  Package information: SIFLIBS v23.5_0.0, HLS_PKGS v23.5_0.0, 
//                       SIF_TOOLKITS v23.5_0.0, SIF_XILINX v23.5_0.0, 
//                       SIF_ALTERA v23.5_0.0, CCS_LIBS v23.5_0.0, 
//                       CDS_PPRO v10.3c_2, CDS_DesigChecker v10.5_beta2, 
//                       CDS_OASYS v19.1_3.7, CDS_PSR v19.2_0.9, 
//                       DesignPad v2.78_1.0
//  
solution new -state initial
solution options defaults
solution options set /Input/CppStandard c++11
solution options set /Output/GenerateCycleNetlist false
solution options set /Flows/SCVerify/USE_CCS_BLOCK true
flow package require /SCVerify
solution file add ./lenet_tb.cpp -type C++
directive set -PIPELINE_RAMP_UP true
directive set -CLUSTER_TYPE combinational
directive set -CLUSTER_FAST_MODE false
directive set -CLUSTER_RTL_SYN false
directive set -CLUSTER_OPT_CONSTANT_INPUTS true
directive set -CLUSTER_ADDTREE_IN_COUNT_THRESHOLD 0
directive set -CLUSTER_ADDTREE_IN_WIDTH_THRESHOLD 0
directive set -ROM_THRESHOLD 64
directive set -PROTOTYPE_ROM true
directive set -CHARACTERIZE_ROM false
directive set -OPT_CONST_MULTS use_library
directive set -CLOCK_OVERHEAD 20.000000
directive set -RESET_CLEARS_ALL_REGS use_library
directive set -START_FLAG {}
directive set -READY_FLAG {}
directive set -DONE_FLAG {}
directive set -TRANSACTION_DONE_SIGNAL true
directive set -STALL_FLAG false
directive set -IDLE_SIGNAL {}
directive set -REGISTER_IDLE_SIGNAL false
directive set -ARRAY_SIZE 1024
directive set -CHAN_IO_PROTOCOL use_library
directive set -IO_MODE super
directive set -UNROLL no
directive set -REALLOC true
directive set -MUXPATH true
directive set -TIMING_CHECKS true
directive set -ASSIGN_OVERHEAD 0
directive set -REGISTER_SHARING_LIMIT 0
directive set -REGISTER_SHARING_MAX_WIDTH_DIFFERENCE 8
directive set -SAFE_FSM false
directive set -NO_X_ASSIGNMENTS true
directive set -REG_MAX_FANOUT 0
directive set -FSM_BINARY_ENCODING_THRESHOLD 64
directive set -FSM_ENCODING none
directive set -LOGIC_OPT false
directive set -MEM_MAP_THRESHOLD 32
directive set -REGISTER_THRESHOLD 256
directive set -MERGEABLE true
directive set -SPECULATE true
directive set -DESIGN_GOAL area
go new
solution design set lenet -top
directive set -ASSUME_ARRAY_INDEX_IN_RANGE true
directive set -ARRAY_INDEX_OPTIMIZATION true
directive set -SCHED_USE_MULTICYCLE true
go analyze
solution design set lenet -top
solution library add nangate-45nm_beh -- -rtlsyntool OasysRTL -vendor Nangate -technology 045nm
solution library add ccs_sample_mem
solution library add amba
go libraries
directive set -CLOCKS {clk {-CLOCK_PERIOD 2.0 -CLOCK_EDGE rising -CLOCK_UNCERTAINTY 0.0 -CLOCK_HIGH_TIME 1.0 -RESET_SYNC_NAME rst -RESET_ASYNC_NAME arst_n -RESET_KIND sync -RESET_SYNC_ACTIVE high -RESET_ASYNC_ACTIVE low -ENABLE_ACTIVE high}}
go assembly
directive set /lenet/core/K_COL#3 -UNROLL yes
directive set /lenet/core/K_ROW#3 -UNROLL yes
directive set /lenet/core/K_COL#2 -UNROLL yes
directive set /lenet/core/K_ROW#2 -UNROLL yes
directive set /lenet/core/K_COL#1 -UNROLL yes
directive set /lenet/core/K_ROW#1 -UNROLL yes
directive set /lenet/core/K_COL -UNROLL yes
directive set /lenet/core/K_ROW -UNROLL yes
directive set /lenet/core/R3_OUT -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/R4_OUT -PIPELINE_INIT_INTERVAL 1
directive set /lenet/C1_weights.rom:rsc -INTERLEAVE 0
directive set /lenet/C1_biases.rom:rsc -INTERLEAVE 0
directive set /lenet/core/C1_out:rsc -INTERLEAVE 0
directive set /lenet/C1_weights.rom:rsc -BLOCK_SIZE 0
directive set /lenet/C1_biases.rom:rsc -BLOCK_SIZE 0
directive set /lenet/image_in:rsc -BLOCK_SIZE 0
directive set /lenet/core/OUT -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/R1_ROW -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/R2_ROW -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/DEN -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/FC1_out:rsc -INTERLEAVE 8
directive set /lenet/FC1_bias.rom:rsc -INTERLEAVE 0
directive set /lenet/FC1_weights.rom:rsc -INTERLEAVE 0
directive set /lenet/core/FC2_out:rsc -INTERLEAVE 4
directive set /lenet/core/FC3_out:rsc -INTERLEAVE 2
directive set /lenet/core/FC1_IN -PIPELINE_INIT_INTERVAL 2
directive set /lenet/core/FC2_IN -PIPELINE_INIT_INTERVAL 2
directive set /lenet/core/FC3_IN -PIPELINE_INIT_INTERVAL 2
directive set /lenet/core/C1_out:rsc -BLOCK_SIZE 784
directive set /lenet/core/C2_out:rsc -BLOCK_SIZE 100
directive set /lenet/core/C1_COL_CLR -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/C1_ROW_CPY -PIPELINE_INIT_INTERVAL 0
directive set /lenet/core/P2_COL -PIPELINE_INIT_INTERVAL 4
directive set /lenet/core/P1_COL -PIPELINE_INIT_INTERVAL 4
directive set /lenet/core/C1_COL_CPY -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/C1_COL -PIPELINE_INIT_INTERVAL 10
directive set /lenet/core/C2_COL_CLR -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/C2_COL_CPY -PIPELINE_INIT_INTERVAL 1
directive set /lenet/core/C2_COL -PIPELINE_INIT_INTERVAL 26
directive set /lenet/core/F_ROW -PIPELINE_INIT_INTERVAL 1
go architect
go extract
