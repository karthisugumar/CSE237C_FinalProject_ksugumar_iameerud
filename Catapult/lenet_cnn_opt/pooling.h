#ifndef __POOL__
#define __POOL__


// P1 - Maxpool 1

//#pragma hls_design
void maxpool_P1(DTYPE in[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS],
		DTYPE out[C1_NUM_OUTCHAN][C2_IN_ROWS][C2_IN_COLS])
{
	DTYPE max=0,data,temp;

	P1_OFM: for(int ofm=0; ofm<C1_NUM_OUTCHAN; ofm++){
		P1_ROW: for(int r=0; r<C1_OUT_ROWS; r+=P_STRIDE){
			P1_COL: for(int c=0; c<C1_OUT_COLS; c+=P_STRIDE){
//#pragma HLS PIPELINE

				K_ROW: for(int k_r=0; k_r<P_KSIZE; k_r++){
					K_COL: for(int k_c=0; k_c<P_KSIZE; k_c++){
						temp = in[ofm][r + k_r][c + k_c];
						if(temp>max){
							max = temp;
						}
					}//K_COL
				}//K_ROW
				out[ofm][r/P_STRIDE][c/P_STRIDE] = max;
				max=0;
			}//COL
		}//ROW
	}//OFM
}

// P2 - Maxpool 2

//#pragma hls_design
void maxpool_P2(DTYPE in[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS],
		DTYPE out[C2_NUM_OUTCHAN][P2_OUT_ROWS][P2_OUT_COLS])
{
	DTYPE max=0,data,temp;

	P2_OFM: for(int ofm=0; ofm<C2_NUM_OUTCHAN; ofm++){
		P2_ROW: for(int r=0; r<C2_OUT_ROWS; r+=P_STRIDE){
			P2_COL: for(int c=0; c<C2_OUT_COLS; c+=P_STRIDE){
//#pragma HLS PIPELINE

				K_ROW: for(int k_r=0; k_r<P_KSIZE; k_r++){
					K_COL: for(int k_c=0; k_c<P_KSIZE; k_c++){
						temp = in[ofm][r + k_r][c + k_c];
						if(temp>max){
							max = temp;
						}
					}//K_COL
				}//K_ROW
				out[ofm][r/P_STRIDE][c/P_STRIDE] = max;
				max=0;
			}//COL
		}//ROW
	}//OFM
}

#endif
