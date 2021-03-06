#ifndef _RELU_
#define _RELU_


// R1 - relu 1
//// Same as C1 out
void relu_R1(DTYPE in[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS],
		DTYPE out[C1_NUM_OUTCHAN][C1_OUT_ROWS][C1_OUT_COLS])

{

	DTYPE data;

	OFM: for(int ofm=0; ofm<C1_NUM_OUTCHAN; ofm++){
		ROW: for(int r=0; r<C1_OUT_ROWS; r++){
			COL: for(int c=0; c<C1_OUT_COLS; c++){
				data = in[ofm][r][c];
				out[ofm][r][c] = (data>0) ? data : (DTYPE)(0);
			}//COL
		}//ROW
	}//OFM
}

// R2 - relu 2
//// Same as C2
void relu_R2(DTYPE in[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS],
		DTYPE out[C2_NUM_OUTCHAN][C2_OUT_ROWS][C2_OUT_COLS])
{

	DTYPE data;

	OFM: for(int ofm=0; ofm<C2_NUM_OUTCHAN; ofm++){
		ROW: for(int r=0; r<C2_OUT_ROWS; r++){
			COL: for(int c=0; c<C2_OUT_COLS; c++){
				data = in[ofm][r][c];
				out[ofm][r][c] = (data>0) ? data : (DTYPE)(0);
			}//COL
		}//ROW
	}//OFM
}


// R3 - relu 3
//// Same as FC1
void relu_R3(DTYPE in[FC1_OUT_SIZE],
		DTYPE out[FC1_OUT_SIZE])
{
	DTYPE data;
	OUT: for(int c=0; c<FC1_OUT_SIZE; c++){
		data = in[c];
		out[c] = (data>0) ? data : (DTYPE)(0);
	}//COL
}

// R4 - relu 4
//// Same as FC2
void relu_R4(DTYPE in[FC2_OUT_SIZE],
		DTYPE out[FC2_OUT_SIZE])
{
	DTYPE data;
	OUT: for(int c=0; c<FC2_OUT_SIZE; c++){
		data = in[c];
		out[c] = (data>0) ? data : (DTYPE)(0);
	}//COL
}

#endif
