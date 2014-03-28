#include "Setting.h"
#include <RFNL.h>

CDSP2_CPUArch _CDSP2_Arch = CDSP2_Arch_Gnrc;

int CDSP2_SetArch(CDSP2_CPUArch Sorc)
{
    _CDSP2_Arch = Sorc;
    switch(Sorc)
    {
        case CDSP2_Arch_SSE:
            break;
        case CDSP2_Arch_AVX:
            break;
        default:
            #undef  __Arch
            #define __Arch Gnrc
            #include "RFNLInterface/_DFT_SetArch.h"
            #include "RFNLInterface/_Vec_SetArch.h"
            #include "RFNLInterface/_FWindow_SetArch.h"
            #include "RFNLInterface/_Interp_SetArch.h"
            break;
    }
    return 1;
}

