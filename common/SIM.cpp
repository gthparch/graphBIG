#include "SIM.h"


unsigned __attribute__ ((noinline)) SIM_BEGIN(bool i)
{
#ifdef QSIM
    qsim_magic_enable();
    return 1;
#endif
    if (i==false) return 0;
    std::cout<<"sim begin\n";
    return 1;
}
unsigned __attribute__ ((noinline)) SIM_END(bool i)
{
#ifdef QSIM
    qsim_magic_disable();
    return 1;
#endif
    if (i==false) return 0;
    std::cout<<"sim end\n";
    return 1;
} 

void __attribute__ ((noinline)) SIM_LOCK(bool * i)
{
    while(__sync_lock_test_and_set(i, 1));
}

void __attribute__ ((noinline)) SIM_UNLOCK(bool * i)
{
    __sync_lock_release(i);
}

