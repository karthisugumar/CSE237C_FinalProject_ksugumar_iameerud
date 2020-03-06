#include<iostream>
//#include <types.h>
//#include<conv2d.h>

const int FHEIGHT=14;
const int FWIDTH=14;
//const int NUM_INCHAN=32;
//const int NUM_OUTCHAN=64;
//const int KHEIGHT=3;
//const int KWIDTH=3;

typedef float DTYPE;

const int STRIDE = 1;
const int KSIZE=5;
const int NUM_INCHAN=1;
const int NUM_OUTCHAN=1;
const int IN_ROWS = 32;
const int IN_COLS = 32;

const int OUT_ROWS = 1 + (IN_ROWS-KSIZE)/STRIDE;
const int OUT_COLS = 1 + (IN_COLS-KSIZE)/STRIDE;


void conv2d(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
			DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE],
			DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS])
{

//accumulation buffer for each output channel
DTYPE acc_buf[OUT_ROWS][OUT_COLS];
DTYPE acc=0;
DTYPE data;

	OFM: for(int ofm=0; ofm<NUM_OUTCHAN; ofm++){
		//Clear accumulation buffer
		ROW_CLR: for(int r=0; r<OUT_ROWS; r++){
			COL_CLR: for(int c=0; c<OUT_COLS; c++){
				acc_buf[r][c]=0;
			}
		}

		IFM: for(int ifm=0; ifm<NUM_INCHAN; ifm++){
			ROW: for(int r=0; r<OUT_ROWS; r++){
				COL: for(int c=0; c<OUT_COLS; c++){

					K_ROW: for(int k_r=0; k_r<KSIZE; k_r+=STRIDE){
						K_COL: for(int k_c=0; k_c<KSIZE; k_c+=STRIDE){
							acc += filt[ofm][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
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
