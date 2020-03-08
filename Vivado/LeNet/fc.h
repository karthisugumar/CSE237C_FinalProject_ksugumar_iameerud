#ifndef __FC__
#define __FC__


// Flatten
void flatten_F(DTYPE in[C2_NUM_OUTCHAN][P2_OUT_ROWS][P2_OUT_COLS], 
			DTYPE out[F_OUT_SIZE])
{
	int idx=0;

	IFM: for(int ifm=0; ifm<C2_NUM_OUTCHAN; ifm++){
		ROW: for(int r=0; r<P2_OUT_ROWS; r++){
#pragma HLS PIPELINE
			COL: for(int c=0; c<P2_OUT_COLS; c++){
#pragma HLS PIPELINE
				out[idx++]=in[ifm][r][c];
			}
		}
	}
}

// FC1 - Fully-Connected 1
void fc_FC1(DTYPE in[F_OUT_SIZE], const DTYPE kernel[FC1_OUT_SIZE][F_OUT_SIZE],
		const DTYPE bias[FC1_OUT_SIZE], DTYPE out[FC1_OUT_SIZE])
{
	OUT: for(int o=0; o<FC1_OUT_SIZE; o++){
		out[o] = bias[o];
		IN: for(int i=0; i<F_OUT_SIZE; i++){
#pragma HLS PIPELINE
			out[o] += kernel[o][i]*in[i];
		}//IN
	}//OUT

}

// FC2 - Fully-Connected 2
void fc_FC2(DTYPE in[FC1_OUT_SIZE], const DTYPE kernel[FC2_OUT_SIZE][FC1_OUT_SIZE],
		const DTYPE bias[FC2_OUT_SIZE], DTYPE out[FC2_OUT_SIZE])
{
	OUT: for(int o=0; o<FC2_OUT_SIZE; o++){
		out[o] = bias[o];
		IN: for(int i=0; i<FC1_OUT_SIZE; i++){
#pragma HLS PIPELINE
			out[o] += kernel[o][i]*in[i];
		}//IN
	}//OUT

}

// FC3 - Fully-Connected 3
void fc_FC3(DTYPE in[FC2_OUT_SIZE], const DTYPE kernel[FC3_OUT_SIZE][FC2_OUT_SIZE],
		const DTYPE bias[FC3_OUT_SIZE], DTYPE out[FC3_OUT_SIZE])
{
	OUT: for(int o=0; o<FC3_OUT_SIZE; o++){
		out[o] = bias[o];
		IN: for(int i=0; i<FC2_OUT_SIZE; i++){
#pragma HLS PIPELINE
			out[o] += kernel[o][i]*in[i];
		}//IN
	}//OUT

}

#endif
