#ifndef CDSP2_SETTING_H
#define CDSP2_SETTING_H

#include <RUtil2.h>

#include "RFNLInterface/Vec.h"
#include "RFNLInterface/DFT.h"
#include "RFNLInterface/FWindow.h"
#include "RFNLInterface/Interp.h"

typedef enum
{
    CDSP2_Arch_Gnrc = 0,
    CDSP2_Arch_SSE = 1,
    CDSP2_Arch_AVX = 2
} CDSP2_CPUArch;

#define CDSP2_Debug_Check 0

CDSP2_CPUArch _CDSP2_Arch;
int CDSP2_Debug_CheckFlag;

int CDSP2_SetArch(CDSP2_CPUArch Sorc);
void CDSP2_SetDebugOn(int Sorc);
void CDSP2_SetDebugOff(int Sorc);

#define CDSP2_If_Debug_Check(Arg) \
    if(CDSP2_Debug_CheckFlag) {Arg}

#endif

