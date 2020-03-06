#include<iostream>
#include "flatten.h"

void flatten(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
			DTYPE out[OUT_SIZE])
{
	int idx=0;

	IFM: for(int ifm=0; ifm<NUM_INCHAN; ifm++){
		ROW: for(int r=0; r<IN_ROWS; r++){
			COL: for(int c=0; c<IN_COLS; c++){
				out[idx++]=in[ifm][r][c];
			}
		}
	}
}
