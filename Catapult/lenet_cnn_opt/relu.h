#ifndef _RELU_
#define _RELU_


// R1 - relu 1
//// Same as C1 out

//#pragma hls_design
void relu_R1(DTYPE in[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS],
		DTYPE out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS])

{

	DTYPE data;

	R1_OFM: for(int ofm=0; ofm<C1_NUM_OUTCHAN; ofm++){
		R1_ROW: for(int r=0; r<C1_OUT_ROWS; r++){
//#pragma HLS PIPELINE
			R1_COL: for(int c=0; c<C1_OUT_COLS; c++){
//#pragma HLS PIPELINE
				data = in[ofm][r][c];
				out[ofm][r][c] = (data>0) ? data : (DTYPE)(0);
			}//COL
		}//ROW
	}//OFM
}

// R2 - relu 2
//// Same as C2

//#pragma hls_design
void relu_R2(DTYPE in[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS],
		DTYPE out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS])
{

	DTYPE data;

	R2_OFM: for(int ofm=0; ofm<C2_NUM_OUTCHAN; ofm++){
		R2_ROW: for(int r=0; r<C2_OUT_ROWS; r++){
//#pragma HLS PIPELINE
			R2_COL: for(int c=0; c<C2_OUT_COLS; c++){
//#pragma HLS PIPELINE
				data = in[ofm][r][c];
				out[ofm][r][c] = (data>0) ? data : (DTYPE)(0);
			}//COL
		}//ROW
	}//OFM
}


// R3 - relu 3
//// Same as FC1

//#pragma hls_design
void relu_R3(DTYPE in[FC1_OUT_SIZE],
		DTYPE out[FC1_OUT_SIZE])
{
	DTYPE data;
	R3_OUT: for(int c=0; c<FC1_OUT_SIZE; c++){
//#pragma HLS PIPELINE
		data = in[c];
		out[c] = (data>0) ? data : (DTYPE)(0);
	}//COL
}

// R4 - relu 4
//// Same as FC2

//#pragma hls_design
void relu_R4(DTYPE in[FC2_OUT_SIZE],
		DTYPE out[FC2_OUT_SIZE])
{
	DTYPE data;
	R4_OUT: for(int c=0; c<FC2_OUT_SIZE; c++){
//#pragma HLS PIPELINE
		data = in[c];
		out[c] = (data>0) ? data : (DTYPE)(0);
	}//COL
}

#endif
