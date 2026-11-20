// bin: xb
// va: 0x00244170
// what: Scales a three-number vector so its length becomes one.
// tool: Claude Opus 5.5 (symcov hint: FcGenericVector<float>::Normalise)
// sub_00244170 (0x00244170, 59 bytes)

extern "C" double __cdecl sqrt(double);

class Class_00244170
{
public:
    void sub_00244170();

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

// Multiplies every component by one over the length.
void Class_00244170::sub_00244170()
{
    float length = (float)sqrt(m_Field00 * m_Field00 + m_Field04 * m_Field04 + m_Field08 * m_Field08);
    float scale = 1.0f / length;
    m_Field00 *= scale;
    m_Field04 *= scale;
    m_Field08 *= scale;
}
