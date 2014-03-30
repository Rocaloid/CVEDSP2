RClass(_RTClassName)
{
    RInherit(RObject);
    
    _T1* Data;
    int  Size;
};

RTMethod(void, CDSP2_Wave, CtorSize, int Size);
RTMethod(void, CDSP2_Wave, Resize, int Size);

RTMethod(void, CDSP2_Wave, Read, _T1* Dest, int LBound, int Size);
RTMethod(void, CDSP2_Wave, Write, _T1* Sorc, int LBound, int Size);

