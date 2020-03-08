#include<iostream>
#include "types.h"


void maxpool(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
			DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS])
{
	DTYPE max=0,data,temp;

	OFM: for(int ofm=0; ofm<NUM_INCHAN; ofm++){
		ROW: for(int r=0; r<IN_ROWS; r+=STRIDE){
			COL: for(int c=0; c<IN_COLS; c+=STRIDE){
#pragma HLS PIPELINE

				K_ROW: for(int k_r=0; k_r<KSIZE; k_r++){
					K_COL: for(int k_c=0; k_c<KSIZE; k_c++){
						temp = in[ofm][r + k_r][c + k_c];
						if(temp>max){
							max = temp;
						}
					}//K_COL
				}//K_ROW
				out[ofm][r/STRIDE][c/STRIDE] = max;
				max=0;
			}//COL
		}//ROW
	}//OFM
}
