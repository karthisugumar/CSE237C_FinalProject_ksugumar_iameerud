#include<iostream>
#include "types.h"

void relu(DTYPE in[IN_SIZE], DTYPE out[OUT_SIZE])
{
	DTYPE data;
	OUT: for(int c=0; c<OUT_SIZE; c++){
#pragma HLS PIPELINE
		data = in[c];
		out[c] = (data>0) ? data : 0;
	}//COL
}
