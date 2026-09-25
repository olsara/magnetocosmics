#include "f2c.h"
#include "f2c_symmap.h"

#ifdef __cplusplus
extern "C" {
#endif

union {
    struct {
	doublereal dxshift1, dxshift2, d__, deltady;
    } _1;
    struct {
	doublereal dxshift1, dxshift2, d0, deltady;
    } _2;
} tail_;

#ifdef __cplusplus
}
#endif

