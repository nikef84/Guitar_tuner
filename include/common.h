// Header file to select program to run

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <hal.h>
#include <ch.h>
#include <tests.h>

// List of all possible programs
#define MAIN_ROUTINE               0
#define STEP_ENGINE_TEST           1


// Selection of program to run
#define PROGRAM_ROUTINE STEP_ENGINE_TEST

#endif /* INCLUDE_COMMON_H_ */