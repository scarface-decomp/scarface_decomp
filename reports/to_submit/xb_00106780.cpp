// bin: xb
// va: 0x00106780
// what: Computes the cosine of the float angle argument and writes it to the output pointer.
// tool: Gemini 4 Neon

#include <math.h>
#pragma intrinsic(cos)

void __cdecl sub_00106780(float* out, float angle)
{
    *out = (float)cos(angle);
}
