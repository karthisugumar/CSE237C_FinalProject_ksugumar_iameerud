#include<iostream>
#include "fc.h"


void fc(DTYPE in[IN_SIZE], DTYPE kernel[OUT_SIZE][IN_SIZE],
		DTYPE bias[OUT_SIZE], DTYPE out[OUT_SIZE])
{
	OUT: for(int o=0; o<OUT_SIZE; o++){
		out[o] = bias[o];
		IN: for(int i=0; i<IN_SIZE; i++){
			out[o] += kernel[o][i]*in[i];
		}//IN
	}//OUT

}
