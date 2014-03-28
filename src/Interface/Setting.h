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

CDSP2_CPUArch _CDSP2_Arch;

int CDSP2_SetArch(CDSP2_CPUArch Sorc);

#endif

