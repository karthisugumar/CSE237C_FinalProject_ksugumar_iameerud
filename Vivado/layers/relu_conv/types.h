#ifndef __TYPES__
#define __TYPES__

#include <ap_fixed.h>
//#include <ap_sync.h>
//#include <ap_channel.h>
// typedef ap_fixed<16,8> WTYPE;
// typedef ap_fixed<16,8> DTYPE; //Image pixel can take a value of 0-255
// typedef ap_fixed<16,7> SAT_TYPE;//,true,AC_RND,AC_SAT> SAT_TYPE;
const int FHEIGHT=14;
const int FWIDTH=14;
//const int NUM_INCHAN=32;
//const int NUM_OUTCHAN=64;
//const int KHEIGHT=3;
//const int KWIDTH=3;

typedef float DTYPE;

const int NUM_INCHAN=6;
const int NUM_OUTCHAN=6;
const int IN_ROWS = 28;
const int IN_COLS = 28;

const int OUT_ROWS = 28;
const int OUT_COLS = 28;


//const int OUT_ROWS = 1 + (IN_ROWS-KSIZE)/STRIDE;
//const int OUT_COLS = 1 + (IN_COLS-KSIZE)/STRIDE;


void relu(DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS],
		DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS]);

#endif
