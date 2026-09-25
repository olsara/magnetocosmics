// 9/25/2026, Olesya Sarajlic: This COMMON block is written during every field
//   evaluation (per-call scratch), so it is declared 'thread_local' to make
//   Geant4 multithreaded magnetic-field evaluation race-free. Each worker
//   thread gets its own copy. (bdip_ and igrfcc_ stay shared: they are set
//   once at configuration time and are only read during tracking.)
#include "f2c.h"
#include "f2c_symmap.h"

#ifdef __cplusplus
extern "C" {
#endif

thread_local union {
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


