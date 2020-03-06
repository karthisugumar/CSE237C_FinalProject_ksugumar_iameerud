#ifndef __TYPES__
#define __TYPES__

#include <ap_fixed.h>

typedef float DTYPE;

const int PREDS=10;

void softmax(DTYPE in[PREDS], DTYPE out[PREDS]);

#endif
