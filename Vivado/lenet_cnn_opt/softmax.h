#ifndef __SM__
#define __SM__

#include "expTable.h"

// SM - Softmax
void softmax_SM(DTYPE in[FC3_OUT_SIZE], DTYPE out[PREDS])
{
	DTYPE denom=0;
	int idx[PREDS];

	DEN: for(int p=0; p<PREDS; p++){
#pragma HLS PIPELINE
		idx[p] = (RES>>1) + (int)(in[p] * 10);
		denom+= expTable[idx[p]];
	}//DEN

	OUT: for(int p=0; p<PREDS; p++){
#pragma HLS PIPELINE
		out[p] = expTable[idx[p]]/denom;
	}//OUT
}


#endif
