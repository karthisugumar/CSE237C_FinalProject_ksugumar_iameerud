#ifndef __TYPES__
#define __TYPES__

#include <ap_fixed.h>

typedef float DTYPE;

const int IN_SIZE = 400;
const int OUT_SIZE = 120;


void fc(DTYPE in[IN_SIZE], DTYPE kernel[OUT_SIZE][IN_SIZE],
		DTYPE bias[OUT_SIZE], DTYPE out[OUT_SIZE]);

#endif
