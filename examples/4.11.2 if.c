#if !defined(HDR)
#define HDR
/* here is the content of hdr.h */
#endif

#if SYSTEM == SYSV
#define HDR "sysv.h"
#elif SYSTEM == BSD
#define HDR "bsd.h"
#elif SYSTEM == MSDOS
#define HDR "msdos.h"
#else
#define HDR "default.h"
#endif
#include HDR

#ifndef HDR
#define HDR
/* here is the content of hdr.h */
#endif
