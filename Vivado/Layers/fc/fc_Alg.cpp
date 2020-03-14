#include<iostream>
#include "fc.h"


void fc(DTYPE in[IN_SIZE], const DTYPE kernel[OUT_SIZE][IN_SIZE],
		const DTYPE bias[OUT_SIZE], DTYPE out[OUT_SIZE])
{
	OUT: for(int o=0; o<OUT_SIZE; o+=8){
		out[o] = bias[o];
		out[o+1] = bias[o+1];
		out[o+2] = bias[o+2];
		out[o+3] = bias[o+3];
		out[o+4] = bias[o+4];
		out[o+5] = bias[o+5];
		out[o+6] = bias[o+6];
		out[o+7] = bias[o+7];
		IN: for(int i=0; i<IN_SIZE; i++){
#pragma HLS PIPELINE
			out[o] += kernel[o][i]*in[i];
			out[o+1] += kernel[o+1][i]*in[i];
			out[o+2] += kernel[o+2][i]*in[i];
			out[o+3] += kernel[o+3][i]*in[i];
			out[o+4] += kernel[o+4][i]*in[i];
			out[o+5] += kernel[o+5][i]*in[i];
			out[o+6] += kernel[o+6][i]*in[i];
			out[o+7] += kernel[o+7][i]*in[i];
		}//IN
	}//OUT

}
