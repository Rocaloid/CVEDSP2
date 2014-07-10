#include "List_Int.h"
#include <RFNL.h>

#define First CDSP2_List_Int* This

RCtor(CDSP2_List_Int)
{
    Array_Ctor(int, This -> Frames);
    RInit(CDSP2_List_Int);
}

RDtor(CDSP2_List_Int)
{
    Array_Dtor(int, This -> Frames);
}

void CDSP2_List_Int_CtorSize(First, int Size)
{
    Array_Ctor(int, This -> Frames);
    Array_Resize(int, This -> Frames, Size);
    RInit(CDSP2_List_Int);
}

void CDSP2_List_Int_Resize(First, int Size)
{
    Array_Resize(int, This -> Frames, Size);
}

void CDSP2_List_Int_From(First, CDSP2_List_Int* Sorc)
{
    int Size = Sorc -> Frames_Index + 1;
    Array_Resize(int, This -> Frames, Size);
    This -> Frames_Index = Sorc -> Frames_Index;
    //TODO: CDSP2_VCopy_Int interface
    RFNL_VCopy_Gnrc_Int(This -> Frames, Sorc -> Frames, Size);
}

void CDSP2_List_Int_Clear(First)
{
    Array_Resize(int, This -> Frames, 0);
}

int  CDSP2_List_Int_Fetch(First, int Index)
{
    return This -> Frames[Index];
}

int  CDSP2_List_Int_IndexBefore(First, int Position)
{
    int i;
    if(This -> Frames_Index < 0) return -1;
    if(Position < This -> Frames[0]) return -1;
    Array_IncFind(i, int, This -> Frames, Position);
    return i - 1;
}

int  CDSP2_List_Int_IndexAfter(First, int Position)
{
    int i;
    if(This -> Frames_Index < 0) return 0;
    if(Position < This -> Frames[0]) return 0;
    Array_IncFind(i, int, This -> Frames, Position);
    return i;
}

int  CDSP2_List_Int_Extract(First, int Index)
{
    int Ret = This -> Frames[Index];
    Array_Remove(int, This -> Frames, Index);
    return Ret;
}

int  CDSP2_List_Int_ExtractBefore(First, int Position)
{
    return CDSP2_List_Int_Extract(This,
        CDSP2_List_Int_IndexBefore(This, Position));
}

int  CDSP2_List_Int_ExtractAfter(First, int Position)
{
    return CDSP2_List_Int_Extract(This,
        CDSP2_List_Int_IndexAfter(This, Position));
}

void CDSP2_List_Int_Remove(First, int Index)
{
    Array_Remove(int, This -> Frames, Index);
}

void CDSP2_List_Int_RemoveRange(First, int LIndex, int HIndex)
{
    Array_RemoveRange(int, This -> Frames, LIndex, HIndex);
}

void CDSP2_List_Int_RemoveRangeP(First, int LPosition, int HPosition)
{
    int LIndex = CDSP2_List_Int_IndexAfter(This, LPosition);
    int HIndex = CDSP2_List_Int_IndexBefore(This, HPosition);
    Array_RemoveRange(int, This -> Frames, LIndex, HIndex);
}
int  CDSP2_List_Int_Add(First, int Position)
{
    int i;
    Array_IncFind(i, int, This -> Frames, Position);
    Array_Insert(int, This -> Frames, i, Position);
    return i;
}

