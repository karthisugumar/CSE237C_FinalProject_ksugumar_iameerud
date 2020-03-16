// ccs_block_macros.h
#include "ccs_testbench.h"

#ifndef EXCLUDE_CCS_BLOCK_INTERCEPT
#ifndef INCLUDE_CCS_BLOCK_INTERCEPT
#define INCLUDE_CCS_BLOCK_INTERCEPT
#ifdef  CCS_DESIGN_FUNC_lenet
extern void mc_testbench_capture_IN( ac_fixed<32, 16, true, AC_TRN, AC_WRAP > image_in[1][28][28],  ac_fixed<32, 16, true, AC_TRN, AC_WRAP > out[10]);
extern void mc_testbench_capture_OUT( ac_fixed<32, 16, true, AC_TRN, AC_WRAP > image_in[1][28][28],  ac_fixed<32, 16, true, AC_TRN, AC_WRAP > out[10]);
extern void mc_testbench_wait_for_idle_sync();

#define ccs_intercept_lenet_17 \
  ccs_real_lenet(ac_fixed<32, 16, true, AC_TRN, AC_WRAP > image_in[1][28][28],ac_fixed<32, 16, true, AC_TRN, AC_WRAP > out[10]);\
  void lenet(ac_fixed<32, 16, true, AC_TRN, AC_WRAP > image_in[1][28][28],ac_fixed<32, 16, true, AC_TRN, AC_WRAP > out[10])\
{\
    static bool ccs_intercept_flag = false;\
    if (!ccs_intercept_flag) {\
      std::cout << "SCVerify intercepting C++ function 'lenet' for RTL block 'lenet'" << std::endl;\
      ccs_intercept_flag=true;\
    }\
    mc_testbench_capture_IN(image_in,out);\
    ccs_real_lenet(image_in,out);\
    mc_testbench_capture_OUT(image_in,out);\
}\
  void ccs_real_lenet
#else
#define ccs_intercept_lenet_17 lenet
#endif //CCS_DESIGN_FUNC_lenet
#endif //INCLUDE_CCS_BLOCK_INTERCEPT
#endif //EXCLUDE_CCS_BLOCK_INTERCEPT

// conv2d_C1 10 INLINE
#define ccs_intercept_conv2d_C1_10 conv2d_C1
// conv2d_C2 83 INLINE
#define ccs_intercept_conv2d_C2_83 conv2d_C2
// maxpool_P1 6 INLINE
#define ccs_intercept_maxpool_P1_6 maxpool_P1
// maxpool_P1 32 INLINE
#define ccs_intercept_maxpool_P1_32 maxpool_P1
// relu_R1 7 INLINE
#define ccs_intercept_relu_R1_7 relu_R1
// relu_R2 28 INLINE
#define ccs_intercept_relu_R2_28 relu_R2
// relu_R3 49 INLINE
#define ccs_intercept_relu_R3_49 relu_R3
// relu_R4 62 INLINE
#define ccs_intercept_relu_R4_62 relu_R4
// flatten_F 6 INLINE
#define ccs_intercept_flatten_F_6 flatten_F
// fc_FC1 28 INLINE
#define ccs_intercept_fc_FC1_28 fc_FC1
// fc_FC2 67 INLINE
#define ccs_intercept_fc_FC2_67 fc_FC2
// fc_FC3 95 INLINE
#define ccs_intercept_fc_FC3_95 fc_FC3
// softmax_SM 8 INLINE
#define ccs_intercept_softmax_SM_8 softmax_SM
// add_value 21 INLINE
#define ccs_intercept_add_value_21 add_value
