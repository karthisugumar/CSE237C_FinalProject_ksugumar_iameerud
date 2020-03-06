#include<iostream>
#include "types.h"
#include "expTable.h"
#include"math.h"

void softmax(DTYPE in[PREDS], DTYPE out[PREDS])
{

	DTYPE denom=0;
	int idx[PREDS];

	DEN: for(int p=0; p<PREDS; p++){
		idx[p] = (RES>>1) + (int)(in[p] * 10);
		denom+= expTable[idx[p]];
	}//DEN

	OUT: for(int p=0; p<PREDS; p++){
		out[p] = expTable[idx[p]]/denom;
	}//OUT
}
