#include<iostream>
#include "types.h"
//#include<conv2d.h>

using namespace std;

void conv2d(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
			DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE],
			DTYPE bias[NUM_OUTCHAN],
			DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS])
{

//accumulation buffer for each output channel
DTYPE acc_buf[OUT_ROWS][OUT_COLS];
DTYPE acc=0;
DTYPE data;

	OFM: for(int ofm=0; ofm<NUM_OUTCHAN; ofm++){
		//Add Bias to accumulation buffer
		ROW_CLR: for(int r=0; r<OUT_ROWS; r++){
			COL_CLR: for(int c=0; c<OUT_COLS; c++){
				acc_buf[r][c]=bias[ofm];
			}
		}

		IFM: for(int ifm=0; ifm<NUM_INCHAN; ifm++){
			ROW: for(int r=0; r<OUT_ROWS; r++){
				COL: for(int c=0; c<OUT_COLS; c++){
					acc=0;

					K_ROW: for(int kr=0; kr<KSIZE; kr+=STRIDE){
						K_COL: for(int kc=0; kc<KSIZE; kc+=STRIDE){
							int ridx = r + kr - KSIZE/2;
							int cidx = c + kc - KSIZE/2;
							if(ridx < 0 || ridx >= OUT_ROWS || cidx < 0 || cidx >= OUT_COLS){//zero pad boundary when index out of bounds
                    			data = 0;
                    		}else{
                    			data=in[ifm][ridx][cidx];
                    		}
							acc += filt[ofm][ifm][kr][kc]*data;
						}
					}

					acc_buf[r][c]+= acc;
				}//COL
			} //ROW
		} //IFM

		//copy to output
		ROW_CPY:for(int r=0;r<OUT_ROWS;r++){
          COL_CPY:for(int c=0;c<OUT_COLS;c++){
            out[ofm][r][c] = acc_buf[r][c];
           	}
		}

	} //OFM

}
