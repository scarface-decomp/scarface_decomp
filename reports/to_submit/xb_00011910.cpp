// bin: xb
// va: 0x00011910
// what: Returns the squared length of a three-number vector (x*x + y*y + z*z).
// tool: Claude Opus 5.5 (symcov hint: vector3::SquaredLength)
// sub_00011910 (0x00011910, 31 bytes)

class Class_00011910
{
public:
    float sub_00011910() const;

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

// Sum of the squares of the three components.
float Class_00011910::sub_00011910() const
{
    return m_Field00 * m_Field00 + m_Field04 * m_Field04 + m_Field08 * m_Field08;
}
