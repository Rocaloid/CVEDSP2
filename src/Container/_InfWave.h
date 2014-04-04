#define _TBase _C(CDSP2_Wave, _, _T1)

RClass(_RTClassName)
{
    RInherit(_TBase);
    
    int APosition;  //Absolute Position
    int VPosition;  //Virtual Position
    int SPosition;  //Submitted Position
};

RTMethod(void, CDSP2_InfWave, CtorSize, int Size);
RTMethod(void, CDSP2_InfWave, Resize, int Size);

RTMethod(int, CDSP2_InfWave, Relocate, int VPosition);
RTMethod(int, CDSP2_InfWave, Submit, int VPosition);

RTMethod(int, CDSP2_InfWave, Dump, _T1* Dest);
RTMethod(int, CDSP2_InfWave, Read, _T1* Dest, int LVPosition, int Size);
RTMethod(int, CDSP2_InfWave, Write, _T1* Sorc, int LVPosition, int Size);

