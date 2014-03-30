#include "Interface/Setting.h"
#include "Container/Wave.h"

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    CDSP2_Wave_Double twave;
    CDSP2_Wave_Double_CtorSize(& twave, 1024);
    int i;
    for(i = 0; i < 1024; i ++)
        twave.Data[i] = i;
    
    Double* temp = RAlloc_Double(3000);
    for(i = 0; i < 3000; i ++)
        temp[i] = 0.2 * i;
    CDSP2_Wave_Double_Write(& twave, temp, - 500, 1000);
    CDSP2_Wave_Double_Read(& twave, temp, -1000, 3000);
    for(i = 0; i < 3000; i ++)
        printf("%f\n", temp[i]);
    RFree(temp);
    CDSP2_Wave_Double_Dtor(& twave);
    return 0;
}

