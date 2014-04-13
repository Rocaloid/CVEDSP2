#include "Interface/Setting.h"
#include "Container/InfWave.h"
#include "Container/Spectrum.h"
#include <RFNL.h>

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    /*
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
    CDSP2_Wave_Double_Dtor(& twave);*/
    
    
    int i, l;
    CDSP2_InfWave_Double twave;
    CDSP2_InfWave_Double_CtorSize(& twave, 10000);
    CDSP2_InfWave_Double_Relocate(& twave, 15000);
    
    Double* temp = RAlloc_Double(10000);
    Double* temp2 = RAlloc_Double(6000);
    Double* wind = RAlloc_Double(3000);
    CDSP2_VSet_Double(wind, 1, 3000);
    CDSP2_Hanning_Double(wind, wind, 3000);
    CDSP2_IWave_Double_SetWindow(& twave, wind, 2048);
    
    for(i = 0; i < 3000; i ++)
        temp[i] = sin(0.2f * i) + 1.0f;

    CDSP2_IWave_Double_Add(& twave, temp, 15500, 3000);
    CDSP2_InfWave_Double_Submit(& twave, 18500);
    CDSP2_IWave_Double_WAdd(& twave, temp, 16500);
    CDSP2_IWave_Double_WAdd(& twave, temp, 17000);
    //CDSP2_InfWave_Double_Read(& twave, temp, 15000, 3000);
    //l = CDSP2_InfWave_Double_Dump(& twave, temp2);
    //CDSP2_VSet_Double(temp2, 0, 6000);
    
    CDSP2_IWave_Double_WAdd(& twave, temp, 19000);
    CDSP2_InfWave_Double_Submit(& twave, 20500);
    
    
    CDSP2_Spectrum_Double spec;
    CDSP2_Spectrum_Double_CtorSize(& spec, 2048);
    spec.MagnType = CDSP2_LinearMagn;
    spec.HalfSymm = 0;
    //float temp[2048];
    //int i;
    //for(i = 0; i < 2048; i ++)
    //    temp[i] = sin(i * 0.1) + sin(i * 0.2);
    CDSP2_Spectrum_Double_FromWave(& spec, & twave, 17000);
    CDSP2_Spectrum_Double_ToWaveA(& spec, & twave, 22000);
    CDSP2_InfWave_Double_Submit(& twave, 25000);
    
    l = CDSP2_InfWave_Double_Dump(& twave, temp);
    for(i = 0; i < 10000; i ++)
        printf("%f\n", temp[i]);
/*
    double Real[2048];
    double Imag[2048];
    CDSP2_InfWave_Double_Read(& twave, temp2, 17000, 2048);
    CDSP2_RFFT_Double(Real, Imag, temp2, 11);
    CDSP2_IRFFT_Double(temp, Real, Imag, 11);
*/
    RFree(temp);
    RFree(temp2);
    RFree(wind);
    CDSP2_InfWave_Double_Dtor(& twave);
    RDelete(& spec);
    return 0;
}

