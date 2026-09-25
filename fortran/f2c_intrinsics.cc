/* Minimal f2c runtime intrinsics used by the translated Tsyganenko/IGRF models.
   Reproduces the exact semantics of the corresponding libf2c routines
   (d_sign, pow_dd, pow_di) so no external libf2c is required. */
#include "f2c.h"
#undef abs
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

double d_sign(doublereal *a, doublereal *b)
{
    double x = (*a >= 0 ? *a : - *a);
    return( *b >= 0 ? x : -x);
}

double pow_dd(doublereal *ap, doublereal *bp)
{
    return(pow(*ap, *bp));
}

double pow_di(doublereal *ap, integer *bp)
{
    double pow, x;
    integer n;
    unsigned long u;
    pow = 1;
    x = *ap;
    n = *bp;
    if(n != 0){
        if(n < 0){ n = -n; x = 1/x; }
        for(u = n; ; ){
            if(u & 01) pow *= x;
            if(u >>= 1) x *= x;
            else break;
        }
    }
    return(pow);
}

#ifdef __cplusplus
}
#endif
