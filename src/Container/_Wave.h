RInterface_Define(void, _C(CDSP2_IWave_, _T1, _Resize), void*, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _SetWindow), void*, _T1*, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _Read), void*, _T1*, int, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _Write), void*, _T1*, int, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _Add), void*, _T1*, int, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _WRead), void*, _T1*, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _WWrite), void*, _T1*, int);
RInterface_Define(void, _C(CDSP2_IWave_, _T1, _WAdd), void*, _T1*, int);

RClass(_RTClassName)
{
    RInherit(RObject);
    
    _T1* Data;
    int  Size;
    
    _T1* Window;
    _T1* WinBuff;
    int  WinSize;
};

RTMethod(void, CDSP2_Wave, CtorSize, int Size);
RTMethod(void, CDSP2_Wave, Resize, int Size);

RTMethod(void, CDSP2_Wave, SetWindow, _T1* Sorc, int Size);

//Read
RTMethod(void, CDSP2_Wave, Read, _T1* Dest, int LBound, int Size);
//Overridding Write
RTMethod(void, CDSP2_Wave, Write, _T1* Sorc, int LBound, int Size);
//Additive Write
RTMethod(void, CDSP2_Wave, Add, _T1* Sorc, int LBound, int Size);
//Windowed Read
RTMethod(void, CDSP2_Wave, WRead, _T1* Dest, int LBound);
//Windowed Overidding Write
RTMethod(void, CDSP2_Wave, WWrite, _T1* Sorc, int LBound);
//Windowed Additive Write
RTMethod(void, CDSP2_Wave, WAdd, _T1* Sorc, int LBound);

