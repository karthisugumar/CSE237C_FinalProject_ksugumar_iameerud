#include<iostream>
#include "types.h"
//#include<conv2d.h>

using namespace std;

void conv2d(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
			const DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE],
			const DTYPE bias[NUM_OUTCHAN],
			DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS])
{
#pragma HLS ARRAY_PARTITION variable=filt cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=out cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=bias cyclic factor=2 dim=1

//accumulation buffer for each output channel
DTYPE acc_buf_0[OUT_ROWS][OUT_COLS];
DTYPE acc_buf_1[OUT_ROWS][OUT_COLS];

DTYPE acc_0=0;
DTYPE acc_1=0;

DTYPE data;

	OFM: for(int ofm=0; ofm<NUM_OUTCHAN; ofm+=2){
		//Add Bias to accumulation buffer
		ROW_CLR: for(int r=0; r<OUT_ROWS; r++){
			COL_CLR: for(int c=0; c<OUT_COLS; c++){
#pragma HLS PIPELINE
				acc_buf_0[r][c]=bias[ofm];
				acc_buf_1[r][c]=bias[ofm+1];
			}
		}

		IFM: for(int ifm=0; ifm<NUM_INCHAN; ifm++){
			ROW: for(int r=0; r<OUT_ROWS; r++){
				COL: for(int c=0; c<OUT_COLS; c++){
#pragma HLS PIPELINE
					acc_0=0;
					acc_1=0;

					K_ROW: for(int kr=0; kr<KSIZE; kr+=STRIDE){
						K_COL: for(int kc=0; kc<KSIZE; kc+=STRIDE){
							int ridx = r + kr - KSIZE/2;
							int cidx = c + kc - KSIZE/2;
							if(ridx < 0 || ridx >= OUT_ROWS || cidx < 0 || cidx >= OUT_COLS){//zero pad boundary when index out of bounds
                    			data = 0;
                    		}else{
                    			data=in[ifm][ridx][cidx];
                    		}
							acc_0 += filt[ofm][ifm][kr][kc]*data;
							acc_1 += filt[ofm+1][ifm][kr][kc]*data;
						}
					}

					acc_buf_0[r][c]+= acc_0;
					acc_buf_1[r][c]+= acc_1;
				}//COL
			} //ROW
		} //IFM

		//copy to output
		ROW_CPY:for(int r=0;r<OUT_ROWS;r++){
          COL_CPY:for(int c=0;c<OUT_COLS;c++){
#pragma HLS PIPELINE
            out[ofm][r][c] = acc_buf_0[r][c];
            out[ofm+1][r][c] = acc_buf_1[r][c];
           	}
		}

	} //OFM

}
