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
