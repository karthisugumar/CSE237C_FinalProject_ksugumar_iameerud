#ifndef __FC__
#define __FC__


// Flatten
void flatten_F(DTYPE in[C2_NUM_OUTCHAN][P2_OUT_ROWS][P2_OUT_COLS], 
			DTYPE out[F_OUT_SIZE])
{
	int idx=0;

	F_IFM: for(int ifm=0; ifm<C2_NUM_OUTCHAN; ifm++){
		F_ROW: for(int r=0; r<P2_OUT_ROWS; r++){
//#pragma HLS PIPELINE
			F_COL: for(int c=0; c<P2_OUT_COLS; c++){
//#pragma HLS PIPELINE
				out[idx++]=in[ifm][r][c];
			}
		}
	}
}


PARAM_TYPE kernel_fc1[FC1_OUT_SIZE][F_OUT_SIZE];
PARAM_TYPE bias_fc1[FC1_OUT_SIZE];
DTYPE out_fc1[FC1_OUT_SIZE];

// FC1 - Fully-Connected 1
void fc_FC1(DTYPE in[F_OUT_SIZE], const PARAM_TYPE kernel_fc1[FC1_OUT_SIZE][F_OUT_SIZE],
		const PARAM_TYPE bias_fc1[FC1_OUT_SIZE], DTYPE out_fc1[FC1_OUT_SIZE])
{
//#pragma HLS ARRAY_PARTITION variable=kernel_fc1 cyclic factor=8 dim=1
//#pragma HLS ARRAY_PARTITION variable=bias_fc1 cyclic factor=8 dim=1
//#pragma HLS ARRAY_PARTITION variable=out_fc1 cyclic factor=8 dim=1

	FC1_OUT: for(int o=0; o<FC1_OUT_SIZE; o+=8){
		out_fc1[o] = bias_fc1[o];
		out_fc1[o+1] = bias_fc1[o+1];
		out_fc1[o+2] = bias_fc1[o+2];
		out_fc1[o+3] = bias_fc1[o+3];

		out_fc1[o+4] = bias_fc1[o+4];
		out_fc1[o+5] = bias_fc1[o+5];
		out_fc1[o+6] = bias_fc1[o+6];
		out_fc1[o+7] = bias_fc1[o+7];

		FC1_IN: for(int i=0; i<F_OUT_SIZE; i++){
	//#pragma HLS PIPELINE
			out_fc1[o] += kernel_fc1[o][i]*in[i];
			out_fc1[o+1] += kernel_fc1[o+1][i]*in[i];
			out_fc1[o+2] += kernel_fc1[o+2][i]*in[i];
			out_fc1[o+3] += kernel_fc1[o+3][i]*in[i];

			out_fc1[o+4] += kernel_fc1[o+4][i]*in[i];
			out_fc1[o+5] += kernel_fc1[o+5][i]*in[i];
			out_fc1[o+6] += kernel_fc1[o+6][i]*in[i];
			out_fc1[o+7] += kernel_fc1[o+7][i]*in[i];
		}//IN
	}//OUT

}

PARAM_TYPE kernel_fc2[FC2_OUT_SIZE][FC1_OUT_SIZE];
PARAM_TYPE bias_fc2[FC2_OUT_SIZE];
DTYPE out_fc2[FC2_OUT_SIZE];

// FC2 - Fully-Connected 2
void fc_FC2(DTYPE in[FC1_OUT_SIZE], const PARAM_TYPE kernel_fc2[FC2_OUT_SIZE][FC1_OUT_SIZE],
		const PARAM_TYPE bias_fc2[FC2_OUT_SIZE], DTYPE out_fc2[FC2_OUT_SIZE])
{
//#pragma HLS ARRAY_PARTITION variable=bias_fc2 cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=kernel_fc2 cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=out_fc2 cyclic factor=4 dim=1
	FC2_OUT: for(int o=0; o<FC2_OUT_SIZE; o+=4){
		out_fc2[o] = bias_fc2[o];
		out_fc2[o+1] = bias_fc2[o+1];
		out_fc2[o+2] = bias_fc2[o+2];
		out_fc2[o+3] = bias_fc2[o+3];
		FC2_IN: for(int i=0; i<FC1_OUT_SIZE; i++){
	//#pragma HLS PIPELINE
			out_fc2[o] += kernel_fc2[o][i]*in[i];
			out_fc2[o+1] += kernel_fc2[o+1][i]*in[i];
			out_fc2[o+2] += kernel_fc2[o+2][i]*in[i];
			out_fc2[o+3] += kernel_fc2[o+3][i]*in[i];
		}//IN
	}//OUT

}


PARAM_TYPE kernel_fc3[FC2_OUT_SIZE][FC1_OUT_SIZE];
PARAM_TYPE bias_fc3[FC2_OUT_SIZE];
DTYPE out_fc3[FC2_OUT_SIZE];

// FC3 - Fully-Connected 3
void fc_FC3(DTYPE in[FC2_OUT_SIZE], const PARAM_TYPE kernel_fc3[FC3_OUT_SIZE][FC2_OUT_SIZE],
		const PARAM_TYPE bias_fc3[FC3_OUT_SIZE], DTYPE out_fc3[FC3_OUT_SIZE])
{
//#pragma HLS ARRAY_PARTITION variable=out_fc3 cyclic factor=2 dim=1
//#pragma HLS ARRAY_PARTITION variable=bias_fc3 cyclic factor=2 dim=1
//#pragma HLS ARRAY_PARTITION variable=kernel_fc3 cyclic factor=2 dim=1
	FC3_OUT: for(int o=0; o<FC3_OUT_SIZE; o+=2){
		out_fc3[o] = bias_fc3[o];
		out_fc3[o+1] = bias_fc3[o+1];
		FC3_IN: for(int i=0; i<FC2_OUT_SIZE; i++){
	//#pragma HLS PIPELINE
			out_fc3[o] += kernel_fc3[o][i]*in[i];
			out_fc3[o+1] += kernel_fc3[o+1][i]*in[i];
		}//IN
	}//OUT

}

#endif
