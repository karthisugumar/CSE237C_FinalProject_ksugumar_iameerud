#include<iostream>
#include "types.h"

void relu(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
		DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS])
{

	DTYPE data;

	OFM: for(int ofm=0; ofm<NUM_OUTCHAN; ofm++){
		ROW: for(int r=0; r<OUT_ROWS; r++){
#pragma HLS PIPELINE
			COL: for(int c=0; c<OUT_COLS; c++){
#pragma HLS PIPELINE
				data = in[ofm][r][c];
				out[ofm][r][c] = (data>0) ? data : 0;
			}//COL
		}//ROW
	}//OFM
}
