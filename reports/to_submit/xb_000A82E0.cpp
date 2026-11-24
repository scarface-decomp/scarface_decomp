// bin: xb
// va: 0x000A82E0
// what: Computes the cosine of the angle in degrees at +0x00 and stores it at +0x04.
// tool: Gemini 4 Neon

#include <math.h>
#pragma intrinsic(cos)

class Class_000A82E0
{
public:
    void sub_000A82E0();
    float m_AngleDeg; // +0x00
    float m_CosAngle; // +0x04
};

void Class_000A82E0::sub_000A82E0()
{
    m_CosAngle = (float)cos(m_AngleDeg * 0.017453292f);
}
