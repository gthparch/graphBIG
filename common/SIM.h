#ifndef _SIM_H
#define _SIM_H
#include <stdint.h>
#include <iostream>

#ifdef QSIM
#include "qsim_magic.h"
#endif

extern "C" unsigned __attribute__ ((noinline)) SIM_BEGIN(bool i);
extern "C" unsigned __attribute__ ((noinline)) SIM_END(bool i); 

extern "C" void __attribute__ ((noinline)) SIM_LOCK(bool * i);
extern "C" void __attribute__ ((noinline)) SIM_UNLOCK(bool * i);
#endif
