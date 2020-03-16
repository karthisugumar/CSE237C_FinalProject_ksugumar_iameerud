void mc_testbench_capture_IN( ac_fixed<32, 16, true, AC_TRN, AC_WRAP > image_in[1][28][28],  ac_fixed<32, 16, true, AC_TRN, AC_WRAP > out[10]) { mc_testbench::capture_IN(image_in,out); }
void mc_testbench_capture_OUT( ac_fixed<32, 16, true, AC_TRN, AC_WRAP > image_in[1][28][28],  ac_fixed<32, 16, true, AC_TRN, AC_WRAP > out[10]) { mc_testbench::capture_OUT(image_in,out); }
void mc_testbench_wait_for_idle_sync() {mc_testbench::wait_for_idle_sync(); }

