// bin: xb
// va: 0x0003DBD0
// what: Returns the length of a three-number vector.
// tool: Claude Opus 5.5 (symcov hint: TVector::Length)
// sub_0003DBD0 (0x0003DBD0, 33 bytes)

extern "C" double __cdecl sqrt(double);

class Class_0003DBD0
{
public:
    float sub_0003DBD0() const;

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

// Square root of the sum of the squares of the three components.
float Class_0003DBD0::sub_0003DBD0() const
{
    return (float)sqrt(m_Field00 * m_Field00 + m_Field04 * m_Field04 + m_Field08 * m_Field08);
}
