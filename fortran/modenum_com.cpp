// 9/25/2026: This COMMON block is written during every field
//   evaluation (per-call scratch), so it is declared 'thread_local' to make
//   Geant4 multithreaded magnetic-field evaluation race-free. Each worker
//   thread gets its own copy. (bdip_ and igrfcc_ stay shared: they are set
//   once at configuration time and are only read during tracking.)
#include "f2c.h"
#include "f2c_symmap.h"

#ifdef __cplusplus
extern "C" {
#endif

thread_local struct {
    integer m;
} modenum_;

#ifdef __cplusplus
}
#endif


