#ifndef __CONV__
#define __CONV__


// C1 - Convolution 1
PARAM_TYPE filt_c1[C1_NUM_OUTCHAN][C1_NUM_INCHAN][C1_KSIZE][C1_KSIZE];
PARAM_TYPE bias_c1[C1_NUM_OUTCHAN];
DTYPE out_c1[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS];

void conv2d_C1 (DTYPE in[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS],
		const PARAM_TYPE filt_c1[C1_NUM_OUTCHAN][C1_NUM_INCHAN][C1_KSIZE][C1_KSIZE],
		const PARAM_TYPE bias_c1[C1_NUM_OUTCHAN],
		DTYPE out_c1[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS])
{
//#pragma HLS ARRAY_PARTITION variable=filt_c1 cyclic factor=2 dim=1
//#pragma HLS ARRAY_PARTITION variable=bias_c1 cyclic factor=2 dim=1
//#pragma HLS ARRAY_PARTITION variable=out_c1 cyclic factor=2 dim=1

//accumulation buffer for each out_c1put channel
DTYPE acc_buf_0[C1_OUT_ROWS][C1_OUT_COLS];
DTYPE acc_buf_1[C1_OUT_ROWS][C1_OUT_COLS];

DTYPE acc_0=0;
DTYPE acc_1=0;

DTYPE data;

	C1_OFM: for(int ofm=0; ofm<C1_NUM_OUTCHAN; ofm+=2){
		//Add Bias to accumulation buffer
		C1_ROW_CLR: for(int r=0; r<C1_OUT_ROWS; r++){
		      C1_COL_CLR: for(int c=0; c<C1_OUT_COLS; c++){
//#pragma HLS PIPELINE
				acc_buf_0[r][c]=bias_c1[ofm];
				acc_buf_1[r][c]=bias_c1[ofm+1];
			}
		}

		C1_IFM: for(int ifm=0; ifm<C1_NUM_INCHAN; ifm++){
			C1_ROW: for(int r=0; r<C1_OUT_ROWS; r++){
				C1_COL: for(int c=0; c<C1_OUT_COLS; c++){
//#pragma HLS PIPELINE
					acc_0=0;
					acc_1=0;

					K_ROW: for(int kr=0; kr<C1_KSIZE; kr+=C_STRIDE){
						K_COL: for(int kc=0; kc<C1_KSIZE; kc+=C_STRIDE){
							int ridx = r + kr - C1_KSIZE/2;
							int cidx = c + kc - C1_KSIZE/2;
							if(ridx < 0 || ridx >= C1_OUT_ROWS || cidx < 0 || cidx >= C1_OUT_COLS){//zero pad boundary when index out_c1 of bounds
                    			data = 0;
                    		}else{
                    			data=in[ifm][ridx][cidx];
                    		}
							acc_0 += filt_c1[ofm][ifm][kr][kc]*data;
							acc_1 += filt_c1[ofm+1][ifm][kr][kc]*data;
						}
					}

					acc_buf_0[r][c]+= acc_0;
					acc_buf_1[r][c]+= acc_1;
				}//COL
			} //ROW
		} //IFM

		//copy to out_c1put
		C1_ROW_CPY:for(int r=0;r<C1_OUT_ROWS;r++){
          C1_COL_CPY:for(int c=0;c<C1_OUT_COLS;c++){
//#pragma HLS PIPELINE
            out_c1[ofm][r][c] = acc_buf_0[r][c];
            out_c1[ofm+1][r][c] = acc_buf_1[r][c];
           	}
		}

	} //OFM
}



PARAM_TYPE filt_c2[C2_NUM_OUTCHAN][C1_NUM_OUTCHAN][C2_KSIZE][C2_KSIZE];
PARAM_TYPE bias_c2[C2_NUM_OUTCHAN];
DTYPE out_c2[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS];

void conv2d_C2 (DTYPE in[C1_NUM_OUTCHAN][C2_IN_ROWS][C2_IN_COLS],
		const PARAM_TYPE filt_c2[C2_NUM_OUTCHAN][C1_NUM_OUTCHAN][C2_KSIZE][C2_KSIZE],
		const PARAM_TYPE bias_c2[C2_NUM_OUTCHAN],
		DTYPE out_c2[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS])
{
//#pragma HLS ARRAY_PARTITION variable=filt_c2 cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=bias_c2 cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=out_c2 cyclic factor=4 dim=1

//accumulation buffer for each out_c2put channel
DTYPE acc_buf_0[C2_OUT_ROWS][C2_OUT_COLS];
DTYPE acc_buf_1[C2_OUT_ROWS][C2_OUT_COLS];
DTYPE acc_buf_2[C2_OUT_ROWS][C2_OUT_COLS];
DTYPE acc_buf_3[C2_OUT_ROWS][C2_OUT_COLS];

DTYPE acc_0=0;
DTYPE acc_1=0;
DTYPE acc_2=0;
DTYPE acc_3=0;

DTYPE data;

	C2_OFM: for(int ofm=0; ofm<C2_NUM_OUTCHAN; ofm+=4){
		//Clear accumulation buffer
		C2_ROW_CLR: for(int r=0; r<C2_OUT_ROWS; r++){
			C2_COL_CLR: for(int c=0; c<C2_OUT_COLS; c++){
//#pragma HLS PIPELINE
				acc_buf_0[r][c]=bias_c2[ofm];
				acc_buf_1[r][c]=bias_c2[ofm+1];
				acc_buf_2[r][c]=bias_c2[ofm+2];
				acc_buf_3[r][c]=bias_c2[ofm+3];
			}
		}

		C2_IFM: for(int ifm=0; ifm<C1_NUM_OUTCHAN; ifm++){
			C2_ROW: for(int r=0; r<C2_OUT_ROWS; r++){
				C2_COL: for(int c=0; c<C2_OUT_COLS; c++){
//#pragma HLS PIPELINE
					DTYPE acc_0=0;
					DTYPE acc_1=0;
					DTYPE acc_2=0;
					DTYPE acc_3=0;

					K_ROW: for(int k_r=0; k_r<C2_KSIZE; k_r+=C_STRIDE){
						K_COL: for(int k_c=0; k_c<C2_KSIZE; k_c+=C_STRIDE){
//#pragma HLS PIPELINE
							acc_0 += filt_c2[ofm][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
							acc_1 += filt_c2[ofm+1][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
							acc_2 += filt_c2[ofm+2][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
							acc_3 += filt_c2[ofm+3][ifm][k_r][k_c]*in[ifm][r + k_r][c + k_c];
						}
					}

					acc_buf_0[r][c]+= acc_0;
					acc_buf_1[r][c]+= acc_1;
					acc_buf_2[r][c]+= acc_2;
					acc_buf_3[r][c]+= acc_3;

				}//COL
			} //ROW
		} //IFM

		//copy to out_c2put
		C2_ROW_CPY:for(int r=0;r<C2_OUT_ROWS;r++){
          C2_COL_CPY:for(int c=0;c<C2_OUT_COLS;c++){
//#pragma HLS PIPELINE
            out_c2[ofm][r][c] = acc_buf_0[r][c];
            out_c2[ofm+1][r][c] = acc_buf_1[r][c];
            out_c2[ofm+2][r][c] = acc_buf_2[r][c];
            out_c2[ofm+3][r][c] = acc_buf_3[r][c];
           	}
		}

	} //OFM
}


#endif
