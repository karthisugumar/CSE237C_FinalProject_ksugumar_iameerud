#include<iostream>
#include "types.h"

void conv2d(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
			const DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE],
			const DTYPE bias[NUM_OUTCHAN],
			DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS])
{

//accumulation buffer for each output channel
DTYPE acc_buf_0[OUT_ROWS][OUT_COLS];
DTYPE acc_buf_1[OUT_ROWS][OUT_COLS];
DTYPE acc_buf_2[OUT_ROWS][OUT_COLS];
DTYPE acc_buf_3[OUT_ROWS][OUT_COLS];

DTYPE acc_0=0;
DTYPE acc_1=0;
DTYPE acc_2=0;
DTYPE acc_3=0;

DTYPE data;

	OFM: for(int ofm=0; ofm<NUM_OUTCHAN; ofm+=4){
		//Clear accumulation buffer
		ROW_CLR: for(int r=0; r<OUT_ROWS; r++){
			COL_CLR: for(int c=0; c<OUT_COLS; c++){
#pragma HLS PIPELINE
				acc_buf_0[r][c]=bias[ofm];
				acc_buf_1[r][c]=bias[ofm+1];
				acc_buf_2[r][c]=bias[ofm+2];
				acc_buf_3[r][c]=bias[ofm+3];
			}
		}

		IFM: for(int ifm=0; ifm<NUM_INCHAN; ifm++){
			ROW: for(int r=0; r<OUT_ROWS; r++){
				COL: for(int c=0; c<OUT_COLS; c++){
#pragma HLS PIPELINE
					DTYPE acc_0=0;
					DTYPE acc_1=0;
					DTYPE acc_2=0;
					DTYPE acc_3=0;

					K_ROW: for(int k_r=0; k_r<KSIZE; k_r+=STRIDE){
						K_COL: for(int k_c=0; k_c<KSIZE; k_c+=STRIDE){
							acc_0 += filt[ofm][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
							acc_1 += filt[ofm+1][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
							acc_2 += filt[ofm+2][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
							acc_3 += filt[ofm+3][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
						}
					}

					acc_buf_0[r][c]+= acc_0;
					acc_buf_1[r][c]+= acc_1;
					acc_buf_2[r][c]+= acc_2;
					acc_buf_3[r][c]+= acc_3;

				}//COL
			} //ROW
		} //IFM

		//copy to output
		ROW_CPY:for(int r=0;r<OUT_ROWS;r++){
          COL_CPY:for(int c=0;c<OUT_COLS;c++){
#pragma HLS PIPELINE
            out[ofm][r][c] = acc_buf_0[r][c];
            out[ofm+1][r][c] = acc_buf_1[r][c];
            out[ofm+2][r][c] = acc_buf_2[r][c];
            out[ofm+3][r][c] = acc_buf_3[r][c];
           	}
		}

	} //OFM

}
