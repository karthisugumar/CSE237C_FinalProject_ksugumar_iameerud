#ifndef __TYPES__
#define __TYPES__

typedef float DTYPE;

const int IN_SIZE = 120;
const int OUT_SIZE = 120;


//const int OUT_ROWS = 1 + (IN_ROWS-KSIZE)/STRIDE;
//const int OUT_COLS = 1 + (IN_COLS-KSIZE)/STRIDE;


void relu(DTYPE in[IN_SIZE], DTYPE out[OUT_SIZE]);
#endif
