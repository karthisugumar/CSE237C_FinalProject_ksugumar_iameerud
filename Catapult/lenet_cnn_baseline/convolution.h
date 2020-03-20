#ifndef __CONV__
#define __CONV__


// C1 - Convolution 1

void conv2d_C1 (DTYPE in[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS],
		const PARAM_TYPE filt[C1_NUM_OUTCHAN][C1_NUM_INCHAN][C1_KSIZE][C1_KSIZE],
		const PARAM_TYPE bias[C1_NUM_OUTCHAN],
		DTYPE out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS])
{

//accumulation buffer for each output channel
DTYPE acc_buf[C1_OUT_ROWS][C1_OUT_COLS];
DTYPE acc=0;
DTYPE data;

	OFM: for(int ofm=0; ofm<C1_NUM_OUTCHAN; ofm++){
		//Add Bias to accumulation buffer
		ROW_CLR: for(int r=0; r<C1_OUT_ROWS; r++){
			COL_CLR: for(int c=0; c<C1_OUT_COLS; c++){
//#pragma HLS PIPELINE
				acc_buf[r][c]=bias[ofm];
			}
		}

		IFM: for(int ifm=0; ifm<C1_NUM_INCHAN; ifm++){
			ROW: for(int r=0; r<C1_OUT_ROWS; r++){
				COL: for(int c=0; c<C1_OUT_COLS; c++){
//#pragma HLS PIPELINE
					acc=0;

					K_ROW: for(int kr=0; kr<C1_KSIZE; kr+=C_STRIDE){
						K_COL: for(int kc=0; kc<C1_KSIZE; kc+=C_STRIDE){
							int ridx = r + kr - C1_KSIZE/2;
							int cidx = c + kc - C1_KSIZE/2;
							if(ridx < 0 || ridx >= C1_OUT_ROWS || cidx < 0 || cidx >= C1_OUT_COLS){//zero pad boundary when index out of bounds
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
		ROW_CPY:for(int r=0;r<C1_OUT_ROWS;r++){
          COL_CPY:for(int c=0;c<C1_OUT_COLS;c++){
//#pragma HLS PIPELINE
            out[ofm][r][c] = acc_buf[r][c];
           	}
		}

	} //OFM

}


// C2 - Convolution 2

void conv2d_C2 (DTYPE in[C1_NUM_OUTCHAN][C2_IN_ROWS][C2_IN_COLS],
		const PARAM_TYPE filt[C2_NUM_OUTCHAN][C1_NUM_OUTCHAN][C2_KSIZE][C2_KSIZE],
		const PARAM_TYPE bias[C2_NUM_OUTCHAN],
		DTYPE out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS])
{

//accumulation buffer for each output channel
DTYPE acc_buf[C2_OUT_ROWS][C2_OUT_COLS];
DTYPE acc=0;
DTYPE data;

	OFM: for(int ofm=0; ofm<C2_NUM_OUTCHAN; ofm++){
		//Clear accumulation buffer
		ROW_CLR: for(int r=0; r<C2_OUT_ROWS; r++){
			COL_CLR: for(int c=0; c<C2_OUT_COLS; c++){
//#pragma HLS PIPELINE
				acc_buf[r][c]=bias[ofm];
			}
		}

		IFM: for(int ifm=0; ifm<C1_NUM_OUTCHAN; ifm++){
			ROW: for(int r=0; r<C2_OUT_ROWS; r++){
				COL: for(int c=0; c<C2_OUT_COLS; c++){
//#pragma HLS PIPELINE
					acc=0;
					K_ROW: for(int k_r=0; k_r<C2_KSIZE; k_r+=C_STRIDE){
						K_COL: for(int k_c=0; k_c<C2_KSIZE; k_c+=C_STRIDE){
							acc += filt[ofm][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
						}
					}

					acc_buf[r][c]+= acc;
				}//COL
			} //ROW
		} //IFM

		//copy to output
		ROW_CPY:for(int r=0;r<C2_OUT_ROWS;r++){
          COL_CPY:for(int c=0;c<C2_OUT_COLS;c++){
//#pragma HLS PIPELINE
            out[ofm][r][c] = acc_buf[r][c];
           	}
		}
	} //OFM
}

#endif
