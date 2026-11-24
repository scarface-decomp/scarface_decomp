// bin: xb
// va: 0x000B2080
// what: If m_Field04 is non-null, calls sub_000BCAD0 and stores its negated float result at +0x08.
// tool: Gemini 4 Neon

class WheelCollisionCalculator
{
public:
    virtual void vfunc_00();
    float sub_000BCAD0();
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

void WheelCollisionCalculator::vfunc_00()
{
    if (m_Field04) {
        m_Field08 = -sub_000BCAD0();
    }
}
