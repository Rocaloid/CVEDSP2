RClass(_RTClassName)
{
    RInherit(RObject);
    
    int Size;
    int NoPhase;
    int HalfSymm;
    int MagnType;
    _T1* Magn;
    _T1* Phse;
};

RTMethod(void, CDSP2_Spectrum, CtorSize, int Size);
RTMethod(void, CDSP2_Spectrum, Resize, int Size);

RTMethod(void, CDSP2_Spectrum, Copy, _C(CDSP2_Spectrum, _, _T1)* Dest);
RTMethod(void, CDSP2_Spectrum, MagnConv, int Type);

RTMethod(void, CDSP2_Spectrum, FromWave, void* Sorc, int Position);
RTMethod(void, CDSP2_Spectrum, FromWaveW, void* Sorc, int Position);
RTMethod(void, CDSP2_Spectrum, FromReal, _T1* Sorc);
RTMethod(void, CDSP2_Spectrum, FromRealW, _T1* Sorc, _T1* Window);
RTMethod(void, CDSP2_Spectrum, FromCplx, _T1* Real, _T1* Imag);

RTMethod(void, CDSP2_Spectrum, ToWave, void* Dest, int Position);
RTMethod(void, CDSP2_Spectrum, ToWaveA, void* Dest, int Position);
RTMethod(void, CDSP2_Spectrum, ToReal, _T1* Sorc);
RTMethod(void, CDSP2_Spectrum, ToRealA, _T1* Sorc);
RTMethod(void, CDSP2_Spectrum, ToCplx, _T1* Real, _T1* Imag);

