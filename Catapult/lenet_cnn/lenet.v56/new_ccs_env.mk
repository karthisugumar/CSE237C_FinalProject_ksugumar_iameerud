ifeq "$(CXX_HOME)" ""
CXX_HOME                                         := /mnt/d/Ubuntu/Mgc_home
export CXX_HOME
endif
ifeq "$(CXX_TYPE)" ""
CXX_TYPE                                         := gcc
export CXX_TYPE
endif
ifeq "$(CXX_VCO)" ""
CXX_VCO                                          := aol
export CXX_VCO
endif
ifeq "$(Option_CppStandard)" ""
Option_CppStandard                               := c++11
export Option_CppStandard
endif
ifeq "$(SYN_DIR)" ""
SYN_DIR                                          := gate_synthesis_or
export SYN_DIR
endif
ifeq "$(HLD_CONSTRAINT_FNAME)" ""
HLD_CONSTRAINT_FNAME                             := top_gate_constraints.cpp
export HLD_CONSTRAINT_FNAME
endif
ifeq "$(TCLSH_CMD)" ""
TCLSH_CMD                                        := /mnt/d/Ubuntu/Mgc_home/bin/tclsh8.5
export TCLSH_CMD
endif
ifeq "$(QuestaSIM_Path)" ""
QuestaSIM_Path                                   := /mnt/d/Ubuntu/Questa/questasim/bin
export QuestaSIM_Path
endif
ifeq "$(QuestaSIM_FORCE_32BIT)" ""
QuestaSIM_FORCE_32BIT                            := 
export QuestaSIM_FORCE_32BIT
endif
ifeq "$(QuestaSIM_DEF_MODELSIM_INI)" ""
QuestaSIM_DEF_MODELSIM_INI                       := 
export QuestaSIM_DEF_MODELSIM_INI
endif
ifeq "$(QuestaSIM_ENABLE_VOPT)" ""
QuestaSIM_ENABLE_VOPT                            := true
export QuestaSIM_ENABLE_VOPT
endif
ifeq "$(QuestaSIM_VCOM_OPTS)" ""
QuestaSIM_VCOM_OPTS                              := 
export QuestaSIM_VCOM_OPTS
endif
ifeq "$(QuestaSIM_VLOG_OPTS)" ""
QuestaSIM_VLOG_OPTS                              := 
export QuestaSIM_VLOG_OPTS
endif
ifeq "$(QuestaSIM_SCCOM_OPTS)" ""
QuestaSIM_SCCOM_OPTS                             := -g -x c++ -Wall -Wno-unused-label -Wno-unknown-pragmas
export QuestaSIM_SCCOM_OPTS
endif
ifeq "$(QuestaSIM_VOPT_ARGS)" ""
QuestaSIM_VOPT_ARGS                              := +acc=npr
export QuestaSIM_VOPT_ARGS
endif
ifeq "$(QuestaSIM_VSIM_OPTS)" ""
QuestaSIM_VSIM_OPTS                              := -t ps
export QuestaSIM_VSIM_OPTS
endif
ifeq "$(QuestaSIM_GATE_VSIM_OPTS)" ""
QuestaSIM_GATE_VSIM_OPTS                         := +notimingchecks -sdfnoerror -noglitch
export QuestaSIM_GATE_VSIM_OPTS
endif
ifeq "$(QuestaSIM_RADIX)" ""
QuestaSIM_RADIX                                  := hex
export QuestaSIM_RADIX
endif
ifeq "$(QuestaSIM_MSIM_AC_TYPES)" ""
QuestaSIM_MSIM_AC_TYPES                          := true
export QuestaSIM_MSIM_AC_TYPES
endif
ifeq "$(QuestaSIM_MSIM_DOFILE)" ""
QuestaSIM_MSIM_DOFILE                            := 
export QuestaSIM_MSIM_DOFILE
endif
ifeq "$(QuestaSIM_VCD_SIZE_LIMIT)" ""
QuestaSIM_VCD_SIZE_LIMIT                         := 2000
export QuestaSIM_VCD_SIZE_LIMIT
endif
ifeq "$(QuestaSIM_ENABLE_CODE_COVERAGE)" ""
QuestaSIM_ENABLE_CODE_COVERAGE                   := false
export QuestaSIM_ENABLE_CODE_COVERAGE
endif
ifeq "$(QuestaSIM_QHOME)" ""
QuestaSIM_QHOME                                  := $(QHOME)
export QuestaSIM_QHOME
endif
ifeq "$(QuestaSIM_WITNESS_WAVEFORM)" ""
QuestaSIM_WITNESS_WAVEFORM                       := false
export QuestaSIM_WITNESS_WAVEFORM
endif
ifeq "$(QuestaSIM_COVERCHECK_TIMEOUT)" ""
QuestaSIM_COVERCHECK_TIMEOUT                     := 2m
export QuestaSIM_COVERCHECK_TIMEOUT
endif
ifeq "$(QuestaSIM_COVERCHECK_TCL)" ""
QuestaSIM_COVERCHECK_TCL                         := 
export QuestaSIM_COVERCHECK_TCL
endif
ifeq "$(QuestaSIM_SYSC_VERSION)" ""
QuestaSIM_SYSC_VERSION                           := 2.3
export QuestaSIM_SYSC_VERSION
endif
ifeq "$(QuestaSIM_SUPPRESS_WAVEFORMS)" ""
QuestaSIM_SUPPRESS_WAVEFORMS                     := false
export QuestaSIM_SUPPRESS_WAVEFORMS
endif
ifeq "$(QuestaSIM_QUESTA_VISUALIZER)" ""
QuestaSIM_QUESTA_VISUALIZER                      := $(VISUALIZER_HOME)
export QuestaSIM_QUESTA_VISUALIZER
endif
ifeq "$(QuestaSIM_ENABLE_QWAVE)" ""
QuestaSIM_ENABLE_QWAVE                           := false
export QuestaSIM_ENABLE_QWAVE
endif
ifeq "$(QuestaSIM_ALLOW_DUP_SYMS)" ""
QuestaSIM_ALLOW_DUP_SYMS                         := false
export QuestaSIM_ALLOW_DUP_SYMS
endif
ifeq "$(QuestaSIM_EXEC_VCOM)" ""
QuestaSIM_EXEC_VCOM                              := 
export QuestaSIM_EXEC_VCOM
endif
ifeq "$(QuestaSIM_EXEC_VLOG)" ""
QuestaSIM_EXEC_VLOG                              := 
export QuestaSIM_EXEC_VLOG
endif
ifeq "$(QuestaSIM_EXEC_SCCOM)" ""
QuestaSIM_EXEC_SCCOM                             := 
export QuestaSIM_EXEC_SCCOM
endif
ifeq "$(QuestaSIM_EXEC_VOPT)" ""
QuestaSIM_EXEC_VOPT                              := 
export QuestaSIM_EXEC_VOPT
endif
ifeq "$(QuestaSIM_EXEC_VSIM)" ""
QuestaSIM_EXEC_VSIM                              := 
export QuestaSIM_EXEC_VSIM
endif
ifeq "$(QuestaSIM_SHOW_LIST)" ""
QuestaSIM_SHOW_LIST                              := false
export QuestaSIM_SHOW_LIST
endif
ifeq "$(QuestaSIM_ENABLE_OLD_MSIM_FLOW)" ""
QuestaSIM_ENABLE_OLD_MSIM_FLOW                   := false
export QuestaSIM_ENABLE_OLD_MSIM_FLOW
endif
ifeq "$(QuestaSIM_Flags)" ""
QuestaSIM_Flags                                  := 
export QuestaSIM_Flags
endif
ifeq "$(NCSim_NC_ROOT)" ""
NCSim_NC_ROOT                                    := $(NC_ROOT)
export NCSim_NC_ROOT
endif
ifeq "$(NCSim_FORCE_32BIT)" ""
NCSim_FORCE_32BIT                                := 
export NCSim_FORCE_32BIT
endif
ifeq "$(NCSim_GCC_HOME)" ""
NCSim_GCC_HOME                                   := 
export NCSim_GCC_HOME
endif
ifeq "$(NCSim_NCSIM_GCCVERSION)" ""
NCSim_NCSIM_GCCVERSION                           := 
export NCSim_NCSIM_GCCVERSION
endif
ifeq "$(NCSim_NCVHDL_OPTS)" ""
NCSim_NCVHDL_OPTS                                := -v93 -linedebug
export NCSim_NCVHDL_OPTS
endif
ifeq "$(NCSim_NCVLOG_OPTS)" ""
NCSim_NCVLOG_OPTS                                := -linedebug
export NCSim_NCVLOG_OPTS
endif
ifeq "$(NCSim_NCSC_OPTS)" ""
NCSim_NCSC_OPTS                                  := 
export NCSim_NCSC_OPTS
endif
ifeq "$(NCSim_NCSC_CXX_OPTS)" ""
NCSim_NCSC_CXX_OPTS                              := -x c++ -Wall -Wno-unknown-pragmas -Wno-deprecated
export NCSim_NCSC_CXX_OPTS
endif
ifeq "$(NCSim_NCELAB_OPTS)" ""
NCSim_NCELAB_OPTS                                := 
export NCSim_NCELAB_OPTS
endif
ifeq "$(NCSim_NCSIM_OPTS)" ""
NCSim_NCSIM_OPTS                                 := 
export NCSim_NCSIM_OPTS
endif
ifeq "$(NCSim_NCSIM_TIMESCALE)" ""
NCSim_NCSIM_TIMESCALE                            := 1 ns / 1 ps
export NCSim_NCSIM_TIMESCALE
endif
ifeq "$(NCSim_NCSIM_SAIF_OPTIONS)" ""
NCSim_NCSIM_SAIF_OPTIONS                         := -verbose -overwrite -internal -hierarchy
export NCSim_NCSIM_SAIF_OPTIONS
endif
ifeq "$(NCSim_NCSIM_DOFILE)" ""
NCSim_NCSIM_DOFILE                               := 
export NCSim_NCSIM_DOFILE
endif
ifeq "$(NCSim_EXEC_NCVHDL)" ""
NCSim_EXEC_NCVHDL                                := 
export NCSim_EXEC_NCVHDL
endif
ifeq "$(NCSim_EXEC_NCVLOG)" ""
NCSim_EXEC_NCVLOG                                := 
export NCSim_EXEC_NCVLOG
endif
ifeq "$(NCSim_EXEC_NCSDFC)" ""
NCSim_EXEC_NCSDFC                                := 
export NCSim_EXEC_NCSDFC
endif
ifeq "$(NCSim_EXEC_NCELAB)" ""
NCSim_EXEC_NCELAB                                := 
export NCSim_EXEC_NCELAB
endif
ifeq "$(NCSim_EXEC_NCSIM)" ""
NCSim_EXEC_NCSIM                                 := 
export NCSim_EXEC_NCSIM
endif
ifeq "$(OSCI_SYSTEMC_INCLUDE)" ""
OSCI_SYSTEMC_INCLUDE                             := /mnt/d/Ubuntu/Mgc_home/shared/include
export OSCI_SYSTEMC_INCLUDE
endif
ifeq "$(OSCI_SYSTEMC_LIB)" ""
OSCI_SYSTEMC_LIB                                 := /mnt/d/Ubuntu/Mgc_home/shared/lib/$(CXX_OS)/$(CXX_TYPE)
export OSCI_SYSTEMC_LIB
endif
ifeq "$(OSCI_SYSTEMC_NAME)" ""
OSCI_SYSTEMC_NAME                                := systemc
export OSCI_SYSTEMC_NAME
endif
ifeq "$(OSCI_COMP_FLAGS)" ""
OSCI_COMP_FLAGS                                  := -Wall -Wno-unknown-pragmas -Wno-unused-label
export OSCI_COMP_FLAGS
endif
ifeq "$(OSCI_USE_32BIT_COMPILER)" ""
OSCI_USE_32BIT_COMPILER                          := false
export OSCI_USE_32BIT_COMPILER
endif
ifeq "$(OSCI_GDBGUI)" ""
OSCI_GDBGUI                                      := ddd
export OSCI_GDBGUI
endif
ifeq "$(OSCI_GCOV)" ""
OSCI_GCOV                                        := false
export OSCI_GCOV
endif
ifeq "$(OSCI_LCOVDIR)" ""
OSCI_LCOVDIR                                     := $(LCOVDIR)
export OSCI_LCOVDIR
endif
ifeq "$(Novas_NOVAS_INST_DIR)" ""
Novas_NOVAS_INST_DIR                             := $(NOVAS_INST_DIR)
export Novas_NOVAS_INST_DIR
endif
ifeq "$(Novas_NOVAS_PLATFORM)" ""
Novas_NOVAS_PLATFORM                             := LINUX
export Novas_NOVAS_PLATFORM
endif
ifeq "$(Novas_NOVAS_MSIM_PLI)" ""
Novas_NOVAS_MSIM_PLI                             := modelsim_fli61
export Novas_NOVAS_MSIM_PLI
endif
ifeq "$(Novas_NOVAS_NCSIM_VER)" ""
Novas_NOVAS_NCSIM_VER                            := nc57_vhdl
export Novas_NOVAS_NCSIM_VER
endif
ifeq "$(Novas_NOVAS_NCSIM_PLI)" ""
Novas_NOVAS_NCSIM_PLI                            := ncsc57/lib-linux_gcc3_23
export Novas_NOVAS_NCSIM_PLI
endif
ifeq "$(Novas_NOVAS_NCSIM_LDV)" ""
Novas_NOVAS_NCSIM_LDV                            := ius_vhpi_latest
export Novas_NOVAS_NCSIM_LDV
endif
ifeq "$(Novas_NOVAS_NCSIM_FSDBW)" ""
Novas_NOVAS_NCSIM_FSDBW                          := LINUX_GNU_296
export Novas_NOVAS_NCSIM_FSDBW
endif
ifeq "$(Novas_VERDI_VERSION)" ""
Novas_VERDI_VERSION                              := N-2017.12
export Novas_VERDI_VERSION
endif
ifeq "$(Valgrind_VALGRIND)" ""
Valgrind_VALGRIND                                := /usr/opt/bin/valgrind
export Valgrind_VALGRIND
endif
ifeq "$(Valgrind_VALGRIND_OPTS)" ""
Valgrind_VALGRIND_OPTS                           := --demangle=yes --leak-check=no --undef-value-errors=yes
export Valgrind_VALGRIND_OPTS
endif
ifeq "$(VCS_VCS_HOME)" ""
VCS_VCS_HOME                                     := $(VCS_HOME)
export VCS_VCS_HOME
endif
ifeq "$(VCS_FORCE_32BIT)" ""
VCS_FORCE_32BIT                                  := 
export VCS_FORCE_32BIT
endif
ifeq "$(VCS_VG_GNU_PACKAGE)" ""
VCS_VG_GNU_PACKAGE                               := $(VG_GNU_PACKAGE)
export VCS_VG_GNU_PACKAGE
endif
ifeq "$(VCS_VG_ENV32_SCRIPT)" ""
VCS_VG_ENV32_SCRIPT                              := source_me_32.csh
export VCS_VG_ENV32_SCRIPT
endif
ifeq "$(VCS_VG_ENV64_SCRIPT)" ""
VCS_VG_ENV64_SCRIPT                              := source_me_64.csh
export VCS_VG_ENV64_SCRIPT
endif
ifeq "$(VCS_COMP_FLAGS)" ""
VCS_COMP_FLAGS                                   := -g -Wall -Wno-unknown-pragmas
export VCS_COMP_FLAGS
endif
ifeq "$(VCS_VHDLAN_OPTS)" ""
VCS_VHDLAN_OPTS                                  := 
export VCS_VHDLAN_OPTS
endif
ifeq "$(VCS_VLOGAN_OPTS)" ""
VCS_VLOGAN_OPTS                                  := +v2k
export VCS_VLOGAN_OPTS
endif
ifeq "$(VCS_VCSELAB_OPTS)" ""
VCS_VCSELAB_OPTS                                 := -debug_all -timescale=1ps/1ps -sysc=blocksync
export VCS_VCSELAB_OPTS
endif
ifeq "$(VCS_VCSSIM_OPTS)" ""
VCS_VCSSIM_OPTS                                  := 
export VCS_VCSSIM_OPTS
endif
ifeq "$(VCS_VCS_GCC_VER)" ""
VCS_VCS_GCC_VER                                  := 4.2.2
export VCS_VCS_GCC_VER
endif
ifeq "$(VCS_VCS_DOFILE)" ""
VCS_VCS_DOFILE                                   := 
export VCS_VCS_DOFILE
endif
ifeq "$(VCS_SYSC_VERSION)" ""
VCS_SYSC_VERSION                                 := 2.3.1
export VCS_SYSC_VERSION
endif
ifeq "$(VCS_LIC_QUEUE)" ""
VCS_LIC_QUEUE                                    := false
export VCS_LIC_QUEUE
endif
ifeq "$(VCS_EXEC_VLOGAN)" ""
VCS_EXEC_VLOGAN                                  := 
export VCS_EXEC_VLOGAN
endif
ifeq "$(VCS_EXEC_VHDLAN)" ""
VCS_EXEC_VHDLAN                                  := 
export VCS_EXEC_VHDLAN
endif
ifeq "$(VCS_EXEC_SYSCAN)" ""
VCS_EXEC_SYSCAN                                  := 
export VCS_EXEC_SYSCAN
endif
ifeq "$(VCS_EXEC_VCS)" ""
VCS_EXEC_VCS                                     := 
export VCS_EXEC_VCS
endif
ifeq "$(VCS_ENABLE_CODE_COVERAGE)" ""
VCS_ENABLE_CODE_COVERAGE                         := false
export VCS_ENABLE_CODE_COVERAGE
endif
ifeq "$(DesignAnalyzer_Exe)" ""
DesignAnalyzer_Exe                               := $(CATAPULT_DESIGN_ANALYZER)
export DesignAnalyzer_Exe
endif
ifeq "$(DesignAnalyzer_lddDebug)" ""
DesignAnalyzer_lddDebug                          := false
export DesignAnalyzer_lddDebug
endif
ifeq "$(SCVerify_RESET_CYCLES)" ""
SCVerify_RESET_CYCLES                            := 2
export SCVerify_RESET_CYCLES
endif
ifeq "$(SCVerify_SYNC_ALL_RESETS)" ""
SCVerify_SYNC_ALL_RESETS                         := true
export SCVerify_SYNC_ALL_RESETS
endif
ifeq "$(SCVerify_TB_STACKSIZE)" ""
SCVerify_TB_STACKSIZE                            := 64000000
export SCVerify_TB_STACKSIZE
endif
ifeq "$(SCVerify_INVOKE_ARGS)" ""
SCVerify_INVOKE_ARGS                             := 
export SCVerify_INVOKE_ARGS
endif
ifeq "$(SCVerify_REPLAY_ARGS)" ""
SCVerify_REPLAY_ARGS                             := 
export SCVerify_REPLAY_ARGS
endif
ifeq "$(SCVerify_QUESTASIM_DEBUG)" ""
SCVerify_QUESTASIM_DEBUG                         := false
export SCVerify_QUESTASIM_DEBUG
endif
ifeq "$(SCVerify_MAX_ERROR_CNT)" ""
SCVerify_MAX_ERROR_CNT                           := 0
export SCVerify_MAX_ERROR_CNT
endif
ifeq "$(SCVerify_DEADLOCK_DETECTION)" ""
SCVerify_DEADLOCK_DETECTION                      := true
export SCVerify_DEADLOCK_DETECTION
endif
ifeq "$(SCVerify_MAX_SIM_TIME)" ""
SCVerify_MAX_SIM_TIME                            := 0
export SCVerify_MAX_SIM_TIME
endif
ifeq "$(SCVerify_MAX_DEADLOCK_TIMER)" ""
SCVerify_MAX_DEADLOCK_TIMER                      := 0
export SCVerify_MAX_DEADLOCK_TIMER
endif
ifeq "$(SCVerify_INCL_DIRS)" ""
SCVerify_INCL_DIRS                               := 
export SCVerify_INCL_DIRS
endif
ifeq "$(SCVerify_LINK_LIBPATHS)" ""
SCVerify_LINK_LIBPATHS                           := 
export SCVerify_LINK_LIBPATHS
endif
ifeq "$(SCVerify_LINK_LIBNAMES)" ""
SCVerify_LINK_LIBNAMES                           := 
export SCVerify_LINK_LIBNAMES
endif
ifeq "$(SCVerify_USE_QUESTASIM)" ""
SCVerify_USE_QUESTASIM                           := true
export SCVerify_USE_QUESTASIM
endif
ifeq "$(SCVerify_USE_OSCI)" ""
SCVerify_USE_OSCI                                := true
export SCVerify_USE_OSCI
endif
ifeq "$(SCVerify_USE_NCSIM)" ""
SCVerify_USE_NCSIM                               := false
export SCVerify_USE_NCSIM
endif
ifeq "$(SCVerify_USE_VCS)" ""
SCVerify_USE_VCS                                 := false
export SCVerify_USE_VCS
endif
ifeq "$(SCVerify_DISABLE_EMPTY_INPUTS)" ""
SCVerify_DISABLE_EMPTY_INPUTS                    := false
export SCVerify_DISABLE_EMPTY_INPUTS
endif
ifeq "$(SCVerify_IDLE_SYNCHRONIZATION_MODE)" ""
SCVerify_IDLE_SYNCHRONIZATION_MODE               := false
export SCVerify_IDLE_SYNCHRONIZATION_MODE
endif
ifeq "$(SCVerify_MISMATCHED_OUTPUTS_ONLY)" ""
SCVerify_MISMATCHED_OUTPUTS_ONLY                 := true
export SCVerify_MISMATCHED_OUTPUTS_ONLY
endif
ifeq "$(SCVerify_WAVE_PROBES)" ""
SCVerify_WAVE_PROBES                             := false
export SCVerify_WAVE_PROBES
endif
ifeq "$(SCVerify_OPTIMIZE_WRAPPERS)" ""
SCVerify_OPTIMIZE_WRAPPERS                       := false
export SCVerify_OPTIMIZE_WRAPPERS
endif
ifeq "$(SCVerify_GENERATE_STAGES)" ""
SCVerify_GENERATE_STAGES                         := schedule extract switching power
export SCVerify_GENERATE_STAGES
endif
ifeq "$(SCVerify_USE_CCS_BLOCK)" ""
SCVerify_USE_CCS_BLOCK                           := true
export SCVerify_USE_CCS_BLOCK
endif
ifeq "$(SCVerify_AUTOWAIT)" ""
SCVerify_AUTOWAIT                                := 0
export SCVerify_AUTOWAIT
endif
ifeq "$(SCVerify_ENABLE_STALL_TOGGLE)" ""
SCVerify_ENABLE_STALL_TOGGLE                     := false
export SCVerify_ENABLE_STALL_TOGGLE
endif
ifeq "$(SCVerify_ENABLE_RESET_TOGGLE)" ""
SCVerify_ENABLE_RESET_TOGGLE                     := false
export SCVerify_ENABLE_RESET_TOGGLE
endif
ifeq "$(SCVerify_USE_RESOLVED_TYPES)" ""
SCVerify_USE_RESOLVED_TYPES                      := false
export SCVerify_USE_RESOLVED_TYPES
endif
ifeq "$(SCVerify_GEN_SVA_BIND)" ""
SCVerify_GEN_SVA_BIND                            := false
export SCVerify_GEN_SVA_BIND
endif
ifeq "$(SCVerify_USE_VISTA)" ""
SCVerify_USE_VISTA                               := false
export SCVerify_USE_VISTA
endif
ifeq "$(SCVerify_ENABLE_REPLAY_VERIFICATION)" ""
SCVerify_ENABLE_REPLAY_VERIFICATION              := false
export SCVerify_ENABLE_REPLAY_VERIFICATION
endif
ifeq "$(SCVerify_ENABLE_CPP_SCVERIFY_TOP)" ""
SCVerify_ENABLE_CPP_SCVERIFY_TOP                 := true
export SCVerify_ENABLE_CPP_SCVERIFY_TOP
endif
ifeq "$(SCVerify_KEEP_UNUSED_TRANSACTION_CTRLS)" ""
SCVerify_KEEP_UNUSED_TRANSACTION_CTRLS           := true
export SCVerify_KEEP_UNUSED_TRANSACTION_CTRLS
endif
ifeq "$(SCVerify_USE_MSIM)" ""
SCVerify_USE_MSIM                                := true
export SCVerify_USE_MSIM
endif
ifeq "$(SCVerify_MSIM_DEBUG)" ""
SCVerify_MSIM_DEBUG                              := false
export SCVerify_MSIM_DEBUG
endif
ifeq "$(OasysRTL_SynthesisFlowType)" ""
OasysRTL_SynthesisFlowType                       := asic
export OasysRTL_SynthesisFlowType
endif
ifeq "$(OasysRTL_FOLDERNAME)" ""
OasysRTL_FOLDERNAME                              := Oasys-RTL
export OasysRTL_FOLDERNAME
endif
ifeq "$(OasysRTL_Path)" ""
OasysRTL_Path                                    := $(OASYS_HOME)/bin
export OasysRTL_Path
endif
ifeq "$(OasysRTL_ShellExe)" ""
OasysRTL_ShellExe                                := oasys
export OasysRTL_ShellExe
endif
ifeq "$(OasysRTL_Flags)" ""
OasysRTL_Flags                                   := 
export OasysRTL_Flags
endif
ifeq "$(OasysRTL_LicenseServer)" ""
OasysRTL_LicenseServer                           := 
export OasysRTL_LicenseServer
endif
ifeq "$(OasysRTL_OutNetlistName)" ""
OasysRTL_OutNetlistName                          := gate.or
export OasysRTL_OutNetlistName
endif
ifeq "$(OasysRTL_OutNetlistFormat)" ""
OasysRTL_OutNetlistFormat                        := verilog
export OasysRTL_OutNetlistFormat
endif
ifeq "$(OasysRTL_TimingReportingMode)" ""
OasysRTL_TimingReportingMode                     := base
export OasysRTL_TimingReportingMode
endif
ifeq "$(OasysRTL_ImportantBits)" ""
OasysRTL_ImportantBits                           := 
export OasysRTL_ImportantBits
endif
ifeq "$(OasysRTL_GenerateGateSdc)" ""
OasysRTL_GenerateGateSdc                         := true
export OasysRTL_GenerateGateSdc
endif
ifeq "$(OasysRTL_ReportMapping)" ""
OasysRTL_ReportMapping                           := true
export OasysRTL_ReportMapping
endif
ifeq "$(OasysRTL_MaxLoopIterations)" ""
OasysRTL_MaxLoopIterations                       := 10000
export OasysRTL_MaxLoopIterations
endif
ifeq "$(OasysRTL_EnableClockGating)" ""
OasysRTL_EnableClockGating                       := false
export OasysRTL_EnableClockGating
endif
ifeq "$(OasysRTL_EnableRetiming)" ""
OasysRTL_EnableRetiming                          := true
export OasysRTL_EnableRetiming
endif
ifeq "$(OasysRTL_ClockGatingMinWidth)" ""
OasysRTL_ClockGatingMinWidth                     := 4
export OasysRTL_ClockGatingMinWidth
endif
ifeq "$(OasysRTL_MultiStageClockGating)" ""
OasysRTL_MultiStageClockGating                   := false
export OasysRTL_MultiStageClockGating
endif
ifeq "$(OasysRTL_EnablePhysicalView)" ""
OasysRTL_EnablePhysicalView                      := false
export OasysRTL_EnablePhysicalView
endif
ifeq "$(OasysRTL_EnableCapReporting)" ""
OasysRTL_EnableCapReporting                      := true
export OasysRTL_EnableCapReporting
endif
ifeq "$(OasysRTL_CustomScriptDirPath)" ""
OasysRTL_CustomScriptDirPath                     := 
export OasysRTL_CustomScriptDirPath
endif
ifeq "$(OasysRTL_ChipUtil)" ""
OasysRTL_ChipUtil                                := 60
export OasysRTL_ChipUtil
endif
ifeq "$(OasysRTL_AspectRatio)" ""
OasysRTL_AspectRatio                             := 1.0
export OasysRTL_AspectRatio
endif
ifeq "$(OasysRTL_AreaEffort)" ""
OasysRTL_AreaEffort                              := 1
export OasysRTL_AreaEffort
endif
ifeq "$(OasysRTL_TimingEffort)" ""
OasysRTL_TimingEffort                            := 1
export OasysRTL_TimingEffort
endif
ifeq "$(OasysRTL_OasysCommMode)" ""
OasysRTL_OasysCommMode                           := Script
export OasysRTL_OasysCommMode
endif
ifeq "$(OasysRTL_CharacterizationEffort)" ""
OasysRTL_CharacterizationEffort                  := 0
export OasysRTL_CharacterizationEffort
endif
ifeq "$(OasysRTL_AreaOptParallelism)" ""
OasysRTL_AreaOptParallelism                      := 1
export OasysRTL_AreaOptParallelism
endif
ifeq "$(LINK_LIBPATHS)" ""
LINK_LIBPATHS                                    := 
export LINK_LIBPATHS
endif
ifeq "$(LINK_LIBNAMES)" ""
LINK_LIBNAMES                                    := 
export LINK_LIBNAMES
endif
ifeq "$(MODEL_TECH)" ""
MODEL_TECH                                       := /mnt/d/Ubuntu/Questa/questasim/bin
export MODEL_TECH
endif
ifeq "$(INCL_DIRS)" ""
INCL_DIRS                                        := 
export INCL_DIRS
endif
