#include <RFNL.h>

#define _CDSP2_Define_FP_FD(Type, Name) \
    _C(Type, _, Float)  _C(Name, _, Float ); \
    _C(Type, _, Double) _C(Name, _, Double)

typedef void (*_CDSP2_FP_DFT2P_Float) (float* , float* , int);
typedef void (*_CDSP2_FP_DFT2P_Double)(double*, double*, int);

typedef void (*_CDSP2_FP_DFT3P_Float) (float* , float* , float* , int);
typedef void (*_CDSP2_FP_DFT3P_Double)(double*, double*, double*, int);

typedef void (*_CDSP2_FP_DFT4P_Float) (float* , float* , float* , float* , int);
typedef void (*_CDSP2_FP_DFT4P_Double)(double*, double*, double*, double*, int);

_CDSP2_Define_FP_FD(_CDSP2_FP_DFT3P, CDSP2_RFFT);
_CDSP2_Define_FP_FD(_CDSP2_FP_DFT4P, CDSP2_CFFT);

_CDSP2_Define_FP_FD(_CDSP2_FP_DFT3P, CDSP2_IRFFT);
_CDSP2_Define_FP_FD(_CDSP2_FP_DFT4P, CDSP2_ICFFT);

_CDSP2_Define_FP_FD(_CDSP2_FP_DFT2P, CDSP2_FFTReflect);

