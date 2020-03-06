#ifndef __TYPES__
#define __TYPES__

#include <ap_fixed.h>

typedef float DTYPE;

const int NUM_INCHAN=16;
const int IN_ROWS=5 ;
const int IN_COLS=5 ;

const int OUT_SIZE=400 ;

void flatten(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS]
			, DTYPE out[OUT_SIZE]);
#endif
