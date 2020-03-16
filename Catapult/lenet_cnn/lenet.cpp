#include<iostream>

#include "lenet.h"
#include "weights.h"
#include "bias.h"

#include "convolution.h"
#include "pooling.h"
#include "relu.h"
#include "fc.h"
#include "softmax.h"

void lenet(DTYPE image_in[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS],
			DTYPE out[PREDS])
{
//#pragma HLS DATAFLOW

DTYPE C1_out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS];


DTYPE R1_out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS];
DTYPE P1_out[C1_NUM_OUTCHAN][C2_IN_ROWS][C2_IN_COLS];

DTYPE C2_out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS];
DTYPE R2_out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS];
DTYPE P2_out[C2_NUM_OUTCHAN][P2_OUT_ROWS][P2_OUT_COLS];


DTYPE F_out[F_OUT_SIZE];

DTYPE FC1_out[FC1_OUT_SIZE];

DTYPE R3_out[FC1_OUT_SIZE];

DTYPE FC2_out[FC2_OUT_SIZE];
DTYPE R4_out[FC2_OUT_SIZE];

DTYPE FC3_out[FC3_OUT_SIZE];


conv2d_C1 (image_in, C1_weights, C1_biases, C1_out);

// R1 - relu 1
//// Same as C1 out
relu_R1(C1_out, R1_out);

// P1 - Maxpool 1
maxpool_P1( R1_out, P1_out);


// C2 - Convolution 2

conv2d_C2 ( P1_out, C2_weights, C2_biases, C2_out);

// R2 - relu 2
//// Same as C2
relu_R2( C2_out, R2_out);


// P2 - Maxpool 2
maxpool_P1( R2_out, P2_out);

// Flatten
flatten_F( P2_out, F_out);

// FC1 - Fully-Connected 1
fc_FC1( F_out,  FC1_weights, FC1_bias, FC1_out);

// R3 - relu 3
//// Same as FC1
relu_R3( FC1_out, R3_out);


// FC2 - Fully-Connected 2
fc_FC2( R3_out, FC2_weights, FC2_bias, FC2_out);

// R4 - relu 4
//// Same as FC2
relu_R4( FC2_out, R4_out);

// FC3 - Fully-Connected 3
fc_FC3(R4_out, FC3_weights, FC3_bias, FC3_out);

// SM - Softmax
softmax_SM(FC3_out, out);

}
