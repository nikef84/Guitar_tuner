# C source files
PROJECT_CSRC 	= 	src/main.c \
					tests/blink_test.c \
					tests/stepper_motor_test.c \
					




# C++ source files
PROJECT_CPPSRC 	= 
# Directories to search headers in
PROJECT_INCDIR	= include \
				  tests \
                  include/stateDriver \
                  include/controllFunc\
 

# Additional libraries
PROJECT_LIBS	= -lm
# Compiler options
PROJECT_OPT     = -DCHPRINTF_USE_FLOAT=1 -specs=nano.specs -specs=nosys.specs

# Additional .mk files are included here
CSRC = $(ALLCSRC) \
       $(TESTSRC) \
       $(PROJECT_CSRC) \
       $(CHIBIOS)/os/various/evtimer.c