// bin: xb
// va: 0x002CCCB0
// what: Updates an Adler-32 checksum with a block of bytes (zlib adler32), used to check compressed data.
// tool: Claude Opus 5.5

// zlib 1.2.1's adler32.c. Types and macros as zconf.h / zlib.h / adler32.c declare them.
// RULE-EXCEPTION: R32, the body keeps zlib's published layout so it can be compared with the library.
typedef unsigned char Bytef;
typedef unsigned int uInt;
typedef unsigned long uLong;

#define Z_NULL 0
#define ZEXPORT

#define BASE 65521UL    /* largest prime smaller than 65536 */
#define NMAX 5552
/* NMAX is the largest n such that 255n(n+1)/2 + (n+1)(BASE-1) <= 2^32-1 */

#define DO1(buf,i)  {s1 += buf[i]; s2 += s1;}
#define DO2(buf,i)  DO1(buf,i); DO1(buf,i+1);
#define DO4(buf,i)  DO2(buf,i); DO2(buf,i+2);
#define DO8(buf,i)  DO4(buf,i); DO4(buf,i+4);
#define DO16(buf)   DO8(buf,0); DO8(buf,8);

#define MOD(a) a %= BASE

extern "C" uLong ZEXPORT adler32(uLong adler, const Bytef *buf, uInt len)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;
    int k;

    if (buf == Z_NULL) return 1L;

    while (len > 0) {
        k = len < NMAX ? (int)len : NMAX;
        len -= k;
        while (k >= 16) {
            DO16(buf);
            buf += 16;
            k -= 16;
        }
        if (k != 0) do {
            s1 += *buf++;
            s2 += s1;
        } while (--k);
        MOD(s1);
        MOD(s2);
    }
    return (s2 << 16) | s1;
}
