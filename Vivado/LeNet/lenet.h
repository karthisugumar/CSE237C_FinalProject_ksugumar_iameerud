#ifndef __LENET__
#define __LENET__

#include <ap_fixed.h>

typedef float DTYPE;

//Common parameters
const int C_STRIDE = 1; //Convolution Stride
const int P_STRIDE = 2; //Pooling Stride


//////  Declaration of Layers  //////

// C1 - Convolution 1
const int C1_KSIZE=3;
const int C1_NUM_INCHAN=1;
const int C1_NUM_OUTCHAN=6;
const int C1_IN_ROWS = 28;
const int C1_IN_COLS = 28;
const int C1_OUT_ROWS = 28;
const int C1_OUT_COLS = 28;

void conv2d_C1 (DTYPE in[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS],
		const DTYPE filt[C1_NUM_OUTCHAN][C1_NUM_INCHAN][C1_KSIZE][C1_KSIZE],
		const DTYPE bias[C1_NUM_OUTCHAN],
		DTYPE out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS]);

// R1 - relu 1
//// Same as C1 out
void relu_R1(DTYPE in[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS],
		DTYPE out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS]);

// P1 - Maxpool 1
const int C2_IN_ROWS = 14;
const int C2_IN_COLS = 14;
const int P_KSIZE = 2;
void maxpool_P1(DTYPE in[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS],
		DTYPE out[C1_NUM_OUTCHAN][C2_IN_ROWS][C2_IN_COLS]);


// C2 - Convolution 2
const int C2_KSIZE=5;
const int C2_OUT_ROWS = 10;
const int C2_OUT_COLS = 10;
const int C2_NUM_OUTCHAN=16;

void conv2d_C2 (DTYPE in[C1_NUM_OUTCHAN][C2_IN_ROWS][C2_IN_COLS],
		const DTYPE filt[C2_NUM_OUTCHAN][C1_NUM_OUTCHAN][C2_KSIZE][C2_KSIZE],
		const DTYPE bias[C2_NUM_OUTCHAN],
		DTYPE out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS]);

// R2 - relu 2
//// Same as C2
void relu_R2(DTYPE in[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS],
		DTYPE out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS]);


// P2 - Maxpool 2
const int P2_OUT_ROWS = 5;
const int P2_OUT_COLS = 5;
void maxpool_P1(DTYPE in[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS],
		DTYPE out[C2_NUM_OUTCHAN][P2_OUT_ROWS][P2_OUT_COLS]);

// Flatten
const int F_OUT_SIZE = 400;
void flatten_F(DTYPE in[C2_NUM_OUTCHAN][P2_OUT_ROWS][P2_OUT_COLS], 
			DTYPE out[F_OUT_SIZE]);

// FC1 - Fully-Connected 1
const int FC1_OUT_SIZE = 120;
void fc_FC1(DTYPE in[F_OUT_SIZE], const DTYPE kernel[FC1_OUT_SIZE][F_OUT_SIZE],
		const DTYPE bias[FC1_OUT_SIZE], DTYPE out[FC1_OUT_SIZE]);

// R3 - relu 3
//// Same as FC1
void relu_R3(DTYPE in[FC1_OUT_SIZE],
		DTYPE out[FC1_OUT_SIZE]);


// FC2 - Fully-Connected 2
const int FC2_OUT_SIZE = 84;
void fc_FC2(DTYPE in[FC1_OUT_SIZE], const DTYPE kernel[FC2_OUT_SIZE][FC1_OUT_SIZE],
		const DTYPE bias[FC2_OUT_SIZE], DTYPE out[FC2_OUT_SIZE]);

// R4 - relu 4
//// Same as FC2
void relu_R4(DTYPE in[FC2_OUT_SIZE],
		DTYPE out[FC2_OUT_SIZE]);

// FC3 - Fully-Connected 3
const int FC3_OUT_SIZE = 10;
void fc_FC3(DTYPE in[FC2_OUT_SIZE], const DTYPE kernel[FC3_OUT_SIZE][FC2_OUT_SIZE],
		const DTYPE bias[FC3_OUT_SIZE], DTYPE out[FC3_OUT_SIZE]);

// SM - Softmax
const int PREDS = 10;
void softmax_SM(DTYPE in[FC3_OUT_SIZE], DTYPE out[PREDS]);


//Declare LeNet Top
void lenet(DTYPE image_in[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS],
			DTYPE out[PREDS]);
#endif
