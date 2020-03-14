#ifndef __TYPES__
#define __TYPES__

#include <ap_fixed.h>
typedef float DTYPE;

const int STRIDE = 1;
const int KSIZE=3;
const int NUM_INCHAN=1;
const int NUM_OUTCHAN=6;
const int IN_ROWS = 28;
const int IN_COLS = 28;

const int OUT_ROWS = 28;
const int OUT_COLS = 28;

void conv2d(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
		const DTYPE filt[NUM_OUTCHAN][NUM_INCHAN][KSIZE][KSIZE],
		const DTYPE bias[NUM_OUTCHAN],
		DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS]);

#endif
