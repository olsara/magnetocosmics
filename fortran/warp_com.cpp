#include "f2c.h"
#include "f2c_symmap.h"

#ifdef __cplusplus
extern "C" {
#endif

union {
    struct {
	doublereal cpss, spss, dpsrr, rps, warp, d__, xs, zs, dxsx, dxsy, 
		dxsz, dzsx, dzsy, dzsz, dzetas, ddzetadx, ddzetady, ddzetadz, 
		zsww;
    } _1;
    struct {
	doublereal cpss, spss, dpsrr, xnext[3], xs, zswarped, dxsx, dxsy, 
		dxsz, dzsx, dzsywarped, dzsz, other[4], zs;
    } _2;
    struct {
	doublereal cpss, spss, dpsrr, xnext[3], xs, zs, dxsx, dxsy, dxsz, 
		other[3], dzetas, ddzetadx, ddzetady, ddzetadz, zsww;
    } _3;
    struct {
	doublereal first[3], rps, warp, d__, other[13];
    } _4;
} warp_;

#ifdef __cplusplus
}
#endif

