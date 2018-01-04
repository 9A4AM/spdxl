/*
 * dxlAPRS toolchain
 *
 * Copyright (C) Christian Rabler <oe5dxl@oevsv.at>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#define X2C_int32
#define X2C_index32
#ifndef osi_H_
#include "osi.h"
#endif
#define osi_C_
#include <osic.h>
#ifndef mlib_H_
#include "mlib.h"
#endif
#ifndef tcp_H_
#include "tcp.h"
#endif
#ifndef udp_H_
#include "udp.h"
#endif

/* os interface linux/win32 */

static void h(uint32_t n)
{
   char tmp;
   if (n<10UL) osi_WrStr((char *)(tmp = (char)(n+48UL),&tmp), 1u/1u);
   else osi_WrStr((char *)(tmp = (char)(n+55UL),&tmp), 1u/1u);
} /* end h() */


extern void osi_WrHex(uint32_t n, uint32_t f)
{
   h(n/16UL&15UL);
   h(n&15UL);
   while (f>=3UL) {
      osi_WrStr(" ", 2ul);
      --f;
   }
} /* end WrHex() */


extern int32_t osi_realint(float x)
{
   if (x>=2.E+9f) return 2000000000L;
   if (x<=(-2.E+9f)) return -2000000000L;
   return (int32_t)X2C_TRUNCI(x,X2C_min_longint,X2C_max_longint);
} /* end realint() */


extern uint32_t osi_realcard(float x)
{
   if (x>=4.E+9f) return 0x0EE6B2800UL;
   if (x<=0.0f) return 0UL;
   return (uint32_t)X2C_TRUNCC(x,0UL,X2C_max_longcard);
} /* end realcard() */


extern int32_t osi_OpenAppendLong(char fn[], uint32_t fn_len)
{
   return osic_OpenAppendLong(fn, fn_len);
} /* end OpenAppendLong() */


extern int32_t osi_OpenAppend(char fn[], uint32_t fn_len)
{
   return osic_OpenAppend(fn, fn_len);
} /* end OpenAppend() */


extern int32_t osi_OpenWrite(char fn[], uint32_t fn_len)
{
   return osic_OpenWrite(fn, fn_len);
} /* end OpenWrite() */


extern int32_t osi_OpenReadLong(char fn[], uint32_t fn_len)
{
   return osic_OpenReadLong(fn, fn_len);
} /* end OpenReadLong() */


extern int32_t osi_OpenRead(char fn[], uint32_t fn_len)
{
   return osic_OpenRead(fn, fn_len);
} /* end OpenRead() */


extern int32_t osi_OpenRW(char fn[], uint32_t fn_len)
{
   return osic_OpenRW(fn, fn_len);
} /* end OpenRW() */


extern int32_t osi_OpenNONBLOCK(char fn[], uint32_t fn_len)
{
   return osic_OpenNONBLOCK(fn, fn_len);
} /* end OpenNONBLOCK() */


extern void osi_NextArg(char s[], uint32_t s_len)
{
   osic_NextArg(s, s_len);
} /* end NextArg() */


extern int32_t osi_RdBin(int32_t fd, char buf[], uint32_t buf_len,
                uint32_t size)
{
   return osic_RdBin(fd, buf, buf_len, size);
} /* end RdBin() */


extern void osi_WrBin(int32_t fd, char buf[], uint32_t buf_len,
                uint32_t size)
{
   osic_WrBin(fd, buf, buf_len, size);
} /* end WrBin() */


extern void osi_Rename(char fname[], uint32_t fname_len,
                char newname[], uint32_t newname_len)
{
   osic_Rename(fname, fname_len, newname, newname_len);
} /* end Rename() */


extern void osi_Werr(char text[], uint32_t text_len)
{
   osic_WerrStr(text, text_len);
} /* end Werr() */


extern void osi_WerrLn(char text[], uint32_t text_len)
{
   osic_WerrStrLn(text, text_len);
} /* end WerrLn() */


extern void osi_WrStrLn(char s[], uint32_t s_len)
{
   osic_WrStrLn(s, s_len);
} /* end WrStrLn() */


extern void osi_WrStr(char s[], uint32_t s_len)
{
   osic_WrStr(s, s_len);
} /* end WrStr() */


extern void osi_Erase(char fn[], uint32_t fn_len, char * done)
{
   osic_Remove(fn, fn_len, done);
} /* end Erase() */


extern char osi_Exists(char fn[], uint32_t fn_len)
{
   return osic_Exists(fn, fn_len);
} /* end Exists() */


extern int32_t osi_getptsname(int32_t fd, char * s,
                uint32_t size)
{
   return osic_getptsname(fd, s, size);
} /* end getptsname() */

typedef char * pSTR;


extern int32_t osi_symblink(char * fname, char * newname)
{
   return osic_symblink((pSTR)fname, (pSTR)newname);
} /* end symblink() */


extern void osi_BEGIN(void)
{
   static int osi_init = 0;
   if (osi_init) return;
   osi_init = 1;
}

